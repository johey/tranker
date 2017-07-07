#ifndef __TRACK_H
#define __TRACK_H

typedef struct {
    list_t *patterns;
} track_t;

track_t *track_init();
void track_destruct(track_t *track);


#endif //__TRACK_H

