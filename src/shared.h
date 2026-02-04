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
constexpr const char* KB_DEPOSIT_MATERIALS = "DEPOSIT_MATERIALS";
constexpr const char* KB_SORT_INVENTORY = "SORT_INVENTORY";
constexpr const char* KB_OPEN_CHEST = "OPEN_CHEST";
constexpr const char* KB_DEPOSIT_AND_SORT = "DEPOSIT_AND_SORT";
constexpr const char* KB_EXIT_INSTANCE = "EXIT_INSTANCE";
constexpr const char* KB_YES_DIALOG = "YES_DIALOG";
constexpr const char* KB_MYSTIC_FORGE = "MYSTIC_FORGE";
constexpr const char* KB_MYSTIC_REFILL = "MYSTIC_REFILL";
constexpr const char* KB_MYSTIC_FORGE_COMBO = "MYSTIC_FORGE_COMBO";
constexpr const char* KB_VENDOR = "VENDOR";
constexpr const char* KB_SELL_JUNK = "SELL_JUNK";
constexpr const char* KB_TRADING_POST = "TRADING_POST";
constexpr const char* KB_TP_REMOVE = "TP_REMOVE";

// Keybind identifiers - Generic (user-assignable)
constexpr const char* KB_GENERIC_1 = "GENERIC_1";
constexpr const char* KB_GENERIC_2 = "GENERIC_2";
constexpr const char* KB_GENERIC_3 = "GENERIC_3";
constexpr const char* KB_GENERIC_4 = "GENERIC_4";
constexpr const char* KB_GENERIC_5 = "GENERIC_5";

// Keybind identifiers - Capture positions
constexpr const char* KB_CAPTURE_DEPOSIT = "CAPTURE_DEPOSIT";
constexpr const char* KB_CAPTURE_SORT = "CAPTURE_SORT";
constexpr const char* KB_CAPTURE_CHEST = "CAPTURE_CHEST";
constexpr const char* KB_CAPTURE_EXIT_INSTANCE = "CAPTURE_EXIT_INSTANCE";
constexpr const char* KB_CAPTURE_GENERIC_1 = "CAPTURE_GENERIC_1";
constexpr const char* KB_CAPTURE_GENERIC_2 = "CAPTURE_GENERIC_2";
constexpr const char* KB_CAPTURE_GENERIC_3 = "CAPTURE_GENERIC_3";
constexpr const char* KB_CAPTURE_GENERIC_4 = "CAPTURE_GENERIC_4";
constexpr const char* KB_CAPTURE_GENERIC_5 = "CAPTURE_GENERIC_5";
constexpr const char* KB_CAPTURE_YES_DIALOG = "CAPTURE_YES_DIALOG";
constexpr const char* KB_CAPTURE_MYSTIC_FORGE = "CAPTURE_MYSTIC_FORGE";
constexpr const char* KB_CAPTURE_MYSTIC_REFILL = "CAPTURE_MYSTIC_REFILL";
constexpr const char* KB_CAPTURE_VENDOR = "CAPTURE_VENDOR";
constexpr const char* KB_CAPTURE_SELL_JUNK = "CAPTURE_SELL_JUNK";
constexpr const char* KB_CAPTURE_TRADING_POST = "CAPTURE_TRADING_POST";
constexpr const char* KB_CAPTURE_TP_REMOVE = "CAPTURE_TP_REMOVE";

// Keybind handler
void ProcessKeybind(const char* aIdentifier, bool aIsRelease);

// Input simulation functions
void SimulateDepositMaterialsClick();
void SimulateSortInventoryClick();
void SimulateOpenChestClick();
void SimulateDepositAndSort();
void SimulateExitInstanceClick();
void SimulateYesDialogClick();
void SimulateMysticForgeClick();
void SimulateMysticRefillClick();
void SimulateMysticForgeCombo();
void SimulateVendorClick();
void SimulateSellJunkClick();
void SimulateTradingPostClick();
void SimulateTpRemoveClick();
void SimulateGenericClick(int slot);
void SimulateClickAt(int x, int y);
void SimulateRightClickAt(int x, int y);

// Capture functions
void CaptureDepositPosition();
void CaptureSortPosition();
void CaptureChestPosition();
void CaptureExitInstancePosition();
void CaptureYesDialogPosition();
void CaptureMysticForgePosition();
void CaptureMysticRefillPosition();
void CaptureVendorPosition();
void CaptureSellJunkPosition();
void CaptureTradingPostPosition();
void CaptureTpRemovePosition();
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
extern int g_YesDialogX;
extern int g_YesDialogY;
extern int g_MysticForgeX;
extern int g_MysticForgeY;
extern int g_MysticRefillX;
extern int g_MysticRefillY;
extern int g_VendorX;
extern int g_VendorY;
extern int g_SellJunkX;
extern int g_SellJunkY;
extern int g_TradingPostX;
extern int g_TradingPostY;
extern int g_TpRemoveX;
extern int g_TpRemoveY;
