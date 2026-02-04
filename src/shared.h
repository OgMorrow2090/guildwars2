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
constexpr const char* KB_EXIT_INSTANCE = "KB_EXIT_INSTANCE";

// Keybind identifiers - Generic (user-assignable)
constexpr const char* KB_GENERIC_1 = "KB_GENERIC_1";
constexpr const char* KB_GENERIC_2 = "KB_GENERIC_2";
constexpr const char* KB_GENERIC_3 = "KB_GENERIC_3";
constexpr const char* KB_GENERIC_4 = "KB_GENERIC_4";
constexpr const char* KB_GENERIC_5 = "KB_GENERIC_5";

// Keybind identifiers - Capture positions
constexpr const char* KB_CAPTURE_DEPOSIT = "KB_CAPTURE_DEPOSIT";
constexpr const char* KB_CAPTURE_SORT = "KB_CAPTURE_SORT";
constexpr const char* KB_CAPTURE_CHEST = "KB_CAPTURE_CHEST";
constexpr const char* KB_CAPTURE_EXIT_INSTANCE = "KB_CAPTURE_EXIT_INSTANCE";
constexpr const char* KB_CAPTURE_GENERIC_1 = "KB_CAPTURE_GENERIC_1";
constexpr const char* KB_CAPTURE_GENERIC_2 = "KB_CAPTURE_GENERIC_2";
constexpr const char* KB_CAPTURE_GENERIC_3 = "KB_CAPTURE_GENERIC_3";
constexpr const char* KB_CAPTURE_GENERIC_4 = "KB_CAPTURE_GENERIC_4";
constexpr const char* KB_CAPTURE_GENERIC_5 = "KB_CAPTURE_GENERIC_5";

// Keybind handler
void ProcessKeybind(const char* aIdentifier, bool aIsRelease);

// Input simulation functions
void SimulateDepositMaterialsClick();
void SimulateSortInventoryClick();
void SimulateOpenChestClick();
void SimulateDepositAndSort();
void SimulateExitInstanceClick();
void SimulateGenericClick(int slot);
void SimulateClickAt(int x, int y);
void SimulateRightClickAt(int x, int y);

// Capture functions
void CaptureDepositPosition();
void CaptureSortPosition();
void CaptureChestPosition();
void CaptureExitInstancePosition();
void CaptureGenericPosition(int slot);

// Config functions
void SetConfigPath(const char* addonPath);
void LoadButtonPositions();
void SaveButtonPositions();
void CheckResolutionChange();

// Button positions
extern int g_DepositX;
extern int g_DepositY;
extern int g_SortX;
extern int g_SortY;
extern int g_ChestX;
extern int g_ChestY;
extern int g_ExitInstanceX;
extern int g_ExitInstanceY;
extern int g_Generic1X;
extern int g_Generic1Y;
extern int g_Generic2X;
extern int g_Generic2Y;
extern int g_Generic3X;
extern int g_Generic3Y;
extern int g_Generic4X;
extern int g_Generic4Y;
extern int g_Generic5X;
extern int g_Generic5Y;
