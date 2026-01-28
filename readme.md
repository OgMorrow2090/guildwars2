# Guild Wars 2 Addons

Nexus addon development for Guild Wars 2 quality-of-life improvements.

## 🎯 Current Projects

### Inventory Hotkeys Addon

Adds configurable hotkeys for inventory management actions that normally require clicking:

- **Deposit All Materials** - Hotkey to deposit all crafting materials to bank
- **Compact/Sort Inventory** - Hotkey to sort and compact inventory items

## 📋 Status

| Feature | Status | Description |
|---------|--------|-------------|
| Deposit Materials Hotkey | 🔬 Research | Keybind to trigger "Deposit All Materials" |
| Sort Inventory Hotkey | 🔬 Research | Keybind to trigger inventory compact/sort |
| Quick Access Integration | 📋 Planned | Icons in Nexus menu bar |
| Configurable Keys | 📋 Planned | User-customizable hotkey bindings |

## 🔧 Technical Stack

- **Framework**: [Raidcore Nexus](https://github.com/RaidcoreGG/Nexus) addon loader
- **Language**: C++ (Windows DLL)
- **Build System**: Visual Studio 2022
- **UI Framework**: ImGui (provided by Nexus)

## 📁 Repository Structure

```
guildwars2/
├── readme.md                 # This file
├── agents.md                 # AI agent development instructions
├── changelog.md              # Version history
├── roadmap.md                # Development plans
├── src/                      # Source code
│   ├── entry.cpp            # DLL entry point and addon definition
│   ├── keybinds.cpp         # Hotkey registration and handlers
│   ├── input_sim.cpp        # Mouse/keyboard input simulation
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

### Development Setup

See [docs/development-setup.md](docs/development-setup.md) for build instructions.

## 📚 Resources

| Resource | Link |
|----------|------|
| Nexus GitHub | https://github.com/RaidcoreGG/Nexus |
| Nexus API Header | https://github.com/RaidcoreGG/RCGG-lib-nexus-api |
| Nexus Wiki | https://github.com/RaidcoreGG/Nexus/wiki |
| Example Addon | https://github.com/RaidcoreGG/GW2-Compass |
| Raidcore Discord | https://discord.gg/Mvk7W7gjE4 |
| This Repository | https://github.com/OgMorrow2090/guildwars2 |

## ⚖️ License

MIT License - See LICENSE file for details.

## 🤝 Contributing

Contributions welcome! Please read the development setup guide and follow existing code patterns.

---

*Built with [Raidcore Nexus](https://raidcore.gg/Nexus) addon framework*
