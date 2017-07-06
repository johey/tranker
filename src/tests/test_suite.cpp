#include <gtest/gtest.h>
#include <iostream>

#include "list_tests.cpp"
#include "event_tests.cpp"
#include "track.cpp"
#include "singelton.cpp"
#include "editor_test.cpp"

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


