/**
 * keybinds.cpp
 * 
 * Keybind registration and handler for Inventory Hotkeys addon.
 * Routes keybind events to appropriate input simulation functions.
 * 
 * Author: OgMorrow2090
 * Repository: https://github.com/OgMorrow2090/guildwars2
 */

#include "shared.h"
#include <cstring>

/**
 * ProcessKeybind - Keybind callback handler
 * 
 * Called by Nexus when a registered keybind is pressed or released.
 * 
 * @param aIdentifier - The keybind identifier (e.g., "KB_DEPOSIT_MATERIALS")
 * @param aIsRelease - true if key was released, false if pressed
 */
void ProcessKeybind(const char* aIdentifier, bool aIsRelease)
{
    // Only act on key press, not release
    if (aIsRelease)
    {
        return;
    }
    
    // Route to appropriate handler
    if (strcmp(aIdentifier, KB_DEPOSIT_MATERIALS) == 0)
    {
        APIDefs->Log(ELogLevel_DEBUG, "InventoryHotkeys", "Deposit Materials hotkey triggered");
        SimulateDepositMaterialsClick();
    }
    else if (strcmp(aIdentifier, KB_SORT_INVENTORY) == 0)
    {
        APIDefs->Log(ELogLevel_DEBUG, "InventoryHotkeys", "Sort Inventory hotkey triggered");
        SimulateSortInventoryClick();
    }
}
