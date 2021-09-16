const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
// HERE IS A COMMENT
    [_default] = LAYOUT( \
        KC_1, KC_2, /* I AM WRITING A COMMENT HERE BECAUSE I HATE COMPILERS */ \
        KC_3, KC_4),
    [_special] = LAYOUT(KC_A, KC_B, \
        KC_C, KC_D)
}
