#pragma once

#include <windows.h>
#include "Nexus.h"

// Global API pointer - set in AddonLoad
extern AddonAPI_t* APIDefs;

// Addon definition
extern AddonDefinition_t AddonDef;

// Game window handle
extern HWND GameWindow;

// Keybind identifiers - Actions
constexpr const char* KB_DEPOSIT_MATERIALS = "KB_DEPOSIT_MATERIALS";
constexpr const char* KB_SORT_INVENTORY = "KB_SORT_INVENTORY";
constexpr const char* KB_OPEN_CHEST = "KB_OPEN_CHEST";
constexpr const char* KB_DEPOSIT_AND_SORT = "KB_DEPOSIT_AND_SORT";

// Keybind identifiers - Capture positions
constexpr const char* KB_CAPTURE_DEPOSIT = "KB_CAPTURE_DEPOSIT";
constexpr const char* KB_CAPTURE_SORT = "KB_CAPTURE_SORT";
constexpr const char* KB_CAPTURE_CHEST = "KB_CAPTURE_CHEST";

// Keybind handler
void ProcessKeybind(const char* aIdentifier, bool aIsRelease);

// Input simulation functions
void SimulateDepositMaterialsClick();
void SimulateSortInventoryClick();
void SimulateOpenChestClick();
void SimulateDepositAndSort();
void SimulateClickAt(int x, int y);
void SimulateRightClickAt(int x, int y);

// Capture functions
void CaptureDepositPosition();
void CaptureSortPosition();
void CaptureChestPosition();

// Config functions
void SetConfigPath(const char* addonPath);
void LoadButtonPositions();
void SaveButtonPositions();

// Button positions
extern int g_DepositX;
extern int g_DepositY;
extern int g_SortX;
extern int g_SortY;
extern int g_ChestX;
extern int g_ChestY;
