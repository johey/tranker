#ifndef __CLI_FUNCTIONS_H
#define __CLI_FUNCTIONS_H

#include <ncurses.h>
#include <unistd.h>

#include "singelton.h"
#include "editor.h"
#include "songdata.h"

#define SCREEN_WIDTH 32
#define SCREEN_HEIGHT 24

void generic_update(api_t *api);
void track_print(WINDOW *track, api_t *api);
//void tracks_print(songdata_t *songdata, api_t *api);
void draw(songdata_t *songdata, api_t *api);

void *event_add_track(void *data);
void *event_sync_track_windows(void *data);
void *event_update_cursor(void *data);

#endif //__CLI_FUNCTIONS_H

