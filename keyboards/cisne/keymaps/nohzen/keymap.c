#include QMK_KEYBOARD_H
#include "nohzen_common.h"


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_0(
          KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,             KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, TD(TD_BRC),
          KC_TAB,   GUI_A,   ALT_S,   SFT_D,   CTL_F,    KC_G,             KC_H,   CTL_J,   SFT_K,   ALT_L, GUI_CLN,    KC_QUOT,
         KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_B,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,    KC_RSFT,
         KC_LCTL,          KC_LGUI,           LW_SPC,           KC_ENT,   MO(2),          KC_LALT,           KC_ENT
    ),
    [1] = LAYOUT_0(
         KC_TRNS,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,             KC_6,    KC_7,    KC_8,    KC_9,    KC_0,      KC_NO,
         KC_TRNS,   KC_NO,   KC_NO, SFT_DEL, CTL_BT1, KC_BTN2,          KC_BSPC, CTL_ENT, SFT_MNS,  KC_EQL, KC_BSLS,     KC_GRV,
         KC_TRNS,   KC_NO,   KC_NO,   KC_NO, KC_BTN3,   KC_NO, KC_TRNS,  KC_SPC,  KC_ENT,   KC_NO,   KC_NO,   KC_NO,      KC_NO,
         KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,   MO(3),          KC_TRNS,          KC_TRNS
    ),
    [2] = LAYOUT_0(
         KC_TRNS,   KC_NO,   KC_NO, KC_WH_U,   KC_NO,   KC_NO,            KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_PSCR,     KC_NO,
         KC_TRNS,   KC_NO, KC_WH_L, KC_WH_D, KC_WH_R,   KC_NO,          KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT,   KC_NO,     KC_NO,
         KC_TRNS, KC_VOLD, KC_VOLU, KC_MUTE,   KC_NO,   KC_NO, KC_TRNS, KC_HOME, KC_PGDN, KC_PGUP,  KC_END,   KC_NO,     KC_NO,
         KC_TRNS,          KC_TRNS,            MO(3),          KC_TRNS, KC_TRNS,          KC_TRNS,          KC_TRNS
    ),
    [3] = LAYOUT_0(
         QK_BOOT,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_NO,
         KC_TRNS,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_NO,
         KC_TRNS,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_TRNS,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_NO,
         KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS, KC_TRNS,          KC_TRNS,          KC_TRNS
    )
};


bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index != 0) return 1;

    int cur_layer = biton32(layer_state);
    if (cur_layer == 0) {
        clockwise ? tap_code(KC_LEFT) : tap_code(KC_RIGHT);
    } else if (cur_layer == 1) {
        clockwise ? tap_code(KC_UP) : tap_code(KC_DOWN);
    }

    return 1;
}
