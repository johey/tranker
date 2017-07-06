#ifndef __LIST_H
#define __LIST_H

#include "configuration.h"

typedef struct _node_t {
    void *data;
    struct _node_t *next;
    struct _node_t *prev;
} node_t;

typedef struct {
    node_t *first;
    node_t *last;
} list_t;

list_t *list_init();
void list_destruct(list_t *list);

void list_push_back(list_t *list, node_t *event);
node_t *list_remove_at(list_t *list, uint8_t pos);

#endif //__LIST_H

