#ifndef __TRANKER_H
#define __TRANKER_H

typedef struct {
	void *(*event_function)(void *data);
	void *data;
} event_t;

void add_event(event_t *event_list, int *event_counter, event_t *event);
void run_events(event_t *event_list, int event_counter);

void *print_fuck(void *data);

#endif //__TRANKER_H

