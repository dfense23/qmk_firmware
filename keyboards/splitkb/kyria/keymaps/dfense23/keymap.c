/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
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
#include QMK_KEYBOARD_H

char wpm_str[10];

enum layers {
    _COLEMAK_DH = 0,
    _NUM,
    _SYM,
    _NAV,
    _NUMPAD,
    _GAME,
    _ADJUST,
    _MOUSE,
};
bool is_alt_tab_active = false; // ADD this near the begining of keymap.c
bool is_alt_shift_tab_active = false; // ADD this near the begining of keymap.c
uint16_t alt_tab_timer = 0;     // we will be using them soon.

//ALT TAB Encoder Timer
void matrix_scan_user(void) { // The very important timer.
  if (is_alt_tab_active) {
    if (timer_elapsed(alt_tab_timer) > 1000) {
      unregister_code(KC_LALT);
      unregister_code(KC_LSFT);
      is_alt_tab_active = false;
      is_alt_shift_tab_active = false;
    }
  }
}; 

// Aliases for readability
#define COLEMAK  DF(_COLEMAK_DH)
#define NUM   MO(_NUM)
#define SYM      MO(_SYM)
#define NAV      MO(_NAV)
#define NUMPAD    MO(_NUMPAD)
#define GAME    MO(_GAME)
#define ADJUST   MO(_ADJUST)
#define MOUSE   MO(_MOUSE)

#define CTL_ESC  MT(MOD_LCTL, KC_ESC)
#define CTL_QUOT MT(MOD_RCTL, KC_QUOTE)
#define CTL_MINS MT(MOD_RCTL, KC_MINUS)
#define ALT_ENT  MT(MOD_LALT, KC_ENT)

// Note: LAlt/Enter (ALT_ENT) is not the same thing as the keyboard shortcut Alt+Enter.
// The notation `mod/tap` denotes a key that activates the modifier `mod` when held down, and
// produces the key `tap` when tapped (i.e. pressed and released).

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*
 * Base Layer: Colemak DH
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  Tab   |   Q  |   W  |   F  |   P  |   B  |                              |   J  |   L  |   U  |   Y  | ;  : |  Bksp  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |Ctrl/Esc|   A  |   R  |   S  |   T  |   G  |                              |   M  |   N  |   E  |   I  |   O  |Ctrl/' "|
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   D  |   V  | [ {  |CapsLk|  |F-keys|  ] } |   K  |   H  | ,  < | . >  | /  ? | RShift |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |Adjust| LGUI | LAlt/| Space| Nav  |  | Sym  | Space| AltGr| RGUI | Menu |
 *                        |      |      | Enter|      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'

    [_COLEMAK_DH] = LAYOUT(
     KC_TAB  , KC_Q ,  KC_W   ,  KC_F  ,   KC_P ,   KC_B ,                                        KC_J,   KC_L ,  KC_U ,   KC_Y ,KC_SCLN, KC_BSPC,
     CTL_ESC , KC_A ,  KC_R   ,  KC_S  ,   KC_T ,   KC_G ,                                        KC_M,   KC_N ,  KC_E ,   KC_I ,  KC_O , CTL_QUOT,
     KC_LSFT , KC_Z ,  KC_X   ,  KC_C  ,   KC_D ,   KC_V , KC_LBRC,KC_CAPS,     FKEYS  , KC_RBRC, KC_K,   KC_H ,KC_COMM, KC_DOT ,KC_SLSH, KC_RSFT,
                                 ADJUST, KC_LGUI, ALT_ENT, KC_SPC , NAV   ,     SYM    , KC_SPC ,KC_RALT, KC_RGUI, KC_APP
    ),
 */
// /*
//  * Layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),      

	[_COLEMAK_DH] = LAYOUT_split_3x6_5( 
        KC_TAB, KC_Q, KC_W, KC_F, KC_P, KC_B,                                                                               KC_J, KC_L, KC_U, KC_Z, LSFT(KC_RBRC), KC_MINS, 
        KC_BSPC, LGUI_T(KC_A), LALT_T(KC_R), LSFT_T(KC_S), LCTL_T(KC_T),KC_G,                                               KC_M, RCTL_T(KC_N), RSFT_T(KC_E), RALT_T(KC_I), RGUI_T(KC_O), KC_ENT, 
        KC_LSFT, KC_Y, KC_X, KC_C, KC_D, KC_V,              KC_ESC, KC_TRNS,                        KC_NO, TT(7),          KC_K, KC_H, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, 
                                TO(COLEMAK), KC_DEL, TT(NUM), KC_SPC, KC_TRNS,                                    TT(SYM), KC_ENT, TT(NAV), TT(NUMPAD), TO(GAME)),
	[_NUM] = LAYOUT_split_3x6_5(
        KC_F12, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,                                                                          KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, 
        KC_TRNS, LGUI_T(KC_1), LALT_T(KC_2), LSFT_T(KC_3), LCTL_T(KC_4), KC_5,                                              KC_6, RCTL_T(KC_7), RSFT_T(KC_8), RALT_T(KC_9), RGUI_T(KC_0), KC_TRNS, 
        KC_TRNS, KC_QUOT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS, KC_TRNS,               KC_TRNS, KC_TRNS,       KC_LBRC, KC_SCLN, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
                                KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
	[_SYM] = LAYOUT_split_3x6_5(
        KC_TRNS, RALT(KC_EQL), KC_EQL, KC_TRNS, KC_TRNS, KC_TRNS,                                                           KC_TRNS, KC_TRNS, RALT(KC_LBRC), RALT(KC_RBRC), LSFT(KC_EQL), LALT(KC_MINS), 
        KC_TRNS, LSFT(KC_1), LSFT(KC_2), LSFT(KC_3), KC_NUHS, LSFT(KC_5),                                                   LSFT(KC_6), LSFT(KC_7), LSFT(KC_8), LSFT(KC_9), LSFT(KC_0), KC_TRNS, 
        KC_TRNS, RALT(KC_1), RALT(KC_2), RALT(KC_3), RALT(KC_4), RALT(KC_5),    KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,     RALT(KC_6), RALT(KC_7), RALT(KC_QUOT), RALT(KC_NUHS), KC_TRNS, KC_TRNS, 
                                KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
	[_NAV] = LAYOUT_split_3x6_5(
        KC_TRNS, LCTL(KC_T), LCTL(KC_W), LCTL(KC_F), KC_TRNS, KC_TRNS,                                                      KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_TRNS, KC_TRNS, 
        KC_TRNS, LGUI_T(LSA(KC_T)), LALT_T(KC_BTN3), LSFT_T(KC_BTN2), LCTL_T(KC_BTN1), KC_TRNS,                             KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_TRNS, KC_TRNS, 
        KC_TRNS, KC_WBAK, KC_WFWD, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS,       KC_NUBS, LSFT(KC_7), RALT(KC_NUBS), LSFT(KC_NUBS), RALT(KC_NO), KC_TRNS, 
                                KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
	[_NUMPAD] = LAYOUT_split_3x6_5(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PGUP,                                                              KC_NUM, KC_P7, KC_P8, KC_P9, KC_PPLS, KC_PMNS, 
        KC_TRNS, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, KC_PGDN,                                                               KC_DOWN, KC_P4, KC_P5, KC_P6, KC_PAST, KC_PSLS, 
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS,       KC_RGHT, KC_P1, KC_P2, KC_P3, KC_PDOT, KC_PENT,
                                KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_P0),
	[_GAME] = LAYOUT_split_3x6_5(
        KC_B, KC_TAB, KC_G, KC_W, KC_F, KC_R,                                                                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
        KC_LCTL, KC_LSFT, KC_A, KC_S, KC_D, KC_T,                                                                           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
        KC_TRNS, KC_1, KC_2, KC_3, KC_4, KC_M,                                  KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
                                KC_TRNS, KC_TRNS, KC_LCTL, KC_TRNS, KC_LCTL,                              TO(COLEMAK), TO(ADJUST), KC_TRNS, KC_TRNS, KC_TRNS),
	[_ADJUST] = LAYOUT_split_3x6_5(
        NK_ON, DT_UP, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                                                 RGB_TOG, RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_K, RGB_M_X, 
        NK_OFF, DT_DOWN, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                                                RGB_SPI, RGB_SAI, RGB_HUI, RGB_VAI, RGB_MOD, KC_TRNS, 
        KC_TRNS, DT_PRNT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS,       RGB_SPD, RGB_SAD, RGB_HUD, RGB_VAD, RGB_RMOD, KC_TRNS, 
                                KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                            TO(GAME), TO(MOUSE), KC_TRNS, KC_TRNS, KC_TRNS),
	[_MOUSE] = LAYOUT_split_3x6_5(
        KC_TRNS, LCTL(KC_T), LCTL(KC_W), LCTL(KC_F),KC_TRNS, KC_PGUP,                                                              KC_LCTL, KC_LSFT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
        KC_WBAK, KC_WFWD, KC_BTN2, KC_BTN3, KC_BTN1, KC_PGDN,                                                               KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
                                KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                              TO(ADJUST), TO(COLEMAK), KC_TRNS, KC_TRNS, KC_TRNS),
};

void pointing_device_init_user(void) {
    //set_auto_mouse_layer(_MOUSE); // only required if AUTO_MOUSE_DEFAULT_LAYER is not set to index of <mouse_layer>
    set_auto_mouse_enable(true);         // always required before the auto mouse feature will work
} 

/* The default OLED and rotary encoder code can be found at the bottom of qmk_firmware/keyboards/splitkb/kyria/rev1/rev1.c
 * These default settings can be overriden by your own settings in your keymap.c
 * For your convenience, here's a copy of those settings so that you can uncomment them if you wish to apply your own modifications.
 * DO NOT edit the rev1.c file; instead override the weakly defined default functions by your own.
 */

#include "quantum.h"
static void render_csd_logo(void) {

  static const char PROGMEM csd_logo[] = {
// 'csd-64-top-line', 128x64px
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xf0, 0xf0, 0xc0, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xf0, 
0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0xc0, 0xf0, 0xf0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0xc0, 0xe0, 0xe0, 0xf0, 0xf0, 0xf8, 0xf8, 
0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xfc, 0xfc, 0xfc, 0xfe, 0xfe, 0x7f, 0x3f, 0x1f, 0x1f, 0x8f, 0xcf, 
0xe6, 0xf6, 0xfc, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xfc, 0xfc, 0xfc, 0xfe, 0xff, 0xff, 0xff, 0xff, 
0xff, 0x3f, 0x1f, 0x0e, 0x0c, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x06, 0x06, 0x0f, 
0x0f, 0x1f, 0x1f, 0x3f, 0x7f, 0xfe, 0xfe, 0xfc, 0xfc, 0xfc, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 
0xf8, 0xf0, 0xf0, 0xe0, 0xe0, 0xc0, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x80, 0xe0, 0xf8, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0x1f, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x3e, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe7, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xf8, 0xe0, 0x80, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 
0x07, 0x0f, 0x0f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x3f, 0x3f, 0x7f, 0x7f, 0xff, 0xff, 0xff, 
0xff, 0xfc, 0xf8, 0xf8, 0xf0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xc0, 0xc0, 0xc0, 0x80, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x70, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x07, 0x1f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xfc, 0xe0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x1f, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xfe, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xe0, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x1f, 0x07, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x07, 0x07, 0x0f, 0x1f, 0x1f, 0x3f, 0x3f, 0x7f, 0x7f, 
0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0xff, 0xff, 0xff, 0xfe, 0xfc, 0xf8, 0xf0, 0xe0, 0xe0, 0xc0, 0xc0, 
0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0xc0, 0xe0, 0xf0, 0xf8, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x7f, 0x7f, 0x7f, 0xff, 0xbf, 0x9f, 0xcf, 
0xc7, 0xe1, 0xe0, 0xf0, 0xf8, 0xfc, 0xfe, 0xff, 0xff, 0xff, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 
0x7f, 0x3f, 0x3f, 0x1f, 0x1f, 0x0f, 0x0f, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x03, 0x07, 0x3f, 0x3f, 0x0f, 0x03, 
0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x0f, 0x3f, 
0x0f, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x03, 
0x0f, 0x3f, 0x3f, 0x0f, 0x03, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

  };

  oled_write_raw_P(csd_logo, sizeof(csd_logo));
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_180; }

bool oled_task_user(void) {
    render_csd_logo();
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state|default_layer_state)) {
        case _COLEMAK_DH:
            oled_write_P(PSTR("Colemak-DH\n"), false);
            break;
        case _NUM:
            oled_write_P(PSTR("Numeric\n"), false);
            break;
        case _SYM:
            oled_write_P(PSTR("Symbol\n"), false);
            break;
        case _NAV:
            oled_write_P(PSTR("Navigastion\n"), false);
            break;
        case _NUMPAD:
            oled_write_P(PSTR("Numpad\n"), false);
            break;
        case _GAME:
            oled_write_P(PSTR("Gaming\n"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Adjust\n"), false);
            break;
        case _MOUSE:
            oled_write_P(PSTR("Mouse\n"), false);
            break;
        default:
            oled_write_P(PSTR("Undefined\n"), false);
    }

    /*
        // QMK Logo and version information
        // clang-format off
        static const char PROGMEM qmk_logo[] = {
            0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
            0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
            0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};
        // clang-format on

        oled_write_P(qmk_logo, false);
        oled_write_P(PSTR("Kyria "), false);
        oled_write_P(PSTR("rev3.dfense\n\n"), false);


#endif
        // Host Keyboard Layer Status
        oled_write_P(PSTR("Layer: "), false);
        switch (get_highest_layer(layer_state|default_layer_state)) {
             case _COLEMAK_DH:
                oled_write_P(PSTR("Colemak-DH\n"), false);
                break;
            case _NUM:
                oled_write_P(PSTR("Numeric\n"), false);
                break;
            case _SYM:
                oled_write_P(PSTR("Symbol\n"), false);
                break;
            case _NAV:
                oled_write_P(PSTR("Navigastion\n"), false);
                break;
            case _NUMPAD:
                oled_write_P(PSTR("Numpad\n"), false);
                break;
            case _GAME:
                oled_write_P(PSTR("Gaming\n"), false);
                break;
            case _ADJUST:
                oled_write_P(PSTR("Adjust\n"), false);
                break;
            default:
                oled_write_P(PSTR("Undefined\n"), false);
        }

       // Host Keyboard LED Status
        led_t led_usb_state = host_keyboard_led_state();
        oled_write_P(led_usb_state.num_lock ? PSTR("NUMLCK ") : PSTR("       "), false);
        oled_write_P(led_usb_state.caps_lock ? PSTR("CAPLCK ") : PSTR("       "), false);
        oled_write_P(led_usb_state.scroll_lock ? PSTR("SCRLCK ") : PSTR("       "), false);
    
        */  
       
    return false;
}

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (get_highest_layer(layer_state|default_layer_state) == 7) {
        if (index == 0) {
            if (clockwise) {
                rgblight_increase_hue();
            } else {
                rgblight_decrease_hue();
            }
        } else if (index == 1) {
            if (clockwise) {
                rgblight_increase_val();
            } else {
                rgblight_decrease_val();
            }
        }
    }

    else {
        if (index == 0) {
            if (clockwise) {
                tap_code(KC_PGDN);
            } else {
                tap_code(KC_PGUP);
            }
        } else if (index == 1) {
            if (clockwise) {
                if (!is_alt_tab_active) {
                    is_alt_tab_active = true;
                unregister_code(KC_LSFT);
                register_code(KC_LALT);
                }
                alt_tab_timer = timer_read();
                tap_code(KC_TAB);
            } else {
                if (!is_alt_shift_tab_active) {
                    is_alt_shift_tab_active = true;
                register_code(KC_LALT);
                register_code(KC_LSFT);
                }
                alt_tab_timer = timer_read();
                tap_code(KC_TAB);
            }
        }
    }
    return false;
};
#endif