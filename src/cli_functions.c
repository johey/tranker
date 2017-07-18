#include "cli_functions.h"

void *event_add_track(void *data) {
    songdata_t *songdata = (songdata_t *)data;
    songdata_track_new_pushback(songdata);
    return NULL;
}

void *event_sync_track_windows(void *data) {
    api_t *api = (api_t *)data;
    songdata_t *songdata = api->songdata;

    for (node_t *node = songdata->tracks->first->next; node->next != NULL; node = node->next) {
        track_t *track = (track_t *)node->data;
        WINDOW *window;
        if (track->ui_element) continue;

        window = (WINDOW *)newwin(32, 10, 5, 10 * songdata->tracks->count);
        track->ui_element = (WINDOW *)window;
        scrollok(window, true);
        track_print(window, api);
    }

    return NULL;
}

void *event_update_cursor(void *data) {
    api_t *api = (api_t *)data;
    node_t *node = (node_t *)api->songdata->tracks->active;
    track_t *active;
    
    if (!node) return NULL;
    
    active = (track_t *)node->data;
    if (!active) return NULL;

    
    wmove((WINDOW *)active->ui_element, api->cursor.y, api->cursor.x);
    wrefresh((WINDOW *)active->ui_element);

    return NULL;
}

void generic_update(api_t *api) {
    switch(api->key) {
        case TK_F1: 
            add_event(api->events, event_add_track, (songdata_t *)api->songdata); 
            add_event(api->events, event_sync_track_windows, (api_t *)api);
            break;

        case TK_UP:
        case TK_DOWN:
        case TK_LEFT:
        case TK_RIGHT:
        case TK_TRACK_NEXT:
        case TK_TRACK_PREV:
            add_event(api->events, event_update_cursor, (api_t *)api);
            break;
    }
}

void track_print(WINDOW *track, api_t *api) {
    for (int i=0; i<32; i++) {
        mvwprintw(track, 31, 0, "%02x---", i);
        wscrl(track, 1);
    }
    wmove(track, api->cursor.y, api->cursor.x);
    wrefresh(track);
}

//void tracks_print(songdata_t *songdata, api_t *api) {
//    for (node_t *node = songdata->tracks->first->next; node->next != NULL; node = node->next) {
//        track_t *track = (track_t *)node->data;
//        WINDOW *window = track->ui_element;
//
//        for (int i=0; i<32; i++) {
//            mvwprintw(window, i, 0, "%02x---", i);
//        }
//        wmove(window, api->cursor.y, api->cursor.x);
//        wrefresh(window);
//    }
//}

void draw(songdata_t *songdata, api_t *api) {
}

