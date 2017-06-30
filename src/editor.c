#include "editor.h"

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


