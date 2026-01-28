# Development Roadmap

Development plans for Guild Wars 2 Addons.

## 🎯 Current Focus: Inventory Hotkeys Addon

### Phase 1: Foundation (v0.1.0)

- [ ] **Development Environment**
  - [ ] Set up Visual Studio 2022 project
  - [ ] Configure Nexus API header
  - [ ] Create basic DLL structure
  - [ ] Test addon loading in game

- [ ] **Core Keybind System**
  - [ ] Implement `GetAddonDef()` export
  - [ ] Register keybinds for Deposit Materials
  - [ ] Register keybinds for Sort Inventory
  - [ ] Implement `ProcessKeybind()` handler

- [ ] **Input Simulation**
  - [ ] Research button position detection
  - [ ] Implement `SendWndProcToGameOnly()` wrapper
  - [ ] Calculate inventory button positions
  - [ ] Test click simulation in game

### Phase 2: Polish (v0.2.0)

- [ ] **UI Scaling Support**
  - [ ] Read MumbleLink UI size setting
  - [ ] Adjust button positions for different UI scales
  - [ ] Test across resolutions (1080p, 1440p, 4K)

- [ ] **Options Panel**
  - [ ] Create ImGui options interface
  - [ ] Display current keybind settings
  - [ ] Show addon status/feedback

- [ ] **Quick Access Integration**
  - [ ] Create addon icons (normal + hover)
  - [ ] Add shortcut to Nexus menu bar
  - [ ] Implement icon click handlers

### Phase 3: Advanced Features (v0.3.0)

- [ ] **Inventory State Detection**
  - [ ] Detect if inventory is open
  - [ ] Show warning if inventory closed
  - [ ] Optional auto-open inventory

- [ ] **Additional Hotkeys**
  - [ ] Salvage all (if feasible)
  - [ ] Consume all (if feasible)
  - [ ] Custom action triggers

### Phase 4: Release (v1.0.0)

- [ ] **Testing & Stability**
  - [ ] Comprehensive testing across game modes
  - [ ] Memory leak verification
  - [ ] Performance optimization

- [ ] **Distribution**
  - [ ] Create GitHub releases
  - [ ] Write user documentation
  - [ ] Consider Raidcore addon library submission

---

## 📋 Backlog

### Future Addon Ideas

| Idea                       | Description                          | Priority |
| -------------------------- | ------------------------------------ | -------- |
| Auto-Deposit on Map Change | Trigger deposit when changing maps   | Low      |
| Inventory Presets          | Save/restore inventory layouts       | Low      |
| Quick Sell                 | Hotkey to sell junk items            | Medium   |

---

## ✅ Completed

### January 2026

- [x] Research Nexus API capabilities
- [x] Confirm feasibility of input simulation
- [x] Create repository structure
- [x] Document development approach
- [x] Create agents.md with Nexus development patterns
- [x] Create C++ source structure (entry.cpp, shared.h)
- [x] Set up changelog with version tracking
- [x] Push initial repository to GitHub

---

Roadmap for Guild Wars 2 Addons - Updated January 2026
