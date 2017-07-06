#include "event.h"

void add_event(list_t *list, void *FUNCPOINT(function, void *data), void *data) {
    node_t *node = (node_t *)malloc(sizeof(node_t));
    event_t *event = (event_t *)malloc(sizeof(event_t));
    event->event_function = function;
    event->data = data;
    node->data = event;
    list_push_back(list, node);
}

void run_events(list_t *list, bool free_data) {
    node_t *node;
    event_t *event;
    while((node = list_remove_at(list, 0)) != NULL) {
        event = (event_t *)node->data;
        event->event_function(event->data);
        if (free_data) free(event->data);
        free(node->data);
        free(node);
    }
}

