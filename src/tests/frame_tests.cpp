#include "../frame.c"

TEST(Frame, Init) {
    frame_t *frame = frame_init();
    ASSERT_EQ(false, frame->has_pattern);
    ASSERT_EQ(0, frame->length);
    frame_destruct(frame);
}

TEST(Frame, SetPattern) {
    frame_t *frame = frame_init();
    pattern_t *pattern = pattern_init();
    frame->pattern = pattern;
    pattern_destruct(pattern);
    frame_destruct(frame);
}

