#include "../track.c"

TEST(Track, InitAndDestruct) {
    track_t *track = track_init();

    ASSERT_EQ(0, track->step_pointer);
    ASSERT_EQ(PATTERN_MAXLENGTH, track->length);

    track_destruct(track);
}

TEST(Track, NoteNames) {
    ASSERT_EQ("A", std::string(track_get_note_name(0)));
    ASSERT_EQ("C", std::string(track_get_note_name(3)));
    ASSERT_EQ("G#", std::string(track_get_note_name(11)));
}

TEST(Track, AddNotesToTrackAndLoopIt) {
    track_t *track = track_init();
    uint8_t clock_result;

    track_set_note_at(track, note_name("C"), 0);
    track_set_note_at(track, note_name("G#"), 15);

    for (int j = 0; j < 2; j++) {
        ASSERT_EQ(0, track->step_pointer);
        ASSERT_EQ(note_name("C"), *track_get_current_note(track));

        for (int i = 0; i < 14; i++) {
            clock_result = track_clock(track);
            ASSERT_EQ(TRACK_RUNNING, clock_result);
            ASSERT_EQ(NOTE_NONE, *track_get_current_note(track));
        }
        clock_result = track_clock(track);
        ASSERT_EQ(note_name("G#"), *track_get_current_note(track));
        ASSERT_EQ(TRACK_ENDED, clock_result);

        clock_result = track_clock(track);
        ASSERT_EQ(TRACK_RESTARTED, clock_result);
    }

    track_destruct(track);
}

TEST(Track, SerializeAndDeserialize) {
    track_t *track = track_init();

    track_set_note_at(track, note_name("C"), 0);
    track_set_note_at(track, note_name("G#"), 15);

    void *serialize = malloc(sizeof(*track));
    memcpy(serialize, track, sizeof(*track));
    track_destruct(track);

    //ASSERT_EQ(NOTE_GS, *((uint8_t)serialize)[15]);

    free(serialize);

}

