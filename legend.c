/*
    legend.c - Display a legend of game symbols
    
    XRogue: Expeditions into the Dungeons of Doom
*/

#include <curses.h>
#include "rogue.h"

/*
 * show_legend:
 *      Display a legend of all game symbols
 */
void
show_legend()
{
    WINDOW *lw;
    int row = 2;
    
    lw = newwin(lines, cols, 0, 0);
    wclear(lw);
    
    /* Title */
    mvwaddstr(lw, 0, 20, "=== XROGUE SYMBOL LEGEND (Press @) ===");
    
    /* Terrain symbols */
    mvwaddstr(lw, row++, 2, "TERRAIN:");
    mvwaddstr(lw, row++, 4, ".  Floor/Ground");
    mvwaddstr(lw, row++, 4, "#  Corridor/Passage");
    mvwaddstr(lw, row++, 4, "+  Door");
    mvwaddstr(lw, row++, 4, "-  Horizontal wall");
    mvwaddstr(lw, row++, 4, "|  Vertical wall");
    mvwaddstr(lw, row++, 4, "^  Trap");
    mvwaddstr(lw, row++, 4, ">  Stairs down");
    mvwaddstr(lw, row++, 4, "<  Stairs up");
    mvwaddstr(lw, row++, 4, "%  Stairs (outside)");
    row++;
    
    /* Player */
    mvwaddstr(lw, row++, 2, "PLAYER:");
    mvwaddstr(lw, row++, 4, "@  You (the player)");
    row++;
    
    /* Items */
    mvwaddstr(lw, row++, 2, "ITEMS:");
    
    /* Color-code items if colors are supported */
    if (color_support) {
        wattron(lw, COLOR_PAIR(CP_ITEM_POTION));
        mvwaddstr(lw, row++, 4, "!  Potion");
        wattroff(lw, COLOR_PAIR(CP_ITEM_POTION));
        
        mvwaddstr(lw, row++, 4, "?  Scroll");
        
        mvwaddstr(lw, row++, 4, "/  Wand or Staff");
        
        mvwaddstr(lw, row++, 4, "=  Ring");
        
        wattron(lw, COLOR_PAIR(CP_ITEM_WEAPON));
        mvwaddstr(lw, row++, 4, ")  Weapon");
        wattroff(lw, COLOR_PAIR(CP_ITEM_WEAPON));
        
        wattron(lw, COLOR_PAIR(CP_ITEM_ARMOR));
        mvwaddstr(lw, row++, 4, "]  Armor");
        wattroff(lw, COLOR_PAIR(CP_ITEM_ARMOR));
        
        wattron(lw, COLOR_PAIR(CP_ITEM_GOLD));
        mvwaddstr(lw, row++, 4, "*  Gold");
        wattroff(lw, COLOR_PAIR(CP_ITEM_GOLD));
        
        mvwaddstr(lw, row++, 4, ",  Amulet/Miscellaneous");
        
        wattron(lw, COLOR_PAIR(CP_ITEM_FOOD));
        mvwaddstr(lw, row++, 4, ":  Food");
        wattroff(lw, COLOR_PAIR(CP_ITEM_FOOD));
    }
    else {
        mvwaddstr(lw, row++, 4, "!  Potion");
        mvwaddstr(lw, row++, 4, "?  Scroll");
        mvwaddstr(lw, row++, 4, "/  Wand or Staff");
        mvwaddstr(lw, row++, 4, "=  Ring");
        mvwaddstr(lw, row++, 4, ")  Weapon");
        mvwaddstr(lw, row++, 4, "]  Armor");
        mvwaddstr(lw, row++, 4, "*  Gold");
        mvwaddstr(lw, row++, 4, ",  Amulet/Miscellaneous");
        mvwaddstr(lw, row++, 4, ":  Food");
    }
    row++;
    
    /* Monsters - common examples */
    mvwaddstr(lw, row++, 2, "MONSTERS (examples):");
    mvwaddstr(lw, row++, 4, "A-Z  Various monsters (uppercase = more dangerous)");
    mvwaddstr(lw, row++, 4, "a-z  Various monsters (lowercase = less dangerous)");
    mvwaddstr(lw, row++, 4, "K  Kobold");
    mvwaddstr(lw, row++, 4, "O  Orc");
    mvwaddstr(lw, row++, 4, "D  Dragon");
    mvwaddstr(lw, row++, 4, "Z  Zombie");
    mvwaddstr(lw, row++, 4, "G  Ghost/Ghoul");
    
    /* Footer */
    mvwaddstr(lw, lines-2, 2, "Press any key to continue...");
    
    draw(lw);
    wgetch(lw);
    
    wclear(lw);
    delwin(lw);
    clearok(cw, TRUE);
    touchwin(cw);
}
