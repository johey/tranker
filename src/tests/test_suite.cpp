#include <gtest/gtest.h>
#include <iostream>

#include "list_tests.cpp"
#include "event_tests.cpp"
#include "pattern_tests.cpp"
#include "singelton.cpp"
#include "editor_test.cpp"
#include "songdata_tests.cpp"
#include "track_tests.cpp"
#include "frame_tests.cpp"
#include "cli_tests.cpp"

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


