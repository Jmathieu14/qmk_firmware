#include QMK_KEYBOARD_H

// https://docs.qmk.fm/#/feature_tap_dance
// TODO: Make the following tap/hold funcs
// LALT/NUM
// TAP Enter/HOLD Backslash


enum layers {
    DEFAULT = 0,
    GAME,
    NAV,
    SYM_FUNC,
    MEDIA,
    NUM
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [DEFAULT] = LAYOUT_planck_mit( \
    KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_DEL, \
    KC_BSPC, LT(SYM_FUNC,KC_TAB), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, \
    KC_ENT, KC_LCTL, KC_Z, KC_X, KC_C, KC_V, KC_B, LT(GAME,KC_QUOT), KC_N, KC_M, KC_COMM, KC_DOT, \
    KC_SLSH, MO(NUM), KC_LSFT, KC_LGUI, KC_LALT, LSFT_T(KC_SPC), KC_SPC, MO(NAV), KC_RALT, KC_RCTL),

    [GAME] = LAYOUT_planck_mit( \
    KC_TAB, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
    KC_TRNS, KC_SPC, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
    KC_TRNS, KC_LCTL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
    KC_TRNS, KC_TRNS, KC_ESC, KC_LALT, KC_LSFT, KC_LSFT, KC_TRNS, KC_TRNS, KC_TRNS, TO(DEFAULT)),

    [NAV] = LAYOUT_planck_mit( \
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_PGUP, KC_HOME, KC_UP, KC_END, KC_PGDN, \
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, TO(GAME), KC_NO, KC_NO, KC_LEFT, KC_DOWN, KC_RGHT, \
    KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, LCTL(KC_LEFT), LCTL(KC_RGHT), \
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_TRNS, KC_TRNS, KC_NO),

    [SYM_FUNC] = LAYOUT_planck_mit( \
    KC_GRV, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_TILD, \
    KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_MINS, KC_PLUS, KC_NO, KC_LBRC, KC_RBRC, KC_BSLS, \
    KC_PIPE, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_UNDS, KC_TRNS, KC_EQL, KC_NO, KC_LCBR, KC_RCBR, \
    KC_QUES, KC_NO, KC_F12, KC_F11, KC_LALT, LSFT_T(KC_SPC), KC_ENT, KC_NO, KC_TRNS, KC_NO),

    [MEDIA] = LAYOUT_planck_mit( \
    KC_NO, KC_MUTE, KC_VOLD, KC_VOLU, RGB_HUD, RGB_HUI, KC_NO, KC_NO, KC_NO, KC_PWR, KC_NO, KC_NO, \
    RESET, KC_TRNS, RGB_TOG, RGB_RMOD, RGB_MOD, RGB_VAD, RGB_VAI, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, \
    KC_NO, KC_NO, RGB_M_P, RGB_SPD, RGB_SPI, RGB_SAD, RGB_SAI, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, \
    KC_NO, KC_NO, AG_NORM, AG_SWAP, RGB_M_K, RGB_M_G, KC_NO, KC_NO, KC_NO, KC_NO),

    [NUM] = LAYOUT_planck_mit( \
    KC_NO, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_SLSH, \
    KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PLUS, KC_4, KC_5, KC_6, KC_ASTR, \
    KC_ENT, KC_LCTL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MINS, KC_COMM, KC_1, KC_2, KC_3, \
    KC_DOT, KC_TRNS, KC_LSFT, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_0, KC_TRNS, KC_RCTL)

};


void matrix_init_user(void) {
  // set CapsLock LED to output and low
  setPinOutput(B1);
  writePinLow(B1);
  // set NumLock LED to output and low
  setPinOutput(B2);
  writePinLow(B2);
  // set ScrollLock LED to output and low
  setPinOutput(B3);
  writePinLow(B3);
}

void matrix_scan_user(void) {

}


void led_set_user(uint8_t usb_led) {
  if (IS_LED_ON(usb_led, USB_LED_NUM_LOCK)) {
    writePinHigh(B2);
  } else {
    writePinLow(B2);
  }
  if (IS_LED_ON(usb_led, USB_LED_CAPS_LOCK)) {
    writePinHigh(B1);
  } else {
    writePinLow(B1);
  }
}

//function for layer indicator LED
layer_state_t layer_state_set_user(layer_state_t state)
{
    if (get_highest_layer(state) == 1) {
        writePinHigh(B3);
	} else {
		writePinLow(B3);
    }
    return state;
}
