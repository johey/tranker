#include "../event.c"

void *function1(void *data) {
    printf("1%s", (char *)data);
    return NULL;
}

void *function2(void *data) {
    printf("2%s", (char *)data);
    return NULL;
}

void *nop(void *data) {
    printf("nop ");
    return NULL;
}

void *dummy(void *data) {
    return NULL;
}

TEST(EventList, AddRemoveAddElement) {
    list_t *events = list_init();
    node_t *my_event;
    int popped = 0;

    // Push 10
    for (int i = 0; i < 10; i++) {
        my_event = (node_t *)malloc(sizeof(node_t));
        list_push(events, my_event);
    }

    // Pop 7
    for (int i = 0; i < 7; i++) {
        free(list_pop(events));
    }

    // Push 3
    for (int i = 0; i < 3; i++) {
        my_event = (node_t *)malloc(sizeof(node_t));
        list_push(events, my_event);
    }

    // Pop remaining
    while((my_event = list_pop(events)) != NULL) {
        free(my_event);
        popped++;
    }
    list_destruct(events);

    // Should be 6 left
    EXPECT_EQ(6, popped);
}

TEST(EventList, RunEventFunctions) {
    list_t *g_events = list_init();
    node_t *event;
    char *datastring;

    for (int i = 0; i < 10; i++) {
        datastring = (char *)malloc(2*sizeof(char));
        sprintf(datastring, "%c", 'a'+i);
        if (i % 2)
            add_event(g_events, function2, datastring);
        else
            add_event(g_events, function1, datastring);
    }

    testing::internal::CaptureStdout();
    run_events(g_events, 1);

    while((event = list_pop(g_events)) != NULL) {
        free(event);
    }
    list_destruct(g_events);

    std::string expected = "1a2b1c2d1e2f1g2h1i2j";
    std::string actual = testing::internal::GetCapturedStdout();

    EXPECT_EQ(expected, actual);
}

TEST(EventList, EmptyQueue) {
    list_t *list = list_init();
    EXPECT_EQ(list->first->next, list->last);
    EXPECT_EQ(list->last->prev, list->first);

    add_event(list, dummy, NULL);
    run_events(list, 0);

    EXPECT_EQ(list->first->next, list->last);
    EXPECT_EQ(list->last->prev, list->first);

    list_destruct(list);
}

TEST(EventList, ReuseEventList) {
    list_t *events = list_init();

    testing::internal::CaptureStdout();
    add_event(events, nop, NULL);
    run_events(events, 0);
    add_event(events, nop, NULL);
    run_events(events, 0);
    std::string actual = testing::internal::GetCapturedStdout();

    list_destruct(events);
    EXPECT_EQ("nop nop ", actual);
}

