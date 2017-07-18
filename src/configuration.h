#ifndef __CONFIGURATION_H
#define __CONFIGURATION_H

// Some special treatments for supporting gcc (for testing) and zcc for Z80.
#ifdef __GNUC__
#include <stdbool.h>
#define FUNCPOINT(f,v) (*f)(v)
#else
typedef enum {false=0, true=1} bool;
#define FUNCPOINT(f,v) (*f)()
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// Constants
#define PATTERN_MAXLENGTH 16

// Keys
#define TK_N0NE       0x00
#define TK_ESC        0x01
#define TK_UP         0x02
#define TK_DOWN       0x03
#define TK_RIGHT      0x04
#define TK_LEFT       0x05
#define TK_F1         0x06
#define TK_F2         0x07
#define TK_F3         0x08
#define TK_F4         0x09
#define TK_F5         0x0a
#define TK_F6         0x0b
#define TK_F7         0x0c
#define TK_F8         0x0d
#define TK_F9         0x0e
#define TK_F10        0x0f
#define TK_F11        0x10
#define TK_F12        0x11
#define TK_a          0x12
#define TK_b          0x13
#define TK_c          0x14
#define TK_d          0x15
#define TK_e          0x16
#define TK_f          0x17
#define TK_g          0x18
#define TK_h          0x19
#define TK_i          0x1a
#define TK_j          0x1b
#define TK_k          0x1c
#define TK_l          0x1d
#define TK_m          0x1e
#define TK_n          0x1f
#define TK_o          0x20
#define TK_p          0x21
#define TK_q          0x22
#define TK_r          0x23
#define TK_s          0x24
#define TK_t          0x25
#define TK_u          0x26
#define TK_v          0x27
#define TK_w          0x28
#define TK_x          0x29
#define TK_y          0x2a
#define TK_z          0x2b
#define TK_A          0x2c
#define TK_B          0x2d
#define TK_C          0x2e
#define TK_D          0x2f
#define TK_E          0x30
#define TK_F          0x31
#define TK_G          0x32
#define TK_H          0x33
#define TK_I          0x34
#define TK_J          0x35
#define TK_K          0x36
#define TK_L          0x37
#define TK_M          0x38
#define TK_N          0x39
#define TK_O          0x3a
#define TK_P          0x3b
#define TK_Q          0x3c
#define TK_R          0x3d
#define TK_S          0x3e
#define TK_T          0x3f
#define TK_U          0x40
#define TK_V          0x41
#define TK_W          0x42
#define TK_X          0x43
#define TK_Y          0x44
#define TK_Z          0x45
#define TK_0          0x46
#define TK_1          0x47
#define TK_2          0x48
#define TK_3          0x49
#define TK_4          0x4a
#define TK_5          0x4b
#define TK_6          0x4c
#define TK_7          0x4d
#define TK_8          0x4e
#define TK_9          0x4f
#define TK_COLON      0x50
#define TK_QUIT       0x51
#define TK_EX         0x52
#define TK_TRACK_NEXT 0x53
#define TK_TRACK_PREV 0x54


#endif

