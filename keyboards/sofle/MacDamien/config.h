// Copyright 2024 Santosh Kumar (@santosh)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once
/* The way how "handedness" is decided (which half is which),
see https://docs.qmk.fm/#/feature_split_keyboard?id=setting-handedness
for more options.
*/

// #define OLED_FONT_H "/Users/dv/qmk_firmware/keyboards/sofle/keymaps/MacDamien/glcdfont.c"
//#define USE_MATRIX_I2C

/* Select hand configuration */

///https://thomasbaart.nl/2018/12/01/reducing-firmware-size-in-qmk/

// #define MAGIC_SWAP_CONTROL_LGUI

#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

#define CUSTOM_FONT

// #define CUSTOM_LAYER_READ //if you remove this it causes issues - needs better guarding

#undef TAPPING_TERM
#define TAPPING_TERM 200
#define QUICK_TAP_TERM 120

// Toggle need this number of taps
#define TAPPING_TOGGLE 2

#define NO_MUSIC_MODE

#define WS2812_DI_PIN D3

// Auto Shift
#define NO_AUTO_SHIFT_ALPHA
#define AUTO_SHIFT_TIMEOUT TAPPING_TERM
#define AUTO_SHIFT_NO_SETUP

#define TRI_LAYER_LOWER_LAYER 3
#define TRI_LAYER_UPPER_LAYER 5
#define TRI_LAYER_ADJUST_LAYER 6

// To allow the use of QK_make in keymap.c
#define ENABLE_COMPILE_KEYCODE

// Eicoders (knobs)
#define ENCODER_MAP_ENABLE = yes
//
// #define ENCODERS_PAD_A { B12 }
// #define ENCODERS_PAD_B { B13 }
// Direction inversion
#define ENCODER_DIRECTION_FLIP
#ifdef ENCODER_RESOLUTION
    #undef ENCODER_RESOLUTION
#endif
