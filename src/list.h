#ifndef __LIST_H
#define __LIST_H

#include "configuration.h"

typedef enum { active_null, active_prev, active_next } active_transfer;

typedef struct _node_t {
    void *data;
    struct _node_t *next;
    struct _node_t *prev;
} node_t;

typedef struct {
    node_t *first;
    node_t *last;
    node_t *active;
    uint8_t count;
} list_t;

#define list_iterate(l, t) for (node_t *node = l->first->next; node->next != NULL; node = node->next)

list_t *list_init();
void list_destruct(list_t *list);

void list_push_back(list_t *list, void *data, bool set_active);
node_t *list_remove_at(list_t *list, uint8_t pos, active_transfer transfer);
node_t *list_get_at(list_t *list, uint8_t pos);
uint8_t list_count(list_t *list);
void list_active_next(list_t *list);
void list_active_prev(list_t *list);

#endif //__LIST_H

