#ifndef __CONFIGURATION_H
#define __CONFIGURATION_H

#ifdef __GNUC__
#define FUNCPOINT(f,v) (*f)(v)
#else
#define FUNCPOINT(f,v) (*f)()
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants
#define PATTERN_MAXLENGTH 16

// Types
typedef unsigned char uint8_t;

#endif

