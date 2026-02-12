/*
    display.c - Helper functions for colored display
    
    XRogue: Expeditions into the Dungeons of Doom
*/

#include <curses.h>
#include "rogue.h"

/*
 * draw_monster:
 *      Draw a monster with appropriate color
 */
void
draw_monster(tp, y, x)
struct thing *tp;
int y, x;
{
    int color = get_monster_color(tp);
    
    if (color > 0) {
        wattron(cw, COLOR_PAIR(color));
        mvwaddch(cw, y, x, tp->t_type);
        wattroff(cw, COLOR_PAIR(color));
    }
    else {
        mvwaddch(cw, y, x, tp->t_type);
    }
}

/*
 * draw_item:
 *      Draw an item with appropriate color
 */
void
draw_item(obj, y, x)
struct object *obj;
int y, x;
{
    int color = get_item_color(obj);
    
    if (color > 0) {
        wattron(cw, COLOR_PAIR(color));
        mvwaddch(cw, y, x, obj->o_type);
        wattroff(cw, COLOR_PAIR(color));
    }
    else {
        mvwaddch(cw, y, x, obj->o_type);
    }
}

/*
 * draw_char_colored:
 *      Draw a character with a specific color pair
 */
void
draw_char_colored(win, y, x, ch, color_pair)
WINDOW *win;
int y, x;
char ch;
int color_pair;
{
    if (color_pair > 0) {
        wattron(win, COLOR_PAIR(color_pair));
        mvwaddch(win, y, x, ch);
        wattroff(win, COLOR_PAIR(color_pair));
    }
    else {
        mvwaddch(win, y, x, ch);
    }
}
