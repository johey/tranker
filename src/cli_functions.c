#include "cli_functions.h"

void *event_add_track(void *data) {
    songdata_t *songdata = (songdata_t *)data;
    songdata_track_new_pushback(songdata);
    return NULL;
}

void *event_sync_track_windows(void *data) {
    songdata_t *songdata = (songdata_t *)data;

    for (node_t *node = songdata->tracks->first->next; node->next != NULL; node = node->next) {
        track_t *track = (track_t *)node->data;
        if (track->ui_element) continue;

        track->ui_element = (WINDOW *)newwin(32, 10, 5, 10 * songdata->tracks->count);
        track_print((WINDOW *)track->ui_element, 0, 0);
    }

    return NULL;
}

void generic_update(songdata_t *songdata, api_t *api) {
    switch(api->key) {
        case TK_F1: 
            add_event(api->events, event_add_track, (songdata_t *)songdata); 
            add_event(api->events, event_sync_track_windows, (songdata_t *)songdata);
            break;
    }

}

void track_print(WINDOW *track, int cursor_y, int cursor_x) {
    for (int i=0; i<32; i++) {
        mvwprintw(track, i, 0, "%02x---", i);
    }
    //wmove(track, cursor_y, cursor_x);
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

