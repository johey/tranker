#include "tranker.h"

#include <stdlib.h>

int main(int argc, char **argv) {
	int event_counter = 0;
	event_t *g_events = (event_t *)malloc(10 * sizeof(event_t));

	event_t my_event;
	my_event.event_function = print_fuck;
	my_event.data = (char *)"Warezmaster of the seven internets!";
	add_event(g_events, &event_counter, &my_event);
	event_counter++;

	event_t my_event2;
	my_event2.event_function = print_fuck;
	my_event2.data = (char *)"Mega!";
	add_event(g_events, &event_counter, &my_event2);
	event_counter++;

	run_events(g_events, event_counter);
	free(g_events);

	return 0;
}


