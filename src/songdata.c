#include "songdata.h"

songdata_t *songdata_init() {
    songdata_t *songdata = (songdata_t *)malloc(sizeof(songdata_t));
    songdata->tracks = list_init();
    return songdata;
}

void songdata_destruct(songdata_t *songdata) {
    list_destruct(songdata->tracks);
    free(songdata);
}

void songdata_track_pushback(songdata_t *songdata, track_t *track) {
    node_t *node = (node_t *)malloc(sizeof(node_t));
    node->data = track;
    list_push_back(songdata->tracks, node);
}

track_t *songdata_track_getat(songdata_t *songdata, uint8_t pos) {
    node_t *node;
    node = list_get_at(songdata->tracks, 0);
    if (node == NULL) return NULL;
    return (track_t *)node->data;
}

