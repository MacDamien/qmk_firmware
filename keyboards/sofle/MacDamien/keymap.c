// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
// #include <stdio.h>

#include QMK_KEYBOARD_H

enum sofle_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _QWERTY,
    _PLOVER,
    _NUMBER,
    _NAV,
    _MOUSE,
    _ADJUST,
};

enum custom_keycodes {
    KC_QWERTY = QK_USER,
    KC_PLOVER,
    KC_NUMBER,
    KC_NAV,
    KC_MOUSE,
    KC_ADJUST
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * !      !      ! LALT ! LCMD ! LCTL !      !       !    !       !      ! LCTL ! LCMD ! LALT !      !      !
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |  ;   |  N   | LSFT | SPC  | /Escape /       \Enter \  | SPC  | ESC   |      !      |
 *            |      |      | BSPC | Nav  |/       /         \      \ |MOUSE | RAlt  |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_QWERTY] = LAYOUT(
  KC_GRV,   KC_1,           KC_2,        KC_3,        KC_4,        KC_5,                         KC_6,    KC_7,        KC_8,        KC_9,         KC_0,    KC_GRV,
  KC_ESC,   KC_Q,           KC_W,        KC_E,        KC_R,        KC_T,                         KC_Y,    KC_U,        KC_I,        KC_O,         KC_P,    KC_BSPC,
  KC_TAB,   LSFT_T(KC_A),   ALT_T(KC_S), GUI_T(KC_D), CTL_T(KC_F), KC_G,                         KC_H,    CTL_T(KC_J), GUI_T(KC_K), ALT_T(KC_L), KC_SCLN, KC_QUOT,
  XXXXXXX,  KC_Z,           KC_X,        KC_C,        KC_V,        KC_B, LCA_T(KC_SPC), XXXXXXX, KC_N,    KC_M,        KC_COMM,     KC_DOT,       KC_SLSH, KC_RSFT,
                    KC_SCLN, KC_N, LSFT_T(KC_BSPC), TT(_NUMBER), KC_ESC,            LT(_MOUSE, KC_ENT),   LT(_NAV, KC_SPC), ALGR_T(KC_ESC), KC_TAB, KC_EJCT
),
/*''
 * PLOVER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   Q  |   W  |   F  |   P  |   G  |                    |   J  |   L  |   U  |   Y  |   ;  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  |   A  |   R  |   S  |   T  |   D  |-------.    ,-------|   H  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   K  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_PLOVER] = LAYOUT(
  KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_GRV,
  KC_ESC,   KC_Q,   KC_W,    KC_F,    KC_P,    KC_G,                      KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN,  KC_BSPC,
  KC_TAB,   KC_A,   KC_R,    KC_S,    KC_T,    KC_D,                      KC_H,    KC_N,    KC_E,    KC_I,    KC_O,  KC_QUOT,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_MUTE,      XXXXXXX,KC_K,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_RSFT,
                 KC_LGUI,KC_LALT,KC_LCTL,TL_LOWR, KC_ENT,        KC_SPC,  TL_UPPR, KC_RCTL, KC_RALT, KC_RGUI
),
/* NAV
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   |  |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|r
 * | Shift|  =   |  -   |  +   |   {  |   }  |-------|    |-------|   [  |   ]  |   ;  |   :  |   \  | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_NAV] = LAYOUT(
  _______, _______ , _______ , _______ , _______ , _______,                           _______,  _______  , _______,  _______ ,  _______ ,_______,
  _______,  KC_INS,  KC_PGUP,   KC_UP,  KC_PGDN, XXXXXXX,                       XXXXXXX, KC_PGUP, KC_UP, KC_PGDN, KC_BSPC, _______,
  _______, XXXXXXX, KC_LEFT,  KC_DOWN,  KC_RGHT,  XXXXXXX,                      KC_LGUI, KC_LALT,  KC_LCTL,  KC_LSFT, KC_BSPC, _______,
  _______,KC_UNDO, KC_CUT, KC_COPY, KC_PASTE, XXXXXXX,  _______,       _______,  XXXXXXX, KC_HOME, XXXXXXX, XXXXXXX, XXXXXXX,   _______,
                         _______, _______, KC_DEL, _______, _______,       _______, _______, _______, _______, _______
),
/* NUM
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   |  |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * | Shift|  =   |  -   |  +   |   {  |   }  |-------|    |-------|   [  |   ]  |   ;  |   :  |   \  | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_NUMBER] = LAYOUT(
  _______,  KC_F1,   KC_F2,      KC_F3,   KC_F4,   KC_F5,                         KC_F6,   KC_F7,   KC_F8, KC_F9, KC_F10,  KC_F11,
  _______,  S(KC_1), RALT(KC_W), KC_UP,   KC_DLR,  KC_PERC,                       KC_PLUS, KC_7,    KC_8,  KC_9,  KC_SLSH, KC_ASTR,
  _______,  KC_LCBR, KC_LEFT,    KC_DOWN, KC_RGHT, KC_LPRN,                       KC_MINS, KC_1,    KC_2,  KC_3,  KC_0,    KC_BSPC,
 _______,   KC_TILD, KC_LBRC,    KC_RBRC, KC_UNDS, KC_HASH, _______,     _______, KC_DOT,  KC_4,    KC_5,  KC_6,  KC_COLN, KC_SCLN,
                       _______, _______, _______, TO(_QWERTY), _______,     _______, _______, KC_ENT, _______, KC_F12
),
/* MOUSE*x ,----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Esc  | Ins  | Pscr | Menu |      |      |                    |      | PWrd |  Up  | NWrd | DLine| Bspc |
 * |----+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Ta | LCtl |LShift|      | Caps |-------.    ,-------|      | Left | Down | Rigth|  Del | Bspc |
 * |------+------+------+------+------+------|  MUTE  |    |       |------+------+------+------+------+------|
 * |Shift | Undo |  Cut | Copy | Paste|      |-------|    |-------|      | LStr |      | LEnd |      | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_MOUSE] = LAYOUT(
 _______, _______, _______, _______, _______, _______,                              _______, _______, _______, _______, _______, _______,
 _______, _______, _______, KC_MS_U, _______, _______,                              _______, _______, _______, _______, _______, _______,
 _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______,                              _______, KC_BTN1, KC_BTN3, KC_BTN2, _______, _______,
 _______, _______, _______, _______, _______, _______, _______,            _______, _______, _______, _______, _______, _______, _______,
                            _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | QK_BOOT|      |QWERTY|COLEMAK|      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |MACWIN|      |      |      |-------.    ,-------|      | VOLDO| MUTE | VOLUP|      |      |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      | PREV | PLAY | NEXT |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
  [_ADJUST] = LAYOUT(
  XXXXXXX , XXXXXXX, XXXXXXX ,  XXXXXXX ,  XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  QK_BOOT , XXXXXXX, KC_QWERTY, KC_PLOVER, CG_TOGG, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX , XXXXXXX, CG_TOGG,   XXXXXXX,   XXXXXXX, XXXXXXX,                     XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, XXXXXXX,
  KC_T , XXXXXXX, XXXXXXX,   XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX,
                   _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
  )
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _NUMBER, _MOUSE, _ADJUST);
}
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        case KC_PLOVER:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_PLOVER);
            }
            return false;
        case KC_NUMBER:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_NUMBER);
            }
            break;
        case KC_NAV:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_NAV);
            }
            break;
        case KC_MOUSE:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_MOUSE);
            }
            break;
        case KC_ADJUST:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_ADJUST);
            }
            break;
    }
    return true;
}
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] = { ENCODER_CCW_CW(KC_LEFT, KC_RGHT),  ENCODER_CCW_CW(KC_VOLU, KC_VOLD)  },
    [1] = { ENCODER_CCW_CW(KC_UP, KC_DOWN), ENCODER_CCW_CW(KC_LEFT, KC_RIGHT) },
    [2] = { ENCODER_CCW_CW(KC_UP, KC_DOWN), ENCODER_CCW_CW(KC_LEFT, KC_RIGHT) },
    [3] = { ENCODER_CCW_CW(KC_UP, KC_DOWN), ENCODER_CCW_CW(KC_LEFT, KC_RIGHT) },
    [4] = { ENCODER_CCW_CW(KC_UP, KC_DOWN), ENCODER_CCW_CW(KC_LEFT, KC_RIGHT) },
    [5] = { ENCODER_CCW_CW(KC_UP, KC_DOWN), ENCODER_CCW_CW(KC_LEFT, KC_RIGHT) },
};
#endif

