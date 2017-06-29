#include "../queue.c"

void *function1(void *data) {
    printf("1%s", (char *)data);
    return NULL;
}

void *function2(void *data) {
    printf("2%s", (char *)data);
    return NULL;
}

TEST(EventList, AddRemoveAddElement) {
    queue_t *events = queue_init();
    node_t *my_event;
    int popped = 0;

    // Push 10
    for (int i = 0; i < 10; i++) {
        my_event = (node_t *)malloc(sizeof(node_t));
        queue_push(events, my_event);
    }

    // Pop 7
    for (int i = 0; i < 7; i++) {
        free(queue_pop(events));
    }

    // Push 3
    for (int i = 0; i < 3; i++) {
        my_event = (node_t *)malloc(sizeof(node_t));
        queue_push(events, my_event);
    }

    // Pop remaining
    while((my_event = queue_pop(events)) != NULL) {
        free(my_event);
        popped++;
    }
    queue_destruct(events);

    // Should be 6 left
    EXPECT_EQ(6, popped);
}

TEST(EventList, RunEventFunctions) {
    queue_t *g_events = queue_init();

    for (int i = 0; i < 10; i++) {
        node_t *my_event = (node_t *)malloc(sizeof(node_t));
        char *datastring = (char *)malloc(2*sizeof(char));
        my_event->event_function = function1;
        if (i % 2)
            my_event->event_function = function2;
        sprintf(datastring, "%c", 'a'+i);
        my_event->data = datastring;
        queue_push(g_events, my_event);
    }

    testing::internal::CaptureStdout();
    run_events(g_events);

    queue_destruct(g_events);

    std::string expected = "1a2b1c2d1e2f1g2h1i2j";
    std::string actual = testing::internal::GetCapturedStdout();

    EXPECT_EQ(expected, actual);
}

