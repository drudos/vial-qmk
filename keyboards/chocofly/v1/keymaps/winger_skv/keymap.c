// Copyright 2022 Will Winder (@winder)
// SPDX-License-Identifier: GPL-2.0-or-later
//
// qmk compile -kb chocofly/v1 -km winger_skv
// qmk flash -kb chocofly/v1 -km winger_skv
//
#include QMK_KEYBOARD_H

enum layers {
    _QWERTY,
    _LOWER,
    _RAISE,
};

#define MT_LCTL LCTL_T(KC_EQL)
#define LW_LBRC LT(_LOWER, KC_LBRC)
#define MT_RALT RALT_T(KC_ENT)
#define LW_RBRC LT(_LOWER, KC_RBRC)
#define MT_RCTL RCTL_T(KC_MINS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                 XXXXXXX, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                                KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    XXXXXXX,
                 XXXXXXX, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_MUTE,                                    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, XXXXXXX,
                 XXXXXXX, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LGUI, KC_APP,  /**/ MO(_RAISE), KC_LGUI, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, XXXXXXX,
                                                     KC_LALT, MT_LCTL, LW_LBRC, MT_RALT, /**/ KC_SPC,     LW_RBRC, MT_RCTL, KC_RALT
    ),
    [_LOWER] = LAYOUT(
                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                 XXXXXXX, KC_GRV,  KC_7,    KC_8,    KC_9,    KC_BSPC,                                          KC_DEL,  KC_HOME, KC_UP,   KC_END,  KC_PGUP, XXXXXXX,
                 XXXXXXX, KC_0,    KC_4,    KC_5,    KC_6,    KC_DEL,  _______,                                 KC_BSPC, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, XXXXXXX,
                 XXXXXXX, KC_GRV,  KC_1,    KC_2,    KC_3,    KC_TAB,  _______, _______, /**/ _______, _______, KC_TAB,  XXXXXXX, XXXXXXX, KC_QUOT, KC_BSLS, XXXXXXX,
                                                     _______, _______, _______, _______, /**/ _______, _______, _______, _______
    ),
    [_RAISE] = LAYOUT(
                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                 XXXXXXX, KC_F12,  KC_F7,   KC_F8,   KC_F9,   XXXXXXX,                                          XXXXXXX, XXXXXXX, KC_UP,   XXXXXXX, XXXXXXX, XXXXXXX,
                 XXXXXXX, KC_F11,  KC_F4,   KC_F5,   KC_F6,   KC_DEL,  XXXXXXX,                                 XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX,
                 XXXXXXX, KC_F10,  KC_F1,   KC_F2,   KC_F3,   XXXXXXX, _______, _______, /**/ _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                                     _______, _______, _______, _______, /**/ _______, _______, _______, _______
    ),
};

// define combo names
enum combos {
    lshft_par,
    rshft_par,
    esc_grv,
    tab,
    space,
    enter,
    COMBO_LENGTH
};

// nifty trick continued
uint16_t COMBO_LEN = COMBO_LENGTH;

// define keys that make up combos
    const uint16_t PROGMEM zx_combo[] = {KC_Z, KC_X, COMBO_END};
    const uint16_t PROGMEM ds_combo[] = {KC_DOT, KC_SLSH, COMBO_END};
    const uint16_t PROGMEM qw_combo[] = {KC_Q, KC_W, COMBO_END};
    const uint16_t PROGMEM as_combo[] = {KC_A, KC_S, COMBO_END};
    const uint16_t PROGMEM sd_combo[] = {KC_S, KC_D, COMBO_END};
    const uint16_t PROGMEM kl_combo[] = {KC_K, KC_L, COMBO_END};

// map combo names to their keys and the key they trigger
combo_t key_combos[] = {
    [lshft_par] = COMBO(zx_combo, SC_LSPO),
    [rshft_par] = COMBO(ds_combo, SC_RSPC),
    [esc_grv] = COMBO(qw_combo, QK_GESC),
    [tab] = COMBO(as_combo, KC_TAB),
    [space] = COMBO(sd_combo, KC_SPC),
    [enter] = COMBO(kl_combo, KC_ENT),
};

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code_delay(KC_VOLD, 10);
        } else {
            tap_code_delay(KC_VOLU, 10);
        }
    }
    return true;
}
#endif
