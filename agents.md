# Guild Wars 2 Addons - AI Agent Instructions

<!-- markdownlint-disable MD022 MD032 MD031 MD040 -->

> **⚠️ IMPORTANT: Always read readme.md first for complete project context before proceeding with any code changes.**
>
> **📁 LOWERCASE FILENAMES ONLY: All new files MUST use lowercase names with hyphens for spaces. Examples: `readme.md`, `input-sim.cpp`, `my-addon.dll`. NEVER use uppercase letters in filenames.**
>
> **🏆 GOLDEN RULE - REPO FIRST CONFIGURATION:**
>
> - **Source of Truth**: The Git repository is the single source of truth for all code and configurations.
> - **Ask before editing**: If unsure about architecture decisions, ask first.

## 🏗️ PROJECT OVERVIEW

This repository contains Nexus addon development for Guild Wars 2. The primary project is an **Inventory Hotkeys Addon** that allows users to trigger inventory management functions via keyboard shortcuts instead of clicking buttons.

### **Technical Context**

- **Platform**: Windows only (DLL-based addon)
- **Framework**: Raidcore Nexus addon loader
- **Language**: C++ (with C compatibility)
- **Build Tool**: Visual Studio 2022
- **UI Framework**: ImGui (provided by Nexus)

## 🎯 CORE FUNCTIONALITY

### **Inventory Hotkeys Addon**

The addon intercepts registered keybinds and simulates mouse clicks on the inventory UI buttons:

1. **Deposit All Materials** - Clicks the "deposit materials" button
2. **Compact/Sort Inventory** - Clicks the "compact" button

### **Technical Approach**

```
User Presses Hotkey → Nexus Keybind Handler → Calculate Button Position → SendWndProcToGameOnly() → Game Receives Click
```

## 📁 FILE STRUCTURE CONVENTIONS

### **Source Files (`src/`)**

| File | Purpose |
|------|---------|
| `entry.cpp` | DLL entry point, `GetAddonDef()` export, Load/Unload functions |
| `keybinds.cpp` | Keybind registration and `ProcessKeybind()` handler |
| `input-sim.cpp` | Input simulation using `SendWndProcToGameOnly()` |
| `shared.h` | Global state, API pointer, shared definitions |

### **Include Files (`include/`)**

| File | Purpose |
|------|---------|
| `Nexus.h` | Nexus API definitions (from RCGG-lib-nexus-api) |

### **Resources (`resources/`)**

| Directory | Purpose |
|-----------|---------|
| `icons/` | Quick Access menu icons (normal and hover states) |

## 🔧 NEXUS API PATTERNS

### **Addon Definition Export**

```cpp
extern "C" __declspec(dllexport) AddonDefinition* GetAddonDef()
{
    AddonDef.Signature = -12345;  // Negative for non-Raidcore addons
    AddonDef.APIVersion = NEXUS_API_VERSION;
    AddonDef.Name = "Inventory Hotkeys";
    AddonDef.Version.Major = 1;
    AddonDef.Version.Minor = 0;
    AddonDef.Version.Build = 0;
    AddonDef.Version.Revision = 0;
    AddonDef.Author = "ITINYK";
    AddonDef.Description = "Hotkeys for inventory management actions.";
    AddonDef.Load = AddonLoad;
    AddonDef.Unload = AddonUnload;
    AddonDef.Flags = EAddonFlags::None;
    AddonDef.Provider = EUpdateProvider::GitHub;
    AddonDef.UpdateLink = "https://github.com/OgMorrow2090/guildwars2";
    
    return &AddonDef;
}
```

### **Keybind Registration**

```cpp
void AddonLoad(AddonAPI* aApi)
{
    APIDefs = aApi;
    
    // Set up ImGui context
    ImGui::SetCurrentContext((ImGuiContext*)APIDefs->ImguiContext);
    ImGui::SetAllocatorFunctions(
        (void* (*)(size_t, void*))APIDefs->ImguiMalloc,
        (void(*)(void*, void*))APIDefs->ImguiFree
    );
    
    // Register keybinds with default keys
    APIDefs->RegisterKeybindWithString("KB_DEPOSIT_MATERIALS", ProcessKeybind, "CTRL+D");
    APIDefs->RegisterKeybindWithString("KB_SORT_INVENTORY", ProcessKeybind, "CTRL+SHIFT+S");
}
```

### **Keybind Handler**

```cpp
void ProcessKeybind(const char* aIdentifier, bool aIsRelease)
{
    if (aIsRelease) return;  // Only act on key press, not release
    
    if (strcmp(aIdentifier, "KB_DEPOSIT_MATERIALS") == 0)
    {
        SimulateDepositMaterialsClick();
    }
    else if (strcmp(aIdentifier, "KB_SORT_INVENTORY") == 0)
    {
        SimulateSortInventoryClick();
    }
}
```

### **Input Simulation**

```cpp
void SimulateClickAt(int x, int y)
{
    LPARAM lParam = MAKELPARAM(x, y);
    
    // Mouse down
    APIDefs->SendWndProcToGameOnly(
        hWnd,
        WM_LBUTTONDOWN,
        MK_LBUTTON,
        lParam
    );
    
    // Mouse up
    APIDefs->SendWndProcToGameOnly(
        hWnd,
        WM_LBUTTONUP,
        0,
        lParam
    );
}
```

## 🎯 DEVELOPMENT CHALLENGES

### **Button Position Detection**

The main challenge is determining where the inventory buttons are on screen:

| Approach | Pros | Cons |
|----------|------|------|
| **Fixed offsets** | Simple to implement | Breaks with UI scaling/resolution |
| **UI scale calculation** | More robust | Requires detecting UI scale setting |
| **Memory reading** | Most accurate | Complex, may need updates |
| **MumbleLink data** | Game-provided | Limited UI information |

### **Recommended Approach**

1. Start with **fixed offsets** for proof of concept
2. Use **MumbleLink** `UISize` field to adjust for UI scaling
3. Calculate button position relative to screen size

```cpp
// MumbleLink provides UI size setting (0-3)
// 0 = Small, 1 = Normal, 2 = Large, 3 = Larger
MumbleLink* ml = (MumbleLink*)APIDefs->GetResource("DL_MUMBLE_LINK");
unsigned uiSize = ml->Identity.UISize;
```

## 🔒 SAFETY CONSIDERATIONS

### **ArenaNet ToS Compliance**

- ✅ **Allowed**: UI convenience addons, keybind remapping
- ✅ **Allowed**: Single action per keypress (1:1 input)
- ⚠️ **Caution**: Do not automate gameplay or create macros
- ❌ **Forbidden**: Multiple actions per keypress, automation

### **Addon Safety**

- Always handle null pointers from API calls
- Clean up resources in `AddonUnload()`
- Don't block the render thread
- Use async operations for any delays

## 📋 CODING STANDARDS

### **Naming Conventions**

| Type | Convention | Example |
|------|------------|---------|
| Files | lowercase with hyphens | `input-sim.cpp` |
| Functions | PascalCase | `ProcessKeybind()` |
| Variables | camelCase | `isInventoryOpen` |
| Constants | SCREAMING_SNAKE | `KB_DEPOSIT_MATERIALS` |
| Keybind IDs | `KB_` prefix | `KB_SORT_INVENTORY` |
| Texture IDs | `TEX_` prefix | `TEX_ADDON_ICON` |

### **Error Handling**

```cpp
// Always check API return values
Texture* icon = APIDefs->GetTexture("TEX_MY_ICON");
if (icon != nullptr && icon->Resource != nullptr)
{
    ImGui::Image(icon->Resource, ImVec2(icon->Width, icon->Height));
}
```

### **Logging**

```cpp
// Use Nexus logging for debugging
APIDefs->Log(ELogLevel_INFO, "InventoryHotkeys", "Addon loaded successfully");
APIDefs->Log(ELogLevel_WARNING, "InventoryHotkeys", "Could not detect inventory position");
```

## 🧹 Session Cleanup Protocol

### **When to Execute Session Cleanup**

AI agents should initiate session cleanup when the user mentions:

- "cleanup"
- "session end"
- "synchronize"

### **Key Session Cleanup Actions**

- Remove debugging statements and temporary test code
- Update all documentation (changelog.md, readme.md, roadmap.md)
- Ensure code compiles without warnings
- Stage, commit, and push all changes with descriptive messages
- Prepare workspace for clean start

## 📚 REFERENCE DOCUMENTATION

| Document | Purpose |
|----------|---------|
| [Nexus Wiki](https://github.com/RaidcoreGG/Nexus/wiki) | Official API documentation |
| [Nexus API](https://github.com/RaidcoreGG/Nexus/wiki/API) | Function reference |
| [Addon Quickstart](https://github.com/RaidcoreGG/Nexus/wiki/Addon-Quickstart) | Getting started guide |
| [GW2 Compass](https://github.com/RaidcoreGG/GW2-Compass) | Example addon |

---

*AI Agent Instructions for Guild Wars 2 Addon Development*
