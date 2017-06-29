#include <gtest/gtest.h>
#include <iostream>

#include "event_tests.cpp"
#include "sequencer.cpp"

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


