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
    
    // Check if resolution changed and load appropriate config
    CheckResolutionChange();
    
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
    else if (strcmp(aIdentifier, KB_EXIT_INSTANCE) == 0)
    {
        SimulateExitInstanceClick();
    }
    else if (strcmp(aIdentifier, KB_YES_DIALOG) == 0)
    {
        SimulateYesDialogClick();
    }
    else if (strcmp(aIdentifier, KB_MYSTIC_FORGE) == 0)
    {
        SimulateMysticForgeClick();
    }
    else if (strcmp(aIdentifier, KB_MYSTIC_REFILL) == 0)
    {
        SimulateMysticRefillClick();
    }
    else if (strcmp(aIdentifier, KB_MYSTIC_FORGE_COMBO) == 0)
    {
        SimulateMysticForgeCombo();
    }
    else if (strcmp(aIdentifier, KB_VENDOR) == 0)
    {
        SimulateVendorClick();
    }
    else if (strcmp(aIdentifier, KB_SELL_JUNK) == 0)
    {
        SimulateSellJunkClick();
    }
    // === GENERIC HOTKEYS ===
    else if (strcmp(aIdentifier, KB_GENERIC_1) == 0)
    {
        SimulateGenericClick(1);
    }
    else if (strcmp(aIdentifier, KB_GENERIC_2) == 0)
    {
        SimulateGenericClick(2);
    }
    else if (strcmp(aIdentifier, KB_GENERIC_3) == 0)
    {
        SimulateGenericClick(3);
    }
    else if (strcmp(aIdentifier, KB_GENERIC_4) == 0)
    {
        SimulateGenericClick(4);
    }
    else if (strcmp(aIdentifier, KB_GENERIC_5) == 0)
    {
        SimulateGenericClick(5);
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
    else if (strcmp(aIdentifier, KB_CAPTURE_EXIT_INSTANCE) == 0)
    {
        CaptureExitInstancePosition();
    }
    else if (strcmp(aIdentifier, KB_CAPTURE_GENERIC_1) == 0)
    {
        CaptureGenericPosition(1);
    }
    else if (strcmp(aIdentifier, KB_CAPTURE_GENERIC_2) == 0)
    {
        CaptureGenericPosition(2);
    }
    else if (strcmp(aIdentifier, KB_CAPTURE_GENERIC_3) == 0)
    {
        CaptureGenericPosition(3);
    }
    else if (strcmp(aIdentifier, KB_CAPTURE_GENERIC_4) == 0)
    {
        CaptureGenericPosition(4);
    }
    else if (strcmp(aIdentifier, KB_CAPTURE_GENERIC_5) == 0)
    {
        CaptureGenericPosition(5);
    }
    else if (strcmp(aIdentifier, KB_CAPTURE_YES_DIALOG) == 0)
    {
        CaptureYesDialogPosition();
    }
    else if (strcmp(aIdentifier, KB_CAPTURE_MYSTIC_FORGE) == 0)
    {
        CaptureMysticForgePosition();
    }
    else if (strcmp(aIdentifier, KB_CAPTURE_MYSTIC_REFILL) == 0)
    {
        CaptureMysticRefillPosition();
    }
    else if (strcmp(aIdentifier, KB_CAPTURE_VENDOR) == 0)
    {
        CaptureVendorPosition();
    }
    else if (strcmp(aIdentifier, KB_CAPTURE_SELL_JUNK) == 0)
    {
        CaptureSellJunkPosition();
    }
}
