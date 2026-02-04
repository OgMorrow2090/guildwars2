/**
 * entry.cpp
 * 
 * DLL entry point and Nexus addon definition for Inventory Hotkeys.
 * Exports GetAddonDef() which Nexus calls to register the addon.
 * 
 * Author: OgMorrow2090
 * Repository: https://github.com/OgMorrow2090/guildwars2
 */

#include "shared.h"
#include <cstring>

// Global state
AddonAPI_t* APIDefs = nullptr;
AddonDefinition_t AddonDef{};
HWND GameWindow = nullptr;

// Forward declarations
void AddonLoad(AddonAPI_t* aApi);
void AddonUnload();

/**
 * DLL Entry Point
 * Called by Windows when the DLL is loaded/unloaded.
 */
BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        DisableThreadLibraryCalls(hModule);
        break;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

/**
 * GetAddonDef - Required Nexus Export
 * 
 * Nexus calls this function to get addon metadata and callbacks.
 * Must be exported as a C function (no name mangling).
 */
extern "C" __declspec(dllexport) AddonDefinition_t* GetAddonDef()
{
    // Signature must be unique and negative for non-Raidcore addons
    AddonDef.Signature = -54321;
    AddonDef.APIVersion = NEXUS_API_VERSION;
    
    // Addon metadata
    AddonDef.Name = "Inventory Hotkeys";
    AddonDef.Version.Major = 1;
    AddonDef.Version.Minor = 2;
    AddonDef.Version.Build = 0;
    AddonDef.Version.Revision = 0;
    AddonDef.Author = "OgMorrow2090";
    AddonDef.Description = "Hotkeys for inventory actions with per-resolution config support.";
    
    // Callbacks
    AddonDef.Load = AddonLoad;
    AddonDef.Unload = AddonUnload;
    
    // Optional features
    AddonDef.Flags = AF_None;
    
    // Auto-update from GitHub releases
    AddonDef.Provider = UP_GitHub;
    AddonDef.UpdateLink = "https://github.com/OgMorrow2090/guildwars2";
    
    return &AddonDef;
}

/**
 * AddonLoad - Called when addon is loaded by Nexus
 * 
 * Initialize addon state and register keybinds.
 */
void AddonLoad(AddonAPI_t* aApi)
{
    APIDefs = aApi;
    
    // Set config path and load saved positions
    SetConfigPath(APIDefs->Paths_GetAddonDirectory("InventoryHotkeys"));
    LoadButtonPositions();
    
    // Get game window handle for input simulation
    // Try multiple window class names that GW2 might use
    GameWindow = FindWindowA("ArenaNet_Dx_Window_Class", nullptr);
    if (GameWindow == nullptr)
    {
        GameWindow = FindWindowA("ArenaNet_Gr_Window_Class", nullptr);
    }
    if (GameWindow == nullptr)
    {
        // Try finding by window title
        GameWindow = FindWindowA(nullptr, "Guild Wars 2");
    }
    if (GameWindow == nullptr)
    {
        // Last resort: get foreground window (will be set on first keybind press)
        APIDefs->Log(LOGL_WARNING, "InventoryHotkeys", "Game window not found at load - will try on keybind press");
    }
    else
    {
        APIDefs->Log(LOGL_INFO, "InventoryHotkeys", "Game window found successfully!");
    }
    
    // === ACTION KEYBINDS ===
    APIDefs->InputBinds_RegisterWithString(
        KB_DEPOSIT_MATERIALS, 
        ProcessKeybind, 
        "CTRL+D"
    );
    
    APIDefs->InputBinds_RegisterWithString(
        KB_SORT_INVENTORY, 
        ProcessKeybind, 
        "CTRL+C"
    );
    
    APIDefs->InputBinds_RegisterWithString(
        KB_OPEN_CHEST, 
        ProcessKeybind, 
        "CTRL+B"
    );
    
    APIDefs->InputBinds_RegisterWithString(
        KB_DEPOSIT_AND_SORT, 
        ProcessKeybind, 
        "CTRL+Q"
    );
    
    APIDefs->InputBinds_RegisterWithString(
        KB_EXIT_INSTANCE, 
        ProcessKeybind, 
        "CTRL+E"
    );
    
    // === GENERIC HOTKEYS (unassigned by default) ===
    APIDefs->InputBinds_RegisterWithString(
        KB_GENERIC_1, 
        ProcessKeybind, 
        "(null)"
    );
    
    APIDefs->InputBinds_RegisterWithString(
        KB_GENERIC_2, 
        ProcessKeybind, 
        "(null)"
    );
    
    APIDefs->InputBinds_RegisterWithString(
        KB_GENERIC_3, 
        ProcessKeybind, 
        "(null)"
    );
    
    APIDefs->InputBinds_RegisterWithString(
        KB_GENERIC_4, 
        ProcessKeybind, 
        "(null)"
    );
    
    APIDefs->InputBinds_RegisterWithString(
        KB_GENERIC_5, 
        ProcessKeybind, 
        "(null)"
    );
    
    // === CAPTURE KEYBINDS ===
    APIDefs->InputBinds_RegisterWithString(
        KB_CAPTURE_DEPOSIT, 
        ProcessKeybind, 
        "CTRL+SHIFT+D"
    );
    
    APIDefs->InputBinds_RegisterWithString(
        KB_CAPTURE_SORT, 
        ProcessKeybind, 
        "CTRL+SHIFT+C"
    );
    
    APIDefs->InputBinds_RegisterWithString(
        KB_CAPTURE_CHEST, 
        ProcessKeybind, 
        "CTRL+SHIFT+B"
    );
    
    APIDefs->InputBinds_RegisterWithString(
        KB_CAPTURE_EXIT_INSTANCE, 
        ProcessKeybind, 
        "CTRL+SHIFT+E"
    );
    
    APIDefs->InputBinds_RegisterWithString(
        KB_CAPTURE_GENERIC_1, 
        ProcessKeybind, 
        "CTRL+SHIFT+1"
    );
    
    APIDefs->InputBinds_RegisterWithString(
        KB_CAPTURE_GENERIC_2, 
        ProcessKeybind, 
        "CTRL+SHIFT+2"
    );
    
    APIDefs->InputBinds_RegisterWithString(
        KB_CAPTURE_GENERIC_3, 
        ProcessKeybind, 
        "CTRL+SHIFT+3"
    );
    
    APIDefs->InputBinds_RegisterWithString(
        KB_CAPTURE_GENERIC_4, 
        ProcessKeybind, 
        "CTRL+SHIFT+4"
    );
    
    APIDefs->InputBinds_RegisterWithString(
        KB_CAPTURE_GENERIC_5, 
        ProcessKeybind, 
        "CTRL+SHIFT+5"
    );
    
    APIDefs->Log(LOGL_INFO, "InventoryHotkeys", "Addon loaded!");
    APIDefs->Log(LOGL_INFO, "InventoryHotkeys", "Actions: Alt+D (Deposit), Alt+C (Compact), Alt+B (Chest)");
    APIDefs->Log(LOGL_INFO, "InventoryHotkeys", "Capture: Ctrl+Shift+D/C/B to set positions");
}

/**
 * AddonUnload - Called when addon is unloaded by Nexus
 * 
 * Clean up resources and deregister keybinds.
 */
void AddonUnload()
{
    // Deregister action keybinds
    APIDefs->InputBinds_Deregister(KB_DEPOSIT_MATERIALS);
    APIDefs->InputBinds_Deregister(KB_SORT_INVENTORY);
    APIDefs->InputBinds_Deregister(KB_OPEN_CHEST);
    APIDefs->InputBinds_Deregister(KB_DEPOSIT_AND_SORT);
    APIDefs->InputBinds_Deregister(KB_EXIT_INSTANCE);
    
    // Deregister generic keybinds
    APIDefs->InputBinds_Deregister(KB_GENERIC_1);
    APIDefs->InputBinds_Deregister(KB_GENERIC_2);
    APIDefs->InputBinds_Deregister(KB_GENERIC_3);
    APIDefs->InputBinds_Deregister(KB_GENERIC_4);
    APIDefs->InputBinds_Deregister(KB_GENERIC_5);
    
    // Deregister capture keybinds
    APIDefs->InputBinds_Deregister(KB_CAPTURE_DEPOSIT);
    APIDefs->InputBinds_Deregister(KB_CAPTURE_SORT);
    APIDefs->InputBinds_Deregister(KB_CAPTURE_CHEST);
    APIDefs->InputBinds_Deregister(KB_CAPTURE_EXIT_INSTANCE);
    APIDefs->InputBinds_Deregister(KB_CAPTURE_GENERIC_1);
    APIDefs->InputBinds_Deregister(KB_CAPTURE_GENERIC_2);
    APIDefs->InputBinds_Deregister(KB_CAPTURE_GENERIC_3);
    APIDefs->InputBinds_Deregister(KB_CAPTURE_GENERIC_4);
    APIDefs->InputBinds_Deregister(KB_CAPTURE_GENERIC_5);
    
    APIDefs->Log(LOGL_INFO, "InventoryHotkeys", "Addon unloaded.");
    
    // Clear global state
    APIDefs = nullptr;
    GameWindow = nullptr;
}
