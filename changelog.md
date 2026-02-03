# Changelog

All notable changes to Guild Wars 2 Addons will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

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
| 1.0.0   | 2026-02-03 | Full release with all core features             |
| 0.1.0   | 2026-01-01 | Initial structure and research                  |

---

Changelog for Guild Wars 2 Addons
