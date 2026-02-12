# XRogue Enhanced Edition

An enhanced version of XRogue (Expeditions into the Dungeons of Doom) with modern quality-of-life improvements including full color support, sidebar UI, and interactive legend.

![XRogue Enhanced](https://img.shields.io/badge/version-enhanced-brightgreen) ![Platform](https://img.shields.io/badge/platform-linux-blue) ![License](https://img.shields.io/badge/license-see%20LICENSE-orange)

## ✨ New Features

### 🎨 Full Color Support
- **Colored Monsters**: Instantly identify threat levels
  - 🔴 Red: Hostile/aggressive monsters
  - 🟢 Green: Friendly monsters
  - 🟡 Yellow: Neutral monsters
  - 🟣 Magenta: Unique/boss monsters

- **Colored Items**: Easily spot loot on the ground
  - 🔵 Cyan: Weapons
  - 🔷 Blue: Armor
  - 🟡 Yellow: Gold
  - 🟢 Green: Food
  - 🟣 Magenta: Potions
  - ⚪ White: Scrolls, rings, wands

### 📊 Sidebar Panel
- **Nearby Objects**: Shows all items in the 8 adjacent squares with direction indicators (N, S, E, W, etc.)
- **Combat Log**: Displays the last 8 combat messages for easy reference
- **Real-time Updates**: Automatically refreshes after each action

### 🎯 Color-Coded Status Line
- **Health (HP)**: Color changes based on health percentage
  - 🟢 Green: Above 66% health
  - 🟡 Yellow: 33-66% health
  - 🔴 Red: Below 33% health (critical!)
- **Gold**: Displayed in bright yellow for easy tracking
- **All stats visible**: Level, HP, AC, Gold, Carry weight, Experience

### 📖 Interactive Symbol Legend
- Press **@** to view a comprehensive, color-coded legend of all game symbols
- Organized by category (terrain, items, monsters)
- Perfect for new players learning the game

## 🚀 Installation

### Prerequisites
- Linux/Unix operating system (or WSL on Windows)
- GCC compiler
- ncurses development library
- make utility

### Install Dependencies

**Debian/Ubuntu:**
```bash
sudo apt-get update
sudo apt-get install build-essential libncurses-dev
```

**Fedora/RHEL/CentOS:**
```bash
sudo dnf install gcc make ncurses-devel
```

**Arch Linux:**
```bash
sudo pacman -S base-devel ncurses
```

### Build & Run

```bash
# Clone the repository
git clone https://github.com/yourusername/zthief.git
cd zthief

# Compile
make

# Run the game
./zthief
```

## 🎮 How to Play

### Basic Controls
- **Movement**: `h` `j` `k` `l` (vi-style) or arrow keys
- **Pick up item**: `,` (comma)
- **Drop item**: `d`
- **Inventory**: `i`
- **Help**: `?`
- **Legend**: `@` ← **NEW!**
- **Quit**: `Q`

### Tips for New Players
1. Press `@` to view the symbol legend
2. Watch the sidebar for nearby items and monsters
3. Check the combat log to review recent battles
4. Colors help identify items and threats at a glance

## 🛠️ Technical Details

### New Files Added
- `colors.c` / `colors.h` - Color system implementation
- `sidebar.c` - Sidebar panel with nearby objects and combat log
- `legend.c` - Interactive symbol legend
- `display.c` - Colored rendering helper functions

### Modified Files
- `main.c` - Window layout and color initialization
- `command.c` - Sidebar updates and legend command
- `chase.c` - Colored monster rendering
- `things.c` - Colored item rendering when dropping
- `move.c` - Colored item rendering on map
- `fight.c` - Combat logging integration
- `rogue.h` - Color definitions and function declarations

## 📜 Original XRogue

XRogue is based on the classic roguelike game "Rogue: Exploring the Dungeons of Doom" and its successor "Advanced Rogue". This enhanced version maintains all original gameplay while adding modern visual improvements.

### Credits
- **Original Rogue**: Michael Toy, Ken Arnold, Glenn Wichman (1980)
- **Advanced Rogue**: Michael Morgan, Ken Dalka, AT&T (1984-1985)
- **XRogue**: Robert Pietkivitch (1991)
- **Enhanced Edition**: Quality-of-life improvements and color support (2026)

## 📄 License

See the `LICENSE.TXT` file for full copyright and licensing information.

## 🤝 Contributing

Contributions are welcome! Feel free to:
- Report bugs
- Suggest new features
- Submit pull requests

## 🎯 Future Enhancements

Potential improvements for future versions:
- Health bar color coding in status line
- Damage numbers in combat messages
- Minimap display
- Mouse support
- Additional color themes

---

**Enjoy your enhanced dungeon crawling experience!** 🗡️⚔️🛡️
