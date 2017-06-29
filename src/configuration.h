#ifndef __CONFIGURATION_H
#define __CONFIGURATION_H

// Some special treatments for supporting gcc (for testing) and zcc for Z80.
#ifdef __GNUC__
#define FUNCPOINT(f,v) (*f)(v)
#else
#define FUNCPOINT(f,v) (*f)()
#endif

typedef unsigned char uint8_t;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Constants
#define PATTERN_MAXLENGTH 16

#endif

