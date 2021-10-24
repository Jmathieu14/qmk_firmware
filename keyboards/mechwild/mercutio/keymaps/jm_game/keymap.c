/* Copyright 2021 Kyle McCreery
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

enum layers {
    DEFAULT = 0,
    NAV,
    NUM,
    SYM_FUNC,
    MEDIA
};

enum tap_dances {
    B_QUOTE,
    BSPC_DEL
};

qk_tap_dance_action_t tap_dance_actions[] = {
    [B_QUOTE] = ACTION_TAP_DANCE_DOUBLE(KC_B, KC_QUOTE),
    [BSPC_DEL] = ACTION_TAP_DANCE_DOUBLE(KC_BSPC, KC_DEL)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[DEFAULT] = LAYOUT_all( \
                                                                                                                                            KC_MUTE        , \
		LT(NUM,KC_ESC)  , KC_Q   , KC_W   , KC_E          , KC_R        , KC_T           , KC_Y       , KC_U   , KC_I   , KC_O   , KC_P   , TD(BSPC_DEL)   , \
		LT(MEDIA,KC_TAB), KC_A   , KC_S   , KC_D          , KC_F        , KC_G           , KC_H       , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_ENT         , \
		KC_LCTL         , KC_LSFT, KC_Z   , KC_X          , KC_C        , KC_V           , TD(B_QUOTE), KC_N   , KC_M   , KC_COMM, KC_DOT , LT(NUM,KC_SLSH), \
		MO(NAV)         , KC_LGUI, KC_LALT, LSFT_T(KC_SPC), MO(SYM_FUNC), LT(NAV,KC_SPC) , KC_RALT, KC_F4  , KC_RCTL),

	[NAV] = LAYOUT_all( \
		                                                                                                               KC_TRNS, \
		KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_PGUP, KC_HOME, KC_UP        , KC_END       , KC_PGDN, \
		KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_LEFT, KC_DOWN      , KC_RGHT      , KC_ENT , \
		KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , LCTL(KC_LEFT), LCTL(KC_RGHT), KC_NO  , \
		KC_TRNS, KC_NO  , KC_NO  , KC_NO  , KC_TRNS, KC_NO  , KC_NO  , KC_NO  , KC_NO  ),

	[NUM] = LAYOUT_all( \
		                                                                                                   KC_TRNS, \
		KC_TRNS, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_SLSH, \
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PLUS, KC_4   , KC_5   , KC_6   , KC_ASTR, KC_ENT , \
		KC_LCTL, KC_LSFT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MINS, KC_COMM, KC_1   , KC_2   , KC_3   , KC_DOT , \
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_0   , KC_ENT , KC_TRNS, KC_TRNS),

	[SYM_FUNC] = LAYOUT_all( \
		                                                                                                   KC_TRNS, \
		KC_GRV , KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_TILD, \
		KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_MINS, KC_PLUS, KC_TRNS, KC_LBRC, KC_RBRC, KC_BSLS, KC_PIPE, \
		KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_UNDS, KC_GRV , KC_EQL , KC_TRNS, KC_LCBR, KC_RCBR, KC_TRNS, \
		KC_TRNS, KC_TRNS, KC_F12 , KC_F11 , KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

	[MEDIA] = LAYOUT_all( \
		                                                                                                   KC_TRNS, \
		KC_NO  , KC_MUTE, KC_VOLD, KC_VOLU, KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_PWR , KC_NO  , RESET  , \
		KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , \
		KC_NO  , KC_NO  , KC_SLEP, KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , \
		KC_NO  , AG_NORM, AG_SWAP, KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  )

};


#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    switch (index) {
        case 0:
            if (clockwise) {
                tap_code(KC_VOLU);
            } else {
                tap_code(KC_VOLD);
            }
        break;
    }
    return true;
}
#endif

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
}

static void render_name(void) {
    static const char PROGMEM mercutio_name[] = {
        0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 0x95, 0xB5, 0x96, 0xD5, 0xB6, 0xB6,
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };
    oled_write_P(mercutio_name, false);
}

void oled_task_user(void) {
    render_name();
}
#endif
