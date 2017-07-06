#include "editor.h"
#include "list.h"

void *event_cursor_up(void *data) {
    api_t *api = (api_t *)data;
    api->cursor.y--;
    return NULL;
}

void *event_cursor_down(void *data) {
    api_t *api = (api_t *)data;
    api->cursor.y++;
    return NULL;
}

void *event_cursor_left(void *data) {
    api_t *api = (api_t *)data;
    api->cursor.x--;
    return NULL;
}

void *event_cursor_right(void *data) {
    api_t *api = (api_t *)data;
    api->cursor.x++;
    return NULL;
}

void *event_mode_insert(void *data) {
    api_t *api = (api_t *)data;
    api->mode = insert;
    return NULL;
}

void *event_mode_normal(void *data) {
    api_t *api = (api_t *)data;
    api->mode = normal;
    return NULL;
}

void *event_mode_ex(void *data) {
    api_t *api = (api_t *)data;
    api->mode = ex;
    return NULL;
}

/////////////////////////////////////////////////////////////////////////////////////

void editor_update_normal(api_t *api) {
    switch(api->key) {
        case TK_DOWN:   add_event(api->events, event_cursor_down, api); break;
        case TK_UP:     add_event(api->events, event_cursor_up, api); break;
        case TK_LEFT:   add_event(api->events, event_cursor_left, api); break;
        case TK_RIGHT:  add_event(api->events, event_cursor_right, api); break;
        case TK_i: add_event(api->events, event_mode_insert, api); break;
        case TK_EX:     add_event(api->events, event_mode_ex, api); break;
    }
}

void editor_update_insert(api_t *api) {
    switch(api->key) {
        case TK_ESC: add_event(api->events, event_mode_normal, api); break;
    }
}

void editor_update_ex(api_t *api) {
    switch(api->key) {
        case TK_ESC: add_event(api->events, event_mode_normal, api); break;
    }
}

void *editor_update(void *data) {
    api_t *api = (api_t *)data;
    switch(api->mode) {
        case normal: editor_update_normal(api); break;
        case insert: editor_update_insert(api); break;
        case ex: editor_update_ex(api); break;
    }
    return NULL;
}

void editor_singelton_init() {
    editor_singelton.update = editor_update;
}

