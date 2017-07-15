#include "frame.h"

frame_t *frame_init() {
    frame_t *frame = (frame_t *)malloc(sizeof(frame_t));
    frame->has_pattern = false;
    frame->length = 0;
    return frame;
}

void frame_destruct(frame_t *frame) {
    free(frame);
}

