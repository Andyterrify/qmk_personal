/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

/* Select hand configuration */

// #define MASTER_LEFT
#define MASTER_RIGHT
// #define EE_HANDS

// #ifdef RGBLIGHT_ENABLE
// #    define RGBLIGHT_EFFECT_BREATHING
// #    define RGBLIGHT_EFFECT_RAINBOW_MOOD
// #    define RGBLIGHT_EFFECT_RAINBOW_SWIRL
// #    define RGBLIGHT_EFFECT_SNAKE
// #    define RGBLIGHT_EFFECT_KNIGHT
// #    define RGBLIGHT_EFFECT_CHRISTMAS
// #    define RGBLIGHT_EFFECT_STATIC_GRADIENT
// //  #define RGBLIGHT_EFFECT_RGB_TEST
// //  #define RGBLIGHT_EFFECT_ALTERNATING
// //  #define RGBLIGHT_EFFECT_TWINKLE
// #    define RGBLIGHT_LIMIT_VAL 120
// #    define RGBLIGHT_HUE_STEP 10
// #    define RGBLIGHT_SAT_STEP 17
// #    define RGBLIGHT_VAL_STEP 17
// #endif

#define RGB_MATRIX_TYPING_HEATMAP_DECREASE_DELAY_MS 50
#define RGB_MATRIX_TYPING_HEATMAP_SPREAD 80
#define RGB_MATRIX_TIMEOUT 60000
#define RGB_MATRIX_SLEEP
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 200
#define SPLIT_TRANSPORT_MIRROR
#define RGBLIGHT_HUE_STEP 10
#define RGBLIGHT_SAT_STEP 17
#define RGBLIGHT_VAL_STEP 17
#define RGB_MATRIX_DISABLE_SHARED_KEYCODES

#define OLED_FONT_H "keyboards/crkbd/lib/glcdfont.c"

#define TRI_LAYER_LOWER_LAYER 2
#define TRI_LAYER_RAISE_LAYER 3
#define TRI_LAYER_ADJUST_LAYER 5

#define CAPS_WORD_INVERT_ON_SHIFT
#define CAPS_WORD_IDLE_TIMEOUT 3000  // 3 seconds.

#define TAPPING_TERM 130
#define USB_POLLING_INTERVAL_MS 1

