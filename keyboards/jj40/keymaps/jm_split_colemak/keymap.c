/* Copyright 2019
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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT_planck_mit( \
    KC_Q, KC_W, KC_F, KC_P, KC_G, KC_ESC, KC_QUOT, KC_J, KC_L, KC_U, KC_Y, KC_SCLN, \
    KC_A, KC_R, KC_S, KC_T, KC_D, KC_TAB, KC_BSPC, KC_H, KC_N, KC_E, KC_I, KC_O, \
    KC_Z, KC_X, KC_C, KC_V, KC_B, KC_LCTL, KC_RCTL, KC_K, KC_M, KC_COMM, KC_DOT, KC_SLSH, \
    KC_LGUI, MO(3), KC_LALT, KC_SPC, KC_LSFT, LT(4,KC_ENT), MO(5), KC_SPC, MO(6), RALT(KC_LEFT), RALT(KC_RGHT)),

    [1] = LAYOUT_planck_mit( \
    KC_Q, KC_W, KC_E, KC_R, KC_1, KC_4, KC_7, KC_T, KC_HOME, KC_I, KC_PGUP, KC_F12, \
    KC_A, KC_S, KC_D, KC_F, KC_2, KC_5, KC_8, KC_G, KC_END, KC_UP, KC_PGDN, LSFT(LCTL(KC_TAB)), \
    KC_Z, KC_X, KC_C, KC_SPC, KC_3, KC_6, KC_9, KC_B, KC_LEFT, KC_DOWN, KC_RGHT, LSFT(LCTL(KC_GRV)), \
    KC_LCTL, LT(3,KC_TAB), KC_LALT, KC_LSFT, KC_V, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LGUI, KC_ESC),

    [2] = LAYOUT_planck_mit( \
    KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_1, KC_4, KC_7, KC_T, KC_HOME, KC_I, KC_PGUP, \
    KC_TAB, KC_A, KC_S, KC_D, KC_F, KC_2, KC_5, KC_8, KC_G, KC_END, KC_UP, KC_PGDN, \
    KC_SPC, KC_Z, KC_X, KC_C, KC_V, KC_3, KC_6, KC_9, KC_B, KC_LEFT, KC_DOWN, KC_RGHT, \
    KC_LCTL, MO(3), KC_LALT, KC_SPC, KC_LSFT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LGUI, KC_RALT),

    [3] = LAYOUT_planck_mit( \
    KC_MUTE, KC_VOLD, KC_VOLU, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, \
    RGB_TOG, RGB_VAD, RGB_VAI, RGB_HUD, RGB_HUI, RGB_SAD, RGB_SAI, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, \
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, \
    LAG_NRM, KC_TRNS, LAG_SWP, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO),

    [4] = LAYOUT_planck_mit( \
    KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_GRV, KC_NO, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, \
    KC_NO, KC_NO, KC_NO, KC_NO, KC_MINS, KC_TILD, KC_DEL, KC_EQL, KC_NO, KC_LBRC, KC_RBRC, KC_BSLS, \
    KC_LSFT, KC_LSFT, KC_NO, KC_NO, KC_UNDS, KC_TRNS, KC_TRNS, KC_PLUS, KC_NO, KC_LCBR, KC_RCBR, KC_PIPE, \
    KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO),

    [5] = LAYOUT_planck_mit( \
    KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_6, KC_7, KC_8, KC_9, KC_0, \
    KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_8, KC_NO, KC_4, KC_5, KC_6, KC_NO, \
    KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_9, KC_NO, KC_1, KC_2, KC_3, KC_ENT, \
    KC_NO, KC_NO, KC_NO, KC_NO, OSL(7), KC_0, KC_TRNS, KC_NO, KC_COMM, KC_DOT, KC_NO),

    [6] = LAYOUT_planck_mit( \
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_ESC, KC_NO, KC_HOME, KC_PGUP, KC_UP, KC_PGDN, KC_END, \
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TAB, KC_BSPC, RALT(KC_LEFT), KC_LEFT, KC_DOWN, KC_RGHT, RCTL(KC_LEFT), \
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RALT(KC_RGHT), KC_NO, KC_NO, KC_NO, RCTL(KC_RGHT), \
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_ENT, TO(0), TO(1), KC_TRNS, TO(2), RALT(KC_SLSH)),

    [7] = LAYOUT_planck_mit( \
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RESET, KC_NO, KC_NO, KC_NO, KC_NO, KC_PWR, KC_NO, \
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, \
    KC_SLEP, KC_NO, EEP_RST, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, \
    KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO)

};
