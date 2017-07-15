#ifndef __FRAME_H
#define __FRAME_H

#include "pattern.h"

typedef struct {
    pattern_t *pattern;
    bool has_pattern;
    uint16_t length;
} frame_t;

frame_t *frame_init();
void frame_destruct(frame_t *frame);


#endif //__FRAME_H

