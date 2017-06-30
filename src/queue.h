#ifndef __QUEUE_H
#define __QUEUE_H

#include "configuration.h"

typedef struct _node_t {
    void *FUNCPOINT(event_function, void *data);
    void *data;
    struct _node_t *next;
    struct _node_t *prev;
} node_t;

typedef struct {
    node_t *first;
    node_t *last;
} queue_t;

queue_t *queue_init();
void queue_destruct(queue_t *queue);

void queue_push(queue_t *queue, node_t *event);
node_t *queue_pop(queue_t *queue);

void add_event(queue_t *queue, void *FUNCPOINT(function, void *data), void *data);
void run_events(queue_t *queue);

#endif //__QUEUE_H

