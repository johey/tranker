#ifndef __PATTERN_H
#define __PATTERN_H

#include "configuration.h"
#include "list.h"

// Macros
#define NOTE_NAMES "A\0\0A#\0B\0\0C\0\0C#\0D\0\0D#\0E\0\0F\0\0F#\0G\0\0G#"
#define pattern_get_note_name(x) (char *)(&NOTE_NAMES[3 * x])
#define note_name(x) note_name_func((char *)x)

#define NOTE_A            0x00
#define NOTE_AS           0x01
#define NOTE_B            0x02
#define NOTE_C            0x03
#define NOTE_CS           0x04
#define NOTE_D            0x05
#define NOTE_DS           0x06
#define NOTE_E            0x07
#define NOTE_F            0x08
#define NOTE_FS           0x09
#define NOTE_G            0x0a
#define NOTE_GS           0x0b
#define NOTE_NONE         0xff

#define PATTERN_ENDED     0xff
#define PATTERN_RUNNING   0x00
#define PATTERN_RESTARTED 0x01

typedef uint8_t note_t;

typedef struct {
    note_t note_array[PATTERN_MAXLENGTH];
    list_t *notes;
    uint8_t length;
    uint8_t step_pointer;
} pattern_t;


// Note functions
note_t note_name_func(char *name);

// Sequencer functions
pattern_t *pattern_init();
void pattern_destruct(pattern_t *pattern);
void pattern_set_note_at(pattern_t *pattern, note_t note, uint8_t position);
note_t *pattern_get_current_note(pattern_t *pattern);

char *pattern_serialize(pattern_t *pattern);

/**
 * Send a clock pulse to the pattern, stepping it forward one step.
 * @return Non-zero if last step, zero otherwise.
 */
uint8_t pattern_clock();

#endif

