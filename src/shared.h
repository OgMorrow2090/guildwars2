#pragma once

#include <windows.h>
#include "Nexus.h"

// Global API pointer - set in AddonLoad
extern AddonAPI* APIDefs;

// Addon definition
extern AddonDefinition AddonDef;

// Game window handle
extern HWND GameWindow;

// Keybind identifiers
constexpr const char* KB_DEPOSIT_MATERIALS = "KB_DEPOSIT_MATERIALS";
constexpr const char* KB_SORT_INVENTORY = "KB_SORT_INVENTORY";

// Keybind handler
void ProcessKeybind(const char* aIdentifier, bool aIsRelease);

// Input simulation functions
void SimulateDepositMaterialsClick();
void SimulateSortInventoryClick();
void SimulateClickAt(int x, int y);
