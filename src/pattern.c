#include "pattern.h"

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

pattern_t *pattern_init() {
    uint8_t i;
    pattern_t *pattern = (pattern_t *)malloc(sizeof(pattern_t));
    pattern->length = PATTERN_MAXLENGTH;
    pattern->step_pointer = 0;

    for (i = 0; i < PATTERN_MAXLENGTH; i++)
        pattern->note_array[i] = NOTE_NONE;

    return pattern;
}

void pattern_destruct(pattern_t *pattern) {
    free(pattern);
}

void pattern_set_note_at(pattern_t *pattern, note_t note, uint8_t position) {
    pattern->note_array[position] = note;
}

note_t *pattern_get_current_note(pattern_t *pattern) {
    return &pattern->note_array[pattern->step_pointer];
}

uint8_t pattern_clock(pattern_t *pattern) {
    pattern->step_pointer++;

    if (PATTERN_MAXLENGTH == pattern->step_pointer) {
        pattern->step_pointer = 0;
        return PATTERN_RESTARTED;
    }

    if ((PATTERN_MAXLENGTH - 1) == pattern->step_pointer) {
        return PATTERN_ENDED;
    }

    return PATTERN_RUNNING;
}

/*
typedef struct {
    note_t note_array[PATTERN_MAXLENGTH];
    uint8_t length;
    uint8_t step_pointer;
} pattern_t;
char *pattern_serialize(pattern_t *pattern) {
    char 
}
*/

