const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_default] = LAYOUT( \
        KC_1, KC_2, \
        LT(NUM,KC_ESC), MO(_special)),
    [_special] = LAYOUT(KC_A, KC_B, \
        KC_C, KC_D)
}
