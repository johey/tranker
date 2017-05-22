#ifndef __TRANKER_H
#define __TRANKER_H

#include "configuration.h"

typedef struct {
        void *FUNCPOINT(event_function, void *data);
	void *data;
} event_t;

void add_event(event_t *event_list, uint8_t *event_counter, event_t *event);
void run_events(event_t *event_list, uint8_t event_counter);

void *print_fuck(void *data);

#endif //__TRANKER_H

