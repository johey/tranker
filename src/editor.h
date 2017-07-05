#ifndef __EDITOR_H
#define __EDITOR_H

#include "configuration.h"
#include "singelton.h"
#include "queue.h"

typedef struct {
    uint8_t y;
    uint8_t x;
} cursor_t;

typedef struct {
    unsigned char key;
    queue_t *events;
    cursor_t cursor;
} api_t;

singelton_t editor_singelton;

void *event_cursor_up(void *cursor);
void *event_cursor_down(void *cursor);
void *event_cursor_left(void *cursor);
void *event_cursor_right(void *cursor);

void *editor_update(void *data);
void editor_singelton_init();

#endif //__EDITOR_H

