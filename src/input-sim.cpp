/**
 * input-sim.cpp
 * 
 * Input simulation functions for clicking inventory buttons.
 * Uses Nexus SendWndProcToGameOnly() to send mouse events directly to the game.
 * 
 * Author: OgMorrow2090
 * Repository: https://github.com/OgMorrow2090/guildwars2
 * 
 * Capture positions:
 *   Ctrl+Shift+D = Deposit button
 *   Ctrl+Shift+C = Compact/Sort button
 *   Ctrl+Shift+B = Bouncy Chest
 * 
 * Actions:
 *   Alt+D = Deposit Materials (left-click)
 *   Alt+C = Compact/Sort (left-click)
 *   Alt+B = Open Bouncy Chest (right-click)
 */

#include "shared.h"
#include <cstdio>

// =============================================================================
// Helper: Find Game Window
// =============================================================================

static void EnsureGameWindow()
{
    if (GameWindow != nullptr) return;
    
    GameWindow = FindWindowA("ArenaNet_Dx_Window_Class", nullptr);
    if (GameWindow == nullptr)
        GameWindow = FindWindowA("ArenaNet_Gr_Window_Class", nullptr);
    if (GameWindow == nullptr)
        GameWindow = FindWindowA(nullptr, "Guild Wars 2");
    if (GameWindow == nullptr)
    {
        GameWindow = GetForegroundWindow();
        APIDefs->Log(LOGL_WARNING, "InventoryHotkeys", "Using foreground window");
    }
}

// =============================================================================
// Click Simulation
// =============================================================================

/**
 * SimulateClickAt - Send LEFT mouse click at coordinates
 */
void SimulateClickAt(int x, int y)
{
    EnsureGameWindow();
    if (GameWindow == nullptr)
    {
        APIDefs->Log(LOGL_WARNING, "InventoryHotkeys", "Game window not available");
        return;
    }
    
    LPARAM lParam = MAKELPARAM(x, y);
    
    APIDefs->WndProc_SendToGameOnly(GameWindow, WM_LBUTTONDOWN, MK_LBUTTON, lParam);
    APIDefs->WndProc_SendToGameOnly(GameWindow, WM_LBUTTONUP, 0, lParam);
}

/**
 * SimulateRightClickAt - Send RIGHT mouse click at coordinates
 */
void SimulateRightClickAt(int x, int y)
{
    EnsureGameWindow();
    if (GameWindow == nullptr)
    {
        APIDefs->Log(LOGL_WARNING, "InventoryHotkeys", "Game window not available");
        return;
    }
    
    LPARAM lParam = MAKELPARAM(x, y);
    
    APIDefs->WndProc_SendToGameOnly(GameWindow, WM_RBUTTONDOWN, MK_RBUTTON, lParam);
    APIDefs->WndProc_SendToGameOnly(GameWindow, WM_RBUTTONUP, 0, lParam);
}

// =============================================================================
// Action Functions
// =============================================================================

void SimulateDepositMaterialsClick()
{
    if (g_DepositX == 0 && g_DepositY == 0)
    {
        APIDefs->GUI_SendAlert("Deposit position not set! Use Ctrl+Shift+D to capture");
        return;
    }
    APIDefs->Log(LOGL_INFO, "InventoryHotkeys", "Clicking Deposit Materials");
    SimulateClickAt(g_DepositX, g_DepositY);
}

void SimulateSortInventoryClick()
{
    if (g_SortX == 0 && g_SortY == 0)
    {
        APIDefs->GUI_SendAlert("Sort position not set! Use Ctrl+Shift+C to capture");
        return;
    }
    APIDefs->Log(LOGL_INFO, "InventoryHotkeys", "Clicking Sort/Compact");
    SimulateClickAt(g_SortX, g_SortY);
}

void SimulateOpenChestClick()
{
    if (g_ChestX == 0 && g_ChestY == 0)
    {
        APIDefs->GUI_SendAlert("Chest position not set! Use Ctrl+Shift+B to capture");
        return;
    }
    APIDefs->Log(LOGL_INFO, "InventoryHotkeys", "Right-clicking Bouncy Chest");
    SimulateRightClickAt(g_ChestX, g_ChestY);
}

void SimulateDepositAndSort()
{
    APIDefs->Log(LOGL_INFO, "InventoryHotkeys", "Combo: Deposit + Sort");
    
    // First deposit
    if (g_DepositX != 0 || g_DepositY != 0)
    {
        SimulateClickAt(g_DepositX, g_DepositY);
    }
    
    // Small delay then sort
    Sleep(100);
    
    if (g_SortX != 0 || g_SortY != 0)
    {
        SimulateClickAt(g_SortX, g_SortY);
    }
}

// =============================================================================
// Position Capture Functions
// =============================================================================

static void CapturePosition(int& outX, int& outY, const char* name)
{
    EnsureGameWindow();
    
    POINT pt;
    if (GetCursorPos(&pt))
    {
        if (GameWindow != nullptr)
        {
            ScreenToClient(GameWindow, &pt);
        }
        
        outX = pt.x;
        outY = pt.y;
        
        char buffer[128];
        sprintf_s(buffer, "%s captured: (%d, %d) - Saved!", name, pt.x, pt.y);
        APIDefs->Log(LOGL_INFO, "InventoryHotkeys", buffer);
        APIDefs->GUI_SendAlert(buffer);
        
        // Auto-save after each capture
        SaveButtonPositions();
    }
    else
    {
        APIDefs->Log(LOGL_WARNING, "InventoryHotkeys", "Failed to get cursor position");
        APIDefs->GUI_SendAlert("Failed to capture position!");
    }
}

void CaptureDepositPosition()
{
    CapturePosition(g_DepositX, g_DepositY, "DEPOSIT");
}

void CaptureSortPosition()
{
    CapturePosition(g_SortX, g_SortY, "SORT/COMPACT");
}

void CaptureChestPosition()
{
    CapturePosition(g_ChestX, g_ChestY, "BOUNCY CHEST");
}
