#ifndef __TRACK_H
#define __TRACK_H

#include "list.h"

typedef struct {
    list_t *frames;
} track_t;

track_t *track_init();
void track_destruct(track_t *track);


#endif //__TRACK_H

