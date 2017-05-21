#include "tranker.h"

#include <stdio.h>

void add_event(event_t *event_list, int *event_counter, event_t *event) {
	event_list[*event_counter] = *event;
	event_counter++;
}

void *print_fuck(void *data) {
	printf("%s\n", (char *)data);
	return NULL;
}

void run_events(event_t *event_list, int event_counter) {
	int i;
	for (i = 0; i < event_counter; i++) {
		event_list[i].event_function(event_list[i].data);
	}
}

