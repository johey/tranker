#ifndef __SONGDATA_H
#define __SONGDATA_H

#include "list.h"
#include "track.h"

typedef struct {
    list_t *tracks;
} songdata_t;

songdata_t *songdata_init();
void songdata_destruct(songdata_t *songdata);

void songdata_track_new_pushback(songdata_t *songdata);
track_t *songdata_track_getat(songdata_t *songdata, uint8_t pos);


#endif //__SONGDATA_H

