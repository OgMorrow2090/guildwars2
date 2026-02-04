# Inventory Hotkeys - Keybind Reference

<!-- markdownlint-disable MD033 -->

All keybinds for the Inventory Hotkeys addon. Configure in Nexus Options → Keybinds.

## Action Hotkeys

| Action | Default Key | Scan Code | Description |
| ------ | ----------- | --------- | ----------- |
| **DEPOSIT_MATERIALS** | Ctrl+D | 32 | Click deposit materials button |
| **SORT_INVENTORY** | Ctrl+S | 31 | Click sort/compact button |
| **OPEN_CHEST** | Ctrl+B | 48 | Right-click bouncy chest |
| **DEPOSIT_AND_SORT** | Ctrl+Q | 16 | Combo: deposit then sort (100ms delay) |
| **EXIT_INSTANCE** | Ctrl+E | 18 | Click exit instance button |
| **YES_DIALOG** | Ctrl+Y | 21 | Click Yes on confirmation dialogs |
| **MYSTIC_FORGE** | Ctrl+F | 33 | Click Mystic Forge combine button |
| **MYSTIC_REFILL** | Ctrl+R | 19 | Click Mystic Forge refill button |
| **MYSTIC_FORGE_COMBO** | Ctrl+A | 30 | Forge then Refill (100ms delay) |
| **VENDOR** | Ctrl+V | 47 | Click vendor button |
| **SELL_JUNK** | Ctrl+J | 36 | Click sell junk button |
| **TRADING_POST** | Ctrl+O | 24 | Click trading post button |
| **TP_REMOVE** | Ctrl+T | 20 | Click "Take" in Trading Post pickup |
| **GENERIC_2** | Ctrl+2 | 3 | User-assignable hotkey slot 2 |

## Capture Hotkeys

Use these to save button positions. Hover over the button, then press the capture key.

| Capture | Default Key | Scan Code | Saves Position For |
| ------- | ----------- | --------- | ------------------ |
| **CAPTURE_DEPOSIT** | Ctrl+Shift+D | 32 | Deposit Materials button |
| **CAPTURE_SORT** | Ctrl+Shift+S | 31 | Sort/Compact button |
| **CAPTURE_CHEST** | Ctrl+Shift+B | 48 | Bouncy Chest location |
| **CAPTURE_EXIT_INSTANCE** | Ctrl+Shift+E | 18 | Exit Instance button |
| **CAPTURE_YES_DIALOG** | Ctrl+Shift+Y | 21 | Yes Dialog button |
| **CAPTURE_MYSTIC_FORGE** | Ctrl+Shift+F | 33 | Mystic Forge button |
| **CAPTURE_MYSTIC_REFILL** | Ctrl+Shift+R | 19 | Mystic Refill button |
| **CAPTURE_VENDOR** | Ctrl+Shift+V | 47 | Vendor button |
| **CAPTURE_SELL_JUNK** | Ctrl+Shift+J | 36 | Sell Junk button |
| **CAPTURE_TRADING_POST** | Ctrl+Shift+O | 24 | Trading Post button |
| **CAPTURE_TP_REMOVE** | Ctrl+Shift+T | 20 | TP Remove/Take button |
| **CAPTURE_GENERIC_1** | Ctrl+Shift+1 | 2 | Generic slot 1 |
| **CAPTURE_GENERIC_2** | Ctrl+Shift+2 | 3 | Generic slot 2 |
| **CAPTURE_GENERIC_3** | Ctrl+Shift+3 | 4 | Generic slot 3 |
| **CAPTURE_GENERIC_4** | Ctrl+Shift+4 | 5 | Generic slot 4 |
| **CAPTURE_GENERIC_5** | Ctrl+Shift+5 | 6 | Generic slot 5 |

## Unassigned Hotkeys

These hotkeys are registered but not bound to any key by default:

| Action | Description |
| ------ | ----------- |
| **GENERIC_1** | User-assignable hotkey slot 1 |
| **GENERIC_3** | User-assignable hotkey slot 3 |
| **GENERIC_4** | User-assignable hotkey slot 4 |
| **GENERIC_5** | User-assignable hotkey slot 5 |

## Scan Code Reference

Nexus uses Windows Virtual Key codes. Common codes:

| Key | Code | Key | Code | Key | Code |
| --- | ---- | --- | ---- | --- | ---- |
| 1 | 2 | A | 30 | Q | 16 |
| 2 | 3 | B | 48 | R | 19 |
| 3 | 4 | C | 46 | S | 31 |
| 4 | 5 | D | 32 | T | 20 |
| 5 | 6 | E | 18 | V | 47 |
| 6 | 7 | F | 33 | Y | 21 |
| 7 | 8 | J | 36 | O | 24 |

## Config Backup

The Nexus keybind configuration is backed up at:

- **Repository**: `configs/nexus-inputbinds.json`
- **Live Location**: `Guild Wars 2/addons/Nexus/InputBinds.json`

To restore keybinds, copy `nexus-inputbinds.json` to the Nexus folder and rename to `InputBinds.json`.

## Notes

- All positions are saved per-resolution in `inventory-hotkeys-WIDTHxHEIGHT.cfg`
- Combo hotkeys (Deposit+Sort, Mystic Forge Combo) use 100ms delay between clicks
- Positions reset when resolution changes - recapture is required
