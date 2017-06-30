#include "queue.h"

#include <stdio.h>

queue_t *queue_init() {
    queue_t *queue = (queue_t *)malloc(sizeof(queue_t));
    node_t *first = (node_t *)malloc(sizeof(node_t));
    node_t *last = (node_t *)malloc(sizeof(node_t));
    first->next = last;
    last->prev = first;
    first->prev = NULL;
    last->next = NULL;
    queue->first = first;
    queue->last = last;

    return queue;
}

void queue_destruct(queue_t *queue) {
    free(queue->first);
    free(queue->last);
    queue->first = queue->last = NULL;
    free(queue);
}

// Push last in queue
void queue_push(queue_t *queue, node_t *node) {
    node->prev = queue->last->prev;
    node->next = queue->last;
    queue->last->prev->next = node;
    queue->last->prev = node;
}

// Pop first in queue
node_t *queue_pop(queue_t *queue) {
    node_t *node;
    if (queue->first->next == queue->last) return NULL;
    node = queue->first->next;
    queue->first->next = node->next;
    queue->first->next->prev = queue->first;
    return node;
}

void add_event(queue_t *queue, void *FUNCPOINT(function, void *data), void *data) {
    node_t *event = (node_t *)malloc(sizeof(node_t));
    event->event_function = function;
    event->data = data;
    queue_push(queue, event);
}

void run_events(queue_t *queue) {
    node_t *node;
    while((node = queue_pop(queue)) != NULL) {
        node->event_function(node->data);
        //free(node->data);
        free(node);
    }
}

