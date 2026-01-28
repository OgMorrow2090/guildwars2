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
AddonAPI* APIDefs = nullptr;
AddonDefinition AddonDef{};
HWND GameWindow = nullptr;

// Forward declarations
void AddonLoad(AddonAPI* aApi);
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
extern "C" __declspec(dllexport) AddonDefinition* GetAddonDef()
{
    // Signature must be unique and negative for non-Raidcore addons
    AddonDef.Signature = -54321;
    AddonDef.APIVersion = NEXUS_API_VERSION;
    
    // Addon metadata
    AddonDef.Name = "Inventory Hotkeys";
    AddonDef.Version.Major = 0;
    AddonDef.Version.Minor = 1;
    AddonDef.Version.Build = 0;
    AddonDef.Version.Revision = 0;
    AddonDef.Author = "OgMorrow2090";
    AddonDef.Description = "Hotkeys for Deposit All Materials and Sort Inventory buttons.";
    
    // Callbacks
    AddonDef.Load = AddonLoad;
    AddonDef.Unload = AddonUnload;
    
    // Optional features
    AddonDef.Flags = EAddonFlags::None;
    
    // Auto-update from GitHub releases
    AddonDef.Provider = EUpdateProvider::GitHub;
    AddonDef.UpdateLink = "https://github.com/OgMorrow2090/guildwars2";
    
    return &AddonDef;
}

/**
 * AddonLoad - Called when addon is loaded by Nexus
 * 
 * Initialize addon state and register keybinds.
 */
void AddonLoad(AddonAPI* aApi)
{
    APIDefs = aApi;
    
    // Get game window handle for input simulation
    GameWindow = APIDefs->GameHandle;
    
    // Set up ImGui context (required for any ImGui rendering)
    ImGui::SetCurrentContext((ImGuiContext*)APIDefs->ImguiContext);
    ImGui::SetAllocatorFunctions(
        (void* (*)(size_t, void*))APIDefs->ImguiMalloc,
        (void(*)(void*, void*))APIDefs->ImguiFree
    );
    
    // Register keybinds with default keys
    // Users can customize these in Nexus Options (Ctrl+O)
    APIDefs->RegisterKeybindWithString(
        KB_DEPOSIT_MATERIALS, 
        ProcessKeybind, 
        "CTRL+D"
    );
    
    APIDefs->RegisterKeybindWithString(
        KB_SORT_INVENTORY, 
        ProcessKeybind, 
        "CTRL+SHIFT+S"
    );
    
    APIDefs->Log(ELogLevel_INFO, "InventoryHotkeys", "Addon loaded successfully!");
    APIDefs->Log(ELogLevel_INFO, "InventoryHotkeys", "Deposit Materials: Ctrl+D");
    APIDefs->Log(ELogLevel_INFO, "InventoryHotkeys", "Sort Inventory: Ctrl+Shift+S");
}

/**
 * AddonUnload - Called when addon is unloaded by Nexus
 * 
 * Clean up resources and deregister keybinds.
 */
void AddonUnload()
{
    // Deregister keybinds
    APIDefs->DeregisterKeybind(KB_DEPOSIT_MATERIALS);
    APIDefs->DeregisterKeybind(KB_SORT_INVENTORY);
    
    APIDefs->Log(ELogLevel_INFO, "InventoryHotkeys", "Addon unloaded.");
    
    // Clear global state
    APIDefs = nullptr;
    GameWindow = nullptr;
}
