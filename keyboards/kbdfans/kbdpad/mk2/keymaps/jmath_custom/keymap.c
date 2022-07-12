/* Copyright 2019 Ryota Goto
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

	[0] = LAYOUT_ortho_6x4( \
		LT(2,KC_ESC), KC_INS      , KC_DEL      , KC_BSPC     , \
		TO(1)       , KC_PSLS     , KC_PAST     , KC_PMNS     , \
		LT(3,KC_P7) , KC_P8       , KC_P9       , KC_PPLS     , \
		KC_P4       , KC_P5       , KC_P6       , KC_TAB      , \
		KC_P1       , KC_P2       , KC_P3       , KC_PENT     , \
		KC_P0       , KC_P0       , KC_PDOT     , KC_PENT     ),

	[1] = LAYOUT_ortho_6x4( \
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
		TO(0)  , KC_TRNS, KC_TRNS, KC_TRNS, \
		KC_HOME, KC_UP  , KC_PGUP, KC_TRNS, \
		KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS, \
		KC_END , KC_DOWN, KC_PGDN, KC_TRNS, \
		KC_INS , KC_INS , KC_DEL , KC_TRNS),

	[2] = LAYOUT_ortho_6x4( \
		KC_NO , KC_NO, KC_NO, QK_BOOT, \
		KC_NUM, KC_NO, KC_NO, KC_NO  , \
		KC_NO , KC_NO, KC_NO, KC_NO  , \
		KC_NO , KC_NO, KC_NO, KC_NO  , \
		KC_NO , KC_NO, KC_NO, KC_NO  , \
		KC_NO , KC_NO, KC_NO, KC_NO  ),

	[3] = LAYOUT_ortho_6x4( \
		KC_NO, KC_NO  , KC_NO  , KC_NO  , \
		KC_NO, RGB_TOG, RGB_MOD, RGB_VAI, \
		KC_NO, RGB_HUD, RGB_HUI, RGB_VAD, \
		KC_NO, RGB_SAD, RGB_SAI, RGB_SPI, \
		KC_NO, KC_NO  , KC_NO  , RGB_SPD, \
		KC_NO, KC_NO  , KC_NO  , KC_NO  )

};
