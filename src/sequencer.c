#include "sequencer.h"

note_t note_name_func(char *name) {
    note_t note;
    if (!(strcmp(name, "A")))  note = 0;
    else if (!(strcmp(name, "A#"))) note = 1;
    else if (!(strcmp(name, "B")))  note = 2;
    else if (!(strcmp(name, "C")))  note = 3;
    else if (!(strcmp(name, "C#"))) note = 4;
    else if (!(strcmp(name, "D")))  note = 5;
    else if (!(strcmp(name, "D#"))) note = 6;
    else if (!(strcmp(name, "E")))  note = 7;
    else if (!(strcmp(name, "F")))  note = 8;
    else if (!(strcmp(name, "F#"))) note = 9;
    else if (!(strcmp(name, "G")))  note = 10;
    else if (!(strcmp(name, "G#"))) note = 11;
    else note = NOTE_NONE;
    return note;
}

sequencer_t *sequencer_init() {
    sequencer_t *sequencer = (sequencer_t *)malloc(sizeof(sequencer_t));
    sequencer->length = PATTERN_MAXLENGTH;
    sequencer->step_pointer = 0;

    for (int i = 0; i < PATTERN_MAXLENGTH; i++)
        sequencer->note_array[i] = NOTE_NONE;

    return sequencer;
}

void sequencer_destruct(sequencer_t *sequencer) {
    free(sequencer);
}

void sequencer_set_note_at(sequencer_t *sequencer, note_t note, uint8_t position) {
    sequencer->note_array[position] = note;
}

note_t *sequencer_get_current_note(sequencer_t *sequencer) {
    return &(sequencer->note_array[sequencer->step_pointer]);
}

