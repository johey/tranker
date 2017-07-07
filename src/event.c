#include "event.h"

void add_event(list_t *list, void *FUNCPOINT(function, void *data), void *data) {
    event_t *event = (event_t *)malloc(sizeof(event_t));
    event->event_function = function;
    event->data = data;
    list_push_back(list, event);
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

