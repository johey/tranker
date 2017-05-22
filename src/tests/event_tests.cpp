#include "../tranker.c"

TEST(EventList, AddTwoElements) {
	uint8_t event_counter = 0;
	event_t *g_events = (event_t *)malloc(10 * sizeof(event_t));

	event_t my_event;
	my_event.event_function = print_fuck;
	my_event.data = (char *)"1";
	add_event(g_events, &event_counter, &my_event);
	event_counter++;

	event_t my_event2;
	my_event2.event_function = print_fuck;
	my_event2.data = (char *)"2";
	add_event(g_events, &event_counter, &my_event2);
	event_counter++;

	testing::internal::CaptureStdout();
	run_events(g_events, event_counter);
	free(g_events);

	std::string expected = "1\n2\n";
	std::string actual = testing::internal::GetCapturedStdout();

	EXPECT_EQ(expected, actual);
}

