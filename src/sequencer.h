#ifndef __SEQUENCER_H
#define __SEQUENCER_H

#include "configuration.h"

// Macros
#define NOTE_NAMES "A\0\0A#\0B\0\0C\0\0C#\0D\0\0D#\0E\0\0F\0\0F#\0G\0\0G#"
#define sequencer_get_note_name(x) (char *)(&NOTE_NAMES[3 * x])
#define note_name(x) note_name_func((char *)x)

#define NOTE_A  0
#define NOTE_AS 1
#define NOTE_B  2
#define NOTE_C  3
#define NOTE_CS 4
#define NOTE_D  5
#define NOTE_DS 6
#define NOTE_E  7
#define NOTE_F  8
#define NOTE_FS 9
#define NOTE_G  10
#define NOTE_GS 11

#define NOTE_NONE 0xff

typedef uint8_t note_t;

typedef struct {
    note_t note_array[PATTERN_MAXLENGTH];
    uint8_t length;
    uint8_t step_pointer;
} sequencer_t;


// Note functions
note_t note_name_func(char *name);

// Sequencer functions
sequencer_t *sequencer_init();
void sequencer_destruct(sequencer_t *sequencer);
void sequencer_set_note_at(sequencer_t *sequencer, note_t note, uint8_t position);
note_t *sequencer_get_current_note(sequencer_t *sequencer);

/**
 * Send a clock pulse to the sequencer, stepping it forward one step.
 * @return Non-zero if last step, zero otherwise.
 */
uint8_t sequencer_clock();

#endif

