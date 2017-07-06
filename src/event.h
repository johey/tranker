#ifndef __EVENT_H
#define __EVENT_H

#include "list.h"

typedef struct {
    void *FUNCPOINT(event_function, void *data);
    void *data;
} event_t;

void add_event(list_t *list, void *FUNCPOINT(function, void *data), void *data);
void run_events(list_t *list, bool free_data);


#endif //__EVENT_H


