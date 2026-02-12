/*
    colors.c - Color support for XRogue
    
    Handles initialization and management of color pairs for
    items, monsters, and UI elements.
*/

#include <curses.h>
#include "rogue.h"

/* Color pair definitions */
#define CP_NORMAL       1
#define CP_MONSTER_HOSTILE  2
#define CP_MONSTER_FRIENDLY 3
#define CP_MONSTER_NEUTRAL  4
#define CP_MONSTER_UNIQUE   5
#define CP_ITEM_WEAPON  6
#define CP_ITEM_ARMOR   7
#define CP_ITEM_GOLD    8
#define CP_ITEM_FOOD    9
#define CP_ITEM_POTION  10
#define CP_ITEM_SCROLL  11
#define CP_ITEM_RING    12
#define CP_ITEM_STICK   13
#define CP_ITEM_MISC    14
#define CP_COMBAT_HIT   15
#define CP_COMBAT_MISS  16
#define CP_HEALTH_GOOD  17
#define CP_HEALTH_WARN  18
#define CP_HEALTH_CRIT  19

bool color_support = FALSE;

/*
 * init_color_pairs:
 *      Initialize color pairs for the game
 */
void
init_color_pairs()
{
    if (!has_colors()) {
        color_support = FALSE;
        return;
    }
    
    start_color();
    color_support = TRUE;
    
    /* Monster colors */
    init_pair(CP_MONSTER_HOSTILE, COLOR_RED, COLOR_BLACK);
    init_pair(CP_MONSTER_FRIENDLY, COLOR_GREEN, COLOR_BLACK);
    init_pair(CP_MONSTER_NEUTRAL, COLOR_YELLOW, COLOR_BLACK);
    init_pair(CP_MONSTER_UNIQUE, COLOR_MAGENTA, COLOR_BLACK);
    
    /* Item colors */
    init_pair(CP_ITEM_WEAPON, COLOR_CYAN, COLOR_BLACK);
    init_pair(CP_ITEM_ARMOR, COLOR_BLUE, COLOR_BLACK);
    init_pair(CP_ITEM_GOLD, COLOR_YELLOW, COLOR_BLACK);
    init_pair(CP_ITEM_FOOD, COLOR_GREEN, COLOR_BLACK);
    init_pair(CP_ITEM_POTION, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(CP_ITEM_SCROLL, COLOR_WHITE, COLOR_BLACK);
    init_pair(CP_ITEM_RING, COLOR_CYAN, COLOR_BLACK);
    init_pair(CP_ITEM_STICK, COLOR_YELLOW, COLOR_BLACK);
    init_pair(CP_ITEM_MISC, COLOR_WHITE, COLOR_BLACK);
    
    /* Combat colors */
    init_pair(CP_COMBAT_HIT, COLOR_GREEN, COLOR_BLACK);
    init_pair(CP_COMBAT_MISS, COLOR_YELLOW, COLOR_BLACK);
    
    /* Health colors */
    init_pair(CP_HEALTH_GOOD, COLOR_GREEN, COLOR_BLACK);
    init_pair(CP_HEALTH_WARN, COLOR_YELLOW, COLOR_BLACK);
    init_pair(CP_HEALTH_CRIT, COLOR_RED, COLOR_BLACK);
    
    init_pair(CP_NORMAL, COLOR_WHITE, COLOR_BLACK);
}

/*
 * get_monster_color:
 *      Return appropriate color pair for a monster
 */
int
get_monster_color(tp)
struct thing *tp;
{
    if (!color_support) return 0;
    
    /* Unique/boss monsters */
    if (on(*tp, ISUNIQUE))
        return COLOR_PAIR(CP_MONSTER_UNIQUE);
    
    /* Friendly monsters */
    if (on(*tp, ISFRIENDLY))
        return COLOR_PAIR(CP_MONSTER_FRIENDLY);
    
    /* Hostile monsters (default) */
    return COLOR_PAIR(CP_MONSTER_HOSTILE);
}

/*
 * get_item_color:
 *      Return appropriate color pair for an item
 */
int
get_item_color(obj)
struct object *obj;
{
    if (!color_support) return 0;
    
    switch (obj->o_type) {
        case WEAPON:
            return COLOR_PAIR(CP_ITEM_WEAPON);
        case ARMOR:
            return COLOR_PAIR(CP_ITEM_ARMOR);
        case GOLD:
            return COLOR_PAIR(CP_ITEM_GOLD);
        case FOOD:
            return COLOR_PAIR(CP_ITEM_FOOD);
        case POTION:
            return COLOR_PAIR(CP_ITEM_POTION);
        case SCROLL:
            return COLOR_PAIR(CP_ITEM_SCROLL);
        case RING:
            return COLOR_PAIR(CP_ITEM_RING);
        case STICK:
            return COLOR_PAIR(CP_ITEM_STICK);
        case MM:
            return COLOR_PAIR(CP_ITEM_MISC);
        case RELIC:
            return COLOR_PAIR(CP_MONSTER_UNIQUE);
        default:
            return COLOR_PAIR(CP_NORMAL);
    }
}

/*
 * get_health_color:
 *      Return color based on health percentage
 */
int
get_health_color(current, maximum)
int current, maximum;
{
    int percent;
    
    if (!color_support || maximum == 0) return 0;
    
    percent = (current * 100) / maximum;
    
    if (percent > 66)
        return COLOR_PAIR(CP_HEALTH_GOOD);
    else if (percent > 33)
        return COLOR_PAIR(CP_HEALTH_WARN);
    else
        return COLOR_PAIR(CP_HEALTH_CRIT);
}
