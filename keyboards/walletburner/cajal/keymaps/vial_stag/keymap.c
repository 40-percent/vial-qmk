/* Copyright 2020 Worldspawn <mcmancuso@gmail.com>
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

#define CTL_ESC MT(MOD_LCTL,KC_ESC)
#define ENT_LR1 LT(1,KC_ENT)
#define SPC_LR2 LT(2,KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT_ortho(
        KC_TAB , KC_Q   , KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL , KC_BSPC, RGB_TOG, \
        CTL_ESC, KC_A   , KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_NO  ,          \
        KC_LSPO, KC_Z   , KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT , KC_SLSH, KC_RSPC, KC_UP  ,          \
        KC_LCTL, KC_NO  , KC_LGUI, KC_LALT, ENT_LR1, ENT_LR1, SPC_LR2, SPC_LR2, MO(3),   KC_NO  , KC_NO  , KC_LEFT, KC_DOWN, KC_RGHT  \
    ),

    [1] = LAYOUT_ortho(
        KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______, _______, _______, \
        _______, _______, C(KC_F4),A(KC_F4),_______, _______, KC_MINS, KC_EQL , KC_LCBR, KC_RCBR, KC_PIPE, KC_GRV , _______,          \
        _______, _______, _______, _______, _______, _______, KC_UNDS, KC_PLUS, KC_LBRC, KC_RBRC, KC_BSLS, KC_TILD, _______,          \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
    ),

    [2] = LAYOUT_ortho(
        KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, KC_PGUP, KC_HOME, _______,          \
        _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, KC_END , _______,          \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
    ),

    [3] = LAYOUT_ortho(
        RGB_TOG,  RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW,RGB_M_SN, RGB_M_K, RGB_M_X, RGB_M_G, S(KC_ESC),_______,_______, _______, _______, \
        RGB_MOD,  RGB_VAI, RGB_HUI, RGB_SAI, _______,  _______, _______, _______, _______, _______, _______, _______, _______,          \
        RGB_RMOD, RGB_VAD, RGB_HUD, RGB_SAD, _______,  _______, _______, _______, _______, _______, _______, _______, _______,          \
        RESET,    _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______  \
    )
};

void matrix_init_user(void) {
  setPinOutput(B5);
  writePinLow(B5);
  setPinOutput(B6);
  writePinLow(B6);
  setPinOutput(B7);
  writePinLow(B7);
}

layer_state_t layer_state_set_user(layer_state_t state) {
    writePinLow(B5);
    writePinLow(B6);
    writePinLow(B7);
    switch (get_highest_layer(state)) {
    case 1:
        writePinHigh(B5);
        break;
    case 2:
        writePinHigh(B6);
        break;
    case 3:
        writePinHigh(B7);
        break;
    }
    return state;
}
