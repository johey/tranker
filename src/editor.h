#ifndef __EDITOR_H
#define __EDITOR_H

#include "configuration.h"

typedef struct {
    uint8_t y;
    uint8_t x;
} cursor_t;

void *event_cursor_up(void *cursor);
void *event_cursor_down(void *cursor);
void *event_cursor_left(void *cursor);
void *event_cursor_right(void *cursor);

#endif //__EDITOR_H

