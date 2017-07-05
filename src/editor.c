#include "editor.h"
#include "queue.h"

void *event_cursor_up(void *cursor) {
    ((cursor_t *)cursor)->y--;
    return (void *)NULL;
}

void *event_cursor_down(void *cursor) {
    ((cursor_t *)cursor)->y++;
    return (void *)NULL;
}

void *event_cursor_left(void *cursor) {
    ((cursor_t *)cursor)->x--;
    return (void *)NULL;
}

void *event_cursor_right(void *cursor) {
    ((cursor_t *)cursor)->x++;
    return (void *)NULL;
}

void *editor_update(void *data) {
    api_t *api = (api_t *)data;
    switch(api->key) {
        case TK_DOWN: add_event(api->events, event_cursor_down, &(api->cursor)); break;
        case TK_UP: add_event(api->events, event_cursor_up, &(api->cursor)); break;
        case TK_LEFT: add_event(api->events, event_cursor_left, &(api->cursor)); break;
        case TK_RIGHT: add_event(api->events, event_cursor_right, &(api->cursor)); break;
        //case TK_QUIT: add_event(api->events, event_quit, NULL); break;
        //case TK_CHORD: add_event(api->events, event_chordwindow, track); break;
    }
    return NULL;
}

void editor_singelton_init() {
    editor_singelton.update = editor_update;
}

