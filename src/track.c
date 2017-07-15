#include "track.h"

track_t *track_init() {
    track_t *track = (track_t *)malloc(sizeof(track_t));
    track->frames = list_init();
    return track;
}

void track_destruct(track_t *track) {
    list_destruct(track->frames);
    free(track);
}

