#include "../list.c"

TEST(List, GetAt) {
    list_t *list = list_init();
    EXPECT_EQ(NULL, list_get_at(list, 0));

    list_push_back(list, (char *)"1");
    list_push_back(list, (char *)"2");

    EXPECT_EQ("1", list_get_at(list, 0)->data);
    EXPECT_EQ("2", list_get_at(list, 1)->data);
    EXPECT_EQ(NULL, list_get_at(list, 2));

    free(list_remove_at(list, 0));
    free(list_remove_at(list, 0));

    list_destruct(list);
}

TEST(List, RemoveAt) {
    list_t *list = list_init();
    node_t *node;

    list_push_back(list, (char *)"1");
    list_push_back(list, (char *)"2");

    //EXPECT_EQ("1", list_remove_at(list, 0)->data);
    EXPECT_EQ("2", (node = list_remove_at(list, 1))->data);
    EXPECT_EQ(NULL, list_remove_at(list, 2));

    free(node);
    free(list_remove_at(list, 0));

    list_destruct(list);
}

TEST(List, AddRemoveAddElement) {
    list_t *list = list_init();
    node_t *node;
    int popped = 0;

    // Push 10
    for (int i = 0; i < 10; i++) {
        list_push_back(list, NULL);
    }

    // Pop 7
    for (int i = 0; i < 7; i++) {
        free(list_remove_at(list, 0));
    }

    // Push 3
    for (int i = 0; i < 3; i++) {
        list_push_back(list, NULL);
    }

    // Pop remaining
    while((node = list_remove_at(list, 0)) != NULL) {
        free(node);
        popped++;
    }
    list_destruct(list);

    // Should be 6 left
    EXPECT_EQ(6, popped);
}

TEST(List, Count) {
    list_t *list = list_init();

    ASSERT_EQ(0, list_count(list));

    list_push_back(list, NULL);

    ASSERT_EQ(1, list_count(list));

    list_push_back(list, NULL);
    list_push_back(list, NULL);

    ASSERT_EQ(3, list_count(list));

    free(list_remove_at(list, 0));
    free(list_remove_at(list, 0));

    ASSERT_EQ(1, list_count(list));

    free(list_remove_at(list, 0));

    list_destruct(list);
}

