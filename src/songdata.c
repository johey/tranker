#include "songdata.h"

songdata_t *songdata_init() {
    songdata_t *songdata = (songdata_t *)malloc(sizeof(songdata_t));
    songdata->tracks = list_init();
    return songdata;
}

void songdata_destruct(songdata_t *songdata) {
    node_t *node;

    while ((node = list_remove_at(songdata->tracks, 0)) != NULL) {
        track_destruct((track_t *)node->data);
        free(node);
    }

    list_destruct(songdata->tracks);
    free(songdata);
}

void songdata_track_new_pushback(songdata_t *songdata) {
    track_t *track = track_init();
    node_t *node = (node_t *)malloc(sizeof(node_t));
    node->data = track;
    list_push_back(songdata->tracks, node);
}

