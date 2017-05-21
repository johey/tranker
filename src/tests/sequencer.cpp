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

TEST(Sequencer, AddNotesToSequencer) {
    sequencer_t *sequencer = sequencer_init();
    
    sequencer_set_note_at(sequencer, note_name("C"), 0);
    sequencer_set_note_at(sequencer, note_name("G#"), 15);

    ASSERT_EQ(0, sequencer->step_pointer);
    ASSERT_EQ(note_name("C"), *sequencer_get_current_note(sequencer));

    sequencer_destruct(sequencer);
}

