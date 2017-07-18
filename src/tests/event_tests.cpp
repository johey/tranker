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

TEST(Events, RunEventFunctions) {
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

    while((event = list_remove_at(g_events, 0, active_null)) != NULL) {
        free(event);
    }
    list_destruct(g_events);

    std::string expected = "1a2b1c2d1e2f1g2h1i2j";
    std::string actual = testing::internal::GetCapturedStdout();

    EXPECT_EQ(expected, actual);
}

TEST(Events, EmptyQueue) {
    list_t *list = list_init();
    EXPECT_EQ(list->first->next, list->last);
    EXPECT_EQ(list->last->prev, list->first);

    add_event(list, dummy, NULL);
    run_events(list, 0);

    EXPECT_EQ(list->first->next, list->last);
    EXPECT_EQ(list->last->prev, list->first);

    list_destruct(list);
}

TEST(Events, ReuseEventList) {
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

