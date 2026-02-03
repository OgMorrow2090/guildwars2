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
 * @param aIdentifier - The keybind identifier
 * @param aIsRelease - true if key was released, false if pressed
 */
void ProcessKeybind(const char* aIdentifier, bool aIsRelease)
{
    // Only act on key press, not release
    if (aIsRelease)
    {
        return;
    }
    
    // === ACTION KEYBINDS ===
    if (strcmp(aIdentifier, KB_DEPOSIT_MATERIALS) == 0)
    {
        SimulateDepositMaterialsClick();
    }
    else if (strcmp(aIdentifier, KB_SORT_INVENTORY) == 0)
    {
        SimulateSortInventoryClick();
    }
    else if (strcmp(aIdentifier, KB_OPEN_CHEST) == 0)
    {
        SimulateOpenChestClick();
    }
    else if (strcmp(aIdentifier, KB_DEPOSIT_AND_SORT) == 0)
    {
        SimulateDepositAndSort();
    }
    // === CAPTURE KEYBINDS ===
    else if (strcmp(aIdentifier, KB_CAPTURE_DEPOSIT) == 0)
    {
        CaptureDepositPosition();
    }
    else if (strcmp(aIdentifier, KB_CAPTURE_SORT) == 0)
    {
        CaptureSortPosition();
    }
    else if (strcmp(aIdentifier, KB_CAPTURE_CHEST) == 0)
    {
        CaptureChestPosition();
    }
}
