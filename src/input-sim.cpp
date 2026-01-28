/**
 * input-sim.cpp
 * 
 * Input simulation functions for clicking inventory buttons.
 * Uses Nexus SendWndProcToGameOnly() to send mouse events directly to the game.
 * 
 * Author: OgMorrow2090
 * Repository: https://github.com/OgMorrow2090/guildwars2
 * 
 * NOTE: Button positions are currently hardcoded for 1920x1080 resolution
 * with default UI scale. Future versions will calculate positions dynamically
 * using MumbleLink UI scale data.
 */

#include "shared.h"

// =============================================================================
// Button Position Configuration
// =============================================================================
// 
// These positions are relative to the inventory window which appears in the
// bottom-right corner of the screen. Positions need adjustment for:
// - Different screen resolutions
// - Different UI scale settings (Small/Normal/Large/Larger)
// - Inventory window position if moved
//
// TODO: Calculate dynamically using MumbleLink UISize and screen resolution
// =============================================================================

// Hardcoded positions for 1920x1080 @ Normal UI scale
// These will need to be determined through in-game testing
namespace ButtonPositions
{
    // "Deposit All Materials" button (cog/gear icon in inventory)
    // Position relative to screen - NEEDS TESTING
    constexpr int DEPOSIT_X = 1800;  // Placeholder - needs actual position
    constexpr int DEPOSIT_Y = 900;   // Placeholder - needs actual position
    
    // "Compact" / Sort button in inventory
    // Position relative to screen - NEEDS TESTING
    constexpr int SORT_X = 1750;     // Placeholder - needs actual position
    constexpr int SORT_Y = 900;      // Placeholder - needs actual position
}

/**
 * SimulateClickAt - Send mouse click at screen coordinates
 * 
 * Uses Nexus API to send WM_LBUTTONDOWN/UP messages directly to the game,
 * bypassing any addon hooks. This ensures the click reaches the game UI.
 * 
 * @param x - Screen X coordinate
 * @param y - Screen Y coordinate
 */
void SimulateClickAt(int x, int y)
{
    if (GameWindow == nullptr)
    {
        APIDefs->Log(ELogLevel_WARNING, "InventoryHotkeys", "Game window not available");
        return;
    }
    
    // Pack coordinates into LPARAM (low word = x, high word = y)
    LPARAM lParam = MAKELPARAM(x, y);
    
    // Send mouse button down
    APIDefs->SendWndProcToGameOnly(
        GameWindow,
        WM_LBUTTONDOWN,
        MK_LBUTTON,  // wParam: indicates left button is down
        lParam
    );
    
    // Small delay could be added here if needed, but typically not required
    
    // Send mouse button up
    APIDefs->SendWndProcToGameOnly(
        GameWindow,
        WM_LBUTTONUP,
        0,           // wParam: no buttons down
        lParam
    );
    
    APIDefs->Log(ELogLevel_DEBUG, "InventoryHotkeys", "Simulated click at (%d, %d)", x, y);
}

/**
 * SimulateDepositMaterialsClick - Click the "Deposit All Materials" button
 * 
 * Sends a mouse click to the deposit materials button position.
 * Requires inventory to be open for the button to be visible.
 */
void SimulateDepositMaterialsClick()
{
    APIDefs->Log(ELogLevel_INFO, "InventoryHotkeys", "Clicking Deposit Materials button");
    SimulateClickAt(ButtonPositions::DEPOSIT_X, ButtonPositions::DEPOSIT_Y);
}

/**
 * SimulateSortInventoryClick - Click the "Compact/Sort" button
 * 
 * Sends a mouse click to the sort/compact button position.
 * Requires inventory to be open for the button to be visible.
 */
void SimulateSortInventoryClick()
{
    APIDefs->Log(ELogLevel_INFO, "InventoryHotkeys", "Clicking Sort Inventory button");
    SimulateClickAt(ButtonPositions::SORT_X, ButtonPositions::SORT_Y);
}
