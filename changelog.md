# Changelog

<!-- markdownlint-disable MD024 -->

All notable changes to Guild Wars 2 Addons will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [1.3.0] - 2026-02-04

### Added

- **Yes Dialog Hotkey** (Ctrl+P) - Click the Yes button on confirmation dialogs
- **Mystic Forge Hotkey** (Ctrl+F) - Click the Mystic Forge combine button
- **Mystic Refill Hotkey** (Ctrl+R) - Click the Mystic Forge refill button
- **Mystic Forge Combo** (Ctrl+A) - Forge then Refill with 100ms delay
- **Capture keybinds** for new hotkeys (Ctrl+Shift+P/F/R)

### Changed

- **Cleaner keybind names** - Removed "KB_" prefix from all keybind identifiers
  - e.g., "KB_DEPOSIT_MATERIALS" → "DEPOSIT_MATERIALS"
  - Requires re-binding keys in Nexus after update

### Technical

- Added 6 new position variables for Yes Dialog and Mystic Forge buttons
- All positions saved per-resolution in config files

## [1.2.0] - 2026-02-04

### Added

- **Exit Instance Hotkey** (Ctrl+E) - Click the exit instance button
- **5 Generic Hotkeys** - User-assignable click hotkeys for any UI element
  - Generic 1-5 with capture keys Ctrl+Shift+1-5
  - Unassigned by default - configure in Nexus Options
- **Capture Exit Instance** (Ctrl+Shift+E) - Save exit instance button location

### Technical

- Added 12 new position variables for exit instance and generic hotkeys
- All positions saved per-resolution in config files

## [1.1.0] - 2026-02-04

### Added

- **Per-Resolution Config Files** - Positions now save to resolution-specific files
  - e.g., `inventory-hotkeys-1920x1080.cfg`, `inventory-hotkeys-2560x1440.cfg`
- **Auto Resolution Detection** - Detects current game window resolution on startup
- **Resolution Change Detection** - Automatically switches config when resolution changes
- **Multi-Device Support** - Switch between laptop and desktop without reconfiguring

### Changed

- Config files now include resolution in filename
- Alert messages show current resolution when loading/saving

## [1.0.0] - 2026-02-03

### Added

- **Deposit Materials Hotkey** (Ctrl+D) - Click deposit materials button
- **Sort/Compact Hotkey** (Ctrl+S) - Click sort/compact button
- **Bouncy Chest Hotkey** (Ctrl+B) - Right-click to open bouncy chests
- **Deposit + Sort Combo** (Ctrl+Q) - Performs deposit then sort in sequence
- **Position Capture System** - Keybinds to save button positions at cursor
  - Ctrl+Shift+D for deposit button
  - Ctrl+Shift+S for sort button
  - Ctrl+Shift+B for bouncy chest
- **Config Persistence** - Saves positions to `inventory-hotkeys.cfg`
- **Nexus Integration** - Full keybind customization via Nexus Options UI
- **Visual Studio 2025 Support** - Built with Platform Toolset v145

### Technical

- Nexus API v6 integration
- `WndProc_SendToGameOnly` for input simulation
- `GUI_SendAlert` for user feedback
- Auto-creates config directory if missing

## [0.1.0] - 2026-01-01

### Initial Release

- Initial repository structure
- Project documentation (readme.md, agents.md, roadmap.md)
- Development setup guide
- Research documentation for Nexus addon development

---

## Version History Summary

| Version | Date       | Highlights                                      |
| ------- | ---------- | ----------------------------------------------- |
| 1.3.0   | 2026-02-04 | Yes Dialog, Mystic Forge hotkeys, cleaner names |
| 1.2.0   | 2026-02-04 | Exit instance hotkey, 5 generic hotkeys         |
| 1.1.0   | 2026-02-04 | Per-resolution configs, multi-device support    |
| 1.0.0   | 2026-02-03 | Full release with all core features             |
| 0.1.0   | 2026-01-01 | Initial structure and research                  |

---

Changelog for Guild Wars 2 Addons
