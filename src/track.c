#include "track.h"

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

track_t *track_init() {
    uint8_t i;
    track_t *track = (track_t *)malloc(sizeof(track_t));
    track->length = PATTERN_MAXLENGTH;
    track->step_pointer = 0;

    for (i = 0; i < PATTERN_MAXLENGTH; i++)
        track->note_array[i] = NOTE_NONE;

    return track;
}

void track_destruct(track_t *track) {
    free(track);
}

void track_set_note_at(track_t *track, note_t note, uint8_t position) {
    track->note_array[position] = note;
}

note_t *track_get_current_note(track_t *track) {
    return &track->note_array[track->step_pointer];
}

uint8_t track_clock(track_t *track) {
    track->step_pointer++;

    if (PATTERN_MAXLENGTH == track->step_pointer) {
        track->step_pointer = 0;
        return TRACK_RESTARTED;
    }

    if ((PATTERN_MAXLENGTH - 1) == track->step_pointer) {
        return TRACK_ENDED;
    }

    return TRACK_RUNNING;
}

