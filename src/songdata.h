#ifndef __SONGDATA_H
#define __SONGDATA_H

#include <ncurses.h>

#include "list.h"
#include "track.h"
#include "frame.h"

typedef struct {
    list_t *tracks;
    track_t *active;
} songdata_t;

songdata_t *songdata_init();
void songdata_destruct(songdata_t *songdata);

void songdata_track_new_pushback(songdata_t *songdata);


#endif //__SONGDATA_H

