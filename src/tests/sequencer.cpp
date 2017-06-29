#include "../sequencer.c"

TEST(Sequencer, InitAndDestruct) {
    sequencer_t *sequencer = sequencer_init();

    ASSERT_EQ(0, sequencer->step_pointer);
    ASSERT_EQ(PATTERN_MAXLENGTH, sequencer->length);

    sequencer_destruct(sequencer);
}

TEST(Sequencer, NoteNames) {
    ASSERT_EQ("A", std::string(sequencer_get_note_name(0)));
    ASSERT_EQ("C", std::string(sequencer_get_note_name(3)));
    ASSERT_EQ("G#", std::string(sequencer_get_note_name(11)));
}

TEST(Sequencer, AddNotesToSequencerAndLoopIt) {
    sequencer_t *sequencer = sequencer_init();
    uint8_t clock_result;
    
    sequencer_set_note_at(sequencer, note_name("C"), 0);
    sequencer_set_note_at(sequencer, note_name("G#"), 15);

    for (int j = 0; j < 2; j++) {
        ASSERT_EQ(0, sequencer->step_pointer);
        ASSERT_EQ(note_name("C"), *sequencer_get_current_note(sequencer));

        for (int i = 0; i < 14; i++) {
            clock_result = sequencer_clock(sequencer);
            ASSERT_EQ(SEQUENCER_RUNNING, clock_result);
            ASSERT_EQ(NOTE_NONE, *sequencer_get_current_note(sequencer));
        }
        clock_result = sequencer_clock(sequencer);
        ASSERT_EQ(note_name("G#"), *sequencer_get_current_note(sequencer));
        ASSERT_EQ(SEQUENCER_ENDED, clock_result);

        clock_result = sequencer_clock(sequencer);
        ASSERT_EQ(SEQUENCER_RESTARTED, clock_result);
    }

    sequencer_destruct(sequencer);
}

TEST(Sequencer, SerializeAndDeserialize) {
    sequencer_t *sequencer = sequencer_init();
    
    sequencer_set_note_at(sequencer, note_name("C"), 0);
    sequencer_set_note_at(sequencer, note_name("G#"), 15);

    void *serialize = malloc(sizeof(*sequencer));
    memcpy(serialize, sequencer, sizeof(*sequencer));
    sequencer_destruct(sequencer);

    //ASSERT_EQ(NOTE_GS, *((uint8_t)serialize)[15]);

    free(serialize);

}

