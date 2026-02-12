/*
    sidebar.c - Sidebar panel for XRogue
    
    Displays nearby objects, monsters, and combat log in a sidebar panel
*/

#include <curses.h>
#include <string.h>
#include "rogue.h"

#define SIDEBAR_WIDTH 26
#define MAX_COMBAT_LOG 8

/* Combat log circular buffer */
static char combat_log[MAX_COMBAT_LOG][80];
static int combat_log_pos = 0;
static int combat_log_count = 0;

/*
 * add_combat_log:
 *      Add a message to the combat log
 */
void
add_combat_log(msg)
char *msg;
{
    strncpy(combat_log[combat_log_pos], msg, 79);
    combat_log[combat_log_pos][79] = '\0';
    combat_log_pos = (combat_log_pos + 1) % MAX_COMBAT_LOG;
    if (combat_log_count < MAX_COMBAT_LOG)
        combat_log_count++;
}

/*
 * update_sidebar:
 *      Refresh the sidebar with current information
 */
void
update_sidebar()
{
    int y, x, i, log_start;
    struct linked_list *item;
    struct thing *tp;
    struct object *obj;
    char buf[SIDEBAR_WIDTH];
    int line = 1;
    
    if (sidew == NULL) return;
    
    wclear(sidew);
    box(sidew, 0, 0);
    
    /* Title */
    mvwaddstr(sidew, 0, 2, "[ Nearby ]");
    
    /* Check all 8 adjacent squares */
    for (y = hero.y - 1; y <= hero.y + 1; y++) {
        for (x = hero.x - 1; x <= hero.x + 1; x++) {
            if (y == hero.y && x == hero.x) continue;
            if (y < 0 || y >= lines-3 || x < 0 || x >= cols-SIDEBAR_WIDTH)
                continue;
            
            /* Check for monsters */
            if ((item = find_mons(y, x)) != NULL) {
                tp = THINGPTR(item);
                if (line < lines - MAX_COMBAT_LOG - 5) {
                    char dir[3];
                    int hp_pct;
                    
                    /* Determine direction */
                    if (y < hero.y) strcpy(dir, "N");
                    else if (y > hero.y) strcpy(dir, "S");
                    else strcpy(dir, "");
                    if (x < hero.x) strcat(dir, "W");
                    else if (x > hero.x) strcat(dir, "E");
                    
                    /* Calculate HP percentage */
                    hp_pct = (tp->t_stats.s_hpt * 100) / tp->maxstats.s_hpt;
                    
                    snprintf(buf, SIDEBAR_WIDTH-2, "%2s:%-12s %3d%%",
                        dir, monster_name(tp), hp_pct);
                    buf[SIDEBAR_WIDTH-3] = '\0';
                    
                    wattron(sidew, get_monster_color(tp));
                    mvwaddstr(sidew, line++, 1, buf);
                    wattroff(sidew, get_monster_color(tp));
                }
            }
            
            /* Check for objects */
            if ((item = find_obj(y, x)) != NULL) {
                obj = OBJPTR(item);
                if (line < lines - MAX_COMBAT_LOG - 5) {
                    char dir[3];
                    char *name;
                    
                    /* Determine direction */
                    if (y < hero.y) strcpy(dir, "N");
                    else if (y > hero.y) strcpy(dir, "S");
                    else strcpy(dir, "");
                    if (x < hero.x) strcat(dir, "W");
                    else if (x > hero.x) strcat(dir, "E");
                    
                    name = inv_name(obj, FALSE);
                    snprintf(buf, SIDEBAR_WIDTH-2, "%2s:%-18s", dir, name);
                    buf[SIDEBAR_WIDTH-3] = '\0';
                    
                    wattron(sidew, get_item_color(obj));
                    mvwaddstr(sidew, line++, 1, buf);
                    wattroff(sidew, get_item_color(obj));
                }
            }
        }
    }
    
    /* Combat log section */
    if (line < lines - MAX_COMBAT_LOG - 2) {
        mvwaddch(sidew, line++, 0, ACS_LTEE);
        mvwhline(sidew, line-1, 1, ACS_HLINE, SIDEBAR_WIDTH-2);
        mvwaddch(sidew, line-1, SIDEBAR_WIDTH-1, ACS_RTEE);
        mvwaddstr(sidew, line-1, 2, "[ Combat ]");
    }
    
    /* Display combat log (most recent at bottom) */
    log_start = (combat_log_pos - combat_log_count + MAX_COMBAT_LOG) % MAX_COMBAT_LOG;
    for (i = 0; i < combat_log_count && line < lines - 3; i++) {
        int idx = (log_start + i) % MAX_COMBAT_LOG;
        strncpy(buf, combat_log[idx], SIDEBAR_WIDTH-3);
        buf[SIDEBAR_WIDTH-3] = '\0';
        mvwaddstr(sidew, line++, 1, buf);
    }
    
    wrefresh(sidew);
}
