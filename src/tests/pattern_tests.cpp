#include "../pattern.c"

TEST(Pattern, InitAndDestruct) {
    pattern_t *pattern = pattern_init();

    ASSERT_EQ(0, pattern->step_pointer);
    ASSERT_EQ(PATTERN_MAXLENGTH, pattern->length);

    pattern_destruct(pattern);
}

TEST(Pattern, NoteNames) {
    ASSERT_EQ("A", std::string(pattern_get_note_name(0)));
    ASSERT_EQ("C", std::string(pattern_get_note_name(3)));
    ASSERT_EQ("G#", std::string(pattern_get_note_name(11)));
}

TEST(Pattern, AddNotesToPatternAndLoopIt) {
    pattern_t *pattern = pattern_init();
    uint8_t clock_result;

    pattern_set_note_at(pattern, note_name("C"), 0);
    pattern_set_note_at(pattern, note_name("G#"), 15);

    for (int j = 0; j < 2; j++) {
        ASSERT_EQ(0, pattern->step_pointer);
        ASSERT_EQ(note_name("C"), *pattern_get_current_note(pattern));

        for (int i = 0; i < 14; i++) {
            clock_result = pattern_clock(pattern);
            ASSERT_EQ(PATTERN_RUNNING, clock_result);
            ASSERT_EQ(NOTE_NONE, *pattern_get_current_note(pattern));
        }
        clock_result = pattern_clock(pattern);
        ASSERT_EQ(note_name("G#"), *pattern_get_current_note(pattern));
        ASSERT_EQ(PATTERN_ENDED, clock_result);

        clock_result = pattern_clock(pattern);
        ASSERT_EQ(PATTERN_RESTARTED, clock_result);
    }

    pattern_destruct(pattern);
}

//TODO
TEST(Pattern, SerializeAndDeserialize) {
    pattern_t *pattern = pattern_init();

    pattern_set_note_at(pattern, note_name("C"), 0);
    pattern_set_note_at(pattern, note_name("G#"), 15);

    void *serialize = malloc(sizeof(*pattern));
    memcpy(serialize, pattern, sizeof(*pattern));
    pattern_destruct(pattern);

    //ASSERT_EQ(NOTE_GS, *((uint8_t)serialize)[15]);

    free(serialize);

}

