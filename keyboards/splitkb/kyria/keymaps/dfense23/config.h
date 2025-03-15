/* Copyright 2022 Thomas Baart <thomas@splitkb.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/*
* #define CIRQUE_PINNACLE_POSITION_MODE CIRQUE_PINNACLE_ABSOLUTE_MODE
*/

#pragma once
#define TAPPING_TERM 200
#define PERMISSIVE_HOLD_PER_KEY
#define MASTER_LEFT
#define POINTING_DEVICE_RIGHT
#define POINTING_DEVICE_ROTATION_90
#define SPLIT_POINTING_ENABLE
#define TAPPING_TOGGLE 2

//#define CIRQUE_PINNACLE_TAP_ENABLE
//#define CIRQUE_PINNACLE_SECONDARY_TAP_ENABLE
#define POINTING_DEVICE_GESTURES_SCROLL_ENABLE
#define POINTING_DEVICE_GESTURES_CURSOR_GLIDE_ENABLE

#define POINTING_DEVICE_AUTO_MOUSE_ENABLE
// only required if not setting mouse layer elsewhere
#define AUTO_MOUSE_DEFAULT_LAYER 7

// RGB Definitions
#define RGBLIGHT_ENABLE
#define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_STATIC_LIGHT
#define RGB_MATRIX_DISABLE_SHARED_KEYCODES
#define RGBLIGHT_SPLIT

#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 8

// enable modes
#define RGBLIGHT_EFFECT_BREATHING
#define RGBLIGHT_EFFECT_ALTERNATING
#define RGBLIGHT_EFFECT_CHRISTMAS
#define RGBLIGHT_EFFECT_KNIGHT
#define RGBLIGHT_EFFECT_RAINBOW_MOOD
#define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#define RGBLIGHT_EFFECT_RGB_TEST
#define RGBLIGHT_EFFECT_SNAKE
#define RGBLIGHT_EFFECT_STATIC_GRADIENT
#define RGBLIGHT_EFFECT_TWINKLE

#    ifndef RGBLIGHT_LIMIT_VAL
#    	define RGBLIGHT_LIMIT_VAL 150
#    endif
#endif

