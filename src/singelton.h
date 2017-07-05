#ifndef __SINGELTON_H
#define __SINGELTON_H

#include "configuration.h"

typedef struct {
    void *FUNCPOINT(update, void *data);
} singelton_t;

singelton_t *active;

#endif //__SINGELTON_H

