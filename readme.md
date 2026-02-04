# Guild Wars 2 Addons

Nexus addon development for Guild Wars 2 quality-of-life improvements.

## 🎯 Inventory Hotkeys Addon

Adds configurable hotkeys for inventory management actions that normally require clicking.

### Features

- **Deposit All Materials** - Left-click the deposit button
- **Compact/Sort Inventory** - Left-click the sort button
- **Open Bouncy Chest** - Right-click to open bouncy chests

### Keybinds

| Action | Default Key | Description |
| ------ | ----------- | ----------- |
| **Deposit Materials** | Ctrl+D | Click deposit materials button |
| **Compact/Sort** | Ctrl+C | Click sort/compact button |
| **Open Chest** | Ctrl+B | Right-click bouncy chest |
| **Deposit + Sort** | Ctrl+Q | Combo: deposit then sort |
| **Exit Instance** | Ctrl+E | Click exit instance button |
| **Yes Dialog** | Ctrl+P | Click Yes on confirmation dialogs |
| **Mystic Forge** | Ctrl+F | Click Mystic Forge combine button |
| **Mystic Refill** | Ctrl+R | Click Mystic Forge refill button |
| **Mystic Forge Combo** | Ctrl+A | Forge then Refill (100ms delay) |
| **Vendor** | Ctrl+V | Click vendor button |
| **Sell Junk** | Ctrl+J | Click sell junk button |
| **Generic 1-5** | Ctrl+1/2 | User-assignable click hotkeys |

| Capture Position | Default Key | Description |
| ---------------- | ----------- | ----------- |
| **Capture Deposit** | Ctrl+Shift+D | Save deposit button location |
| **Capture Sort** | Ctrl+Shift+C | Save sort button location |
| **Capture Chest** | Ctrl+Shift+B | Save bouncy chest location |
| **Capture Exit** | Ctrl+Shift+E | Save exit instance button location |
| **Capture Yes Dialog** | Ctrl+Shift+P | Save Yes button location |
| **Capture Mystic Forge** | Ctrl+Shift+F | Save Mystic Forge button location |
| **Capture Mystic Refill** | Ctrl+Shift+R | Save Mystic Refill button location |
| **Capture Vendor** | Ctrl+Shift+V | Save Vendor button location |
| **Capture Sell Junk** | Ctrl+Shift+J | Save Sell Junk button location |
| **Capture Generic 1-5** | Ctrl+Shift+1-5 | Save generic hotkey locations |

All keybinds can be customized in Nexus Options (Ctrl+O → Keybinds).

### First-Time Setup

1. Open inventory in GW2
2. Hover mouse over **Deposit Materials** button → Press **Ctrl+Shift+D**
3. Hover mouse over **Compact/Sort** button → Press **Ctrl+Shift+S**
4. (Optional) Hover over a **Bouncy Chest** → Press **Ctrl+Shift+B**
5. Positions are auto-saved to config file

### Config File

Positions are saved per-resolution to separate config files:

```text
Guild Wars 2/addons/InventoryHotkeys/inventory-hotkeys-1920x1080.cfg
Guild Wars 2/addons/InventoryHotkeys/inventory-hotkeys-2560x1440.cfg
Guild Wars 2/addons/InventoryHotkeys/inventory-hotkeys-3840x2160.cfg
```

When you switch between devices or change resolution, the addon automatically:

1. Detects the new resolution
2. Loads the config for that resolution (if exists)
3. Prompts you to capture positions if no config exists for the new resolution

This means you only need to capture positions **once per resolution** - switch between your laptop (1080p) and desktop (1440p) seamlessly!

## 📋 Status

| Feature | Status |
| ------- | ------ |
| Deposit Materials Hotkey | ✅ Working |
| Sort Inventory Hotkey | ✅ Working |
| Bouncy Chest Hotkey | ✅ Working |
| Deposit + Sort Combo | ✅ Working |
| Exit Instance Hotkey | ✅ Working |
| Yes Dialog Hotkey | ✅ Working |
| Mystic Forge Hotkeys | ✅ Working |
| Mystic Forge Combo | ✅ Working |
| Vendor Hotkey | ✅ Working |
| Sell Junk Hotkey | ✅ Working |
| Generic Hotkeys (5 slots) | ✅ Working |
| Position Capture | ✅ Working |
| Config Persistence | ✅ Working |
| Per-Resolution Configs | ✅ Working |
| Auto Resolution Detection | ✅ Working |
| Nexus Keybind UI | ✅ Working |

## 🔧 Technical Stack

- **Framework**: [Raidcore Nexus](https://github.com/RaidcoreGG/Nexus) addon loader
- **Language**: C++ (Windows DLL)
- **Build System**: Visual Studio 2025
- **API Version**: Nexus API v6

## 📁 Repository Structure

```text
guildwars2/
├── readme.md                 # This file
├── agents.md                 # AI agent development instructions
├── changelog.md              # Version history
├── roadmap.md                # Development plans
├── src/                      # Source code
│   ├── entry.cpp            # DLL entry point and addon definition
│   ├── keybinds.cpp         # Hotkey registration and handlers
│   ├── input-sim.cpp        # Mouse/keyboard input simulation
│   ├── config.cpp           # Configuration file handling
│   └── shared.h             # Shared state and API pointer
├── include/                  # External headers
│   └── Nexus.h              # Nexus API definitions
├── resources/                # Assets
│   └── icons/               # Quick Access menu icons
└── docs/                     # Documentation
    └── development-setup.md # Build environment setup
```

## 🚀 Getting Started

### Prerequisites

1. **Guild Wars 2** installed
2. **Nexus Addon Loader** - [Download](https://github.com/RaidcoreGG/Nexus/releases)
3. **Visual Studio 2022** with C++ Desktop Development workload

### Installation (End Users)

1. Install Nexus addon loader in your GW2 directory
2. Download the addon `.dll` from releases
3. Place in `Guild Wars 2/addons/` folder
4. Launch game and configure hotkeys in Nexus options (Ctrl+O)

**Steam Installation Path:**

```text
C:\Program Files (x86)\Steam\steamapps\common\Guild Wars 2\addons\inventory-hotkeys.dll
```

### Development Setup

See [docs/development-setup.md](docs/development-setup.md) for build instructions.

## 📚 Resources

| Resource | Link |
| -------- | ---- |
| Nexus GitHub | [RaidcoreGG/Nexus](https://github.com/RaidcoreGG/Nexus) |
| Nexus API Header | [RaidcoreGG/RCGG-lib-nexus-api](https://github.com/RaidcoreGG/RCGG-lib-nexus-api) |
| Nexus Wiki | [Nexus Wiki](https://github.com/RaidcoreGG/Nexus/wiki) |
| Example Addon | [GW2-Compass](https://github.com/RaidcoreGG/GW2-Compass) |
| Raidcore Discord | [Discord Invite](https://discord.gg/Mvk7W7gjE4) |
| This Repository | [OgMorrow2090/guildwars2](https://github.com/OgMorrow2090/guildwars2) |

## ⚖️ License

MIT License - See LICENSE file for details.

## 🤝 Contributing

Contributions welcome! Please read the development setup guide and follow existing code patterns.

---

*Built with [Raidcore Nexus](https://raidcore.gg/Nexus) addon framework*
