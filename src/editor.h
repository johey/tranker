#ifndef __EDITOR_H
#define __EDITOR_H

#include "configuration.h"
#include "singelton.h"
#include "event.h"
#include "songdata.h"

typedef enum { normal, insert, ex } editormode_t;

typedef struct {
    uint8_t y;
    uint8_t x;
} cursor_t;

typedef struct {
    unsigned char key;
    list_t *events;
    cursor_t cursor;
    editormode_t mode;
    songdata_t *songdata;
} api_t;

singelton_t editor_singelton;

void *event_cursor_up(void *data);
void *event_cursor_down(void *data);
void *event_cursor_left(void *data);
void *event_cursor_right(void *data);
void *event_track_next(void *data);
void *event_track_prev(void *data);

void *event_mode_insert(void *data);
void *event_mode_normal(void *data);
void *event_mode_ex(void *data);

void editor_update_normal(api_t *api);
void editor_update_insert(api_t *api);
void editor_update_ex(api_t *api);

void *editor_update(void *data);
void editor_singelton_init();

#endif //__EDITOR_H

