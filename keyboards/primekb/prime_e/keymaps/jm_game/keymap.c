#include QMK_KEYBOARD_H

enum layers {
    DEFAULT = 0,
    GAME,
    NAV,
    SYM_FUNC,
    MEDIA,
    NUM
};

enum tap_dances {
    NTR_BCKSLSH,
    R_ONE,
    F_TWO,
    V_THREE,
    T_FOUR,
    G_FIVE,
    B_SIX,
    Y_SEVEN,
    H_EIGHT,
    N_NINE,
    U_ZERO
};

// https://docs.qmk.fm/#/feature_tap_dance
tap_dance_action_t tap_dance_actions[] = {
    [NTR_BCKSLSH] = ACTION_TAP_DANCE_DOUBLE(KC_ENT, KC_BSLS),
    [R_ONE] = ACTION_TAP_DANCE_DOUBLE(KC_R, KC_1),
    [F_TWO] = ACTION_TAP_DANCE_DOUBLE(KC_F, KC_2),
    [V_THREE] = ACTION_TAP_DANCE_DOUBLE(KC_V, KC_3),
    [T_FOUR] = ACTION_TAP_DANCE_DOUBLE(KC_T, KC_4),
    [G_FIVE] = ACTION_TAP_DANCE_DOUBLE(KC_G, KC_5),
    [B_SIX] = ACTION_TAP_DANCE_DOUBLE(KC_B, KC_6),
    [Y_SEVEN] = ACTION_TAP_DANCE_DOUBLE(KC_Y, KC_7),
    [H_EIGHT] = ACTION_TAP_DANCE_DOUBLE(KC_H, KC_8),
    [N_NINE] = ACTION_TAP_DANCE_DOUBLE(KC_N, KC_9),
    [U_ZERO] = ACTION_TAP_DANCE_DOUBLE(KC_U, KC_0),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[DEFAULT] = LAYOUT( \
		LT(NUM,KC_ESC)  , KC_Q          , KC_W          , KC_E          , KC_R          , KC_T          , KC_Y                , KC_U          , KC_I, KC_O   , KC_P   , KC_DEL         , KC_BSPC, \
		LT(MEDIA,KC_TAB), KC_A          , KC_S          , KC_D          , KC_F          , KC_G          , KC_H                , KC_J          , KC_K, KC_L   , KC_SCLN, TD(NTR_BCKSLSH),          \
		KC_LCTL         , KC_Z          , KC_X          , KC_C          , KC_V          , KC_B          , LT(SYM_FUNC,KC_QUOT), KC_N          , KC_M, KC_COMM, KC_DOT , KC_SLSH        , MO(NUM), \
		KC_LSFT         , KC_LGUI       , KC_LALT       , LSFT_T(KC_SPC), KC_SPC        , MO(NAV)       , KC_RALT             , KC_RCTL       ),

	[GAME] = LAYOUT( \
		KC_TAB , KC_TRNS, KC_TRNS, KC_TRNS, TD(R_ONE)  , TD(T_FOUR), TD(Y_SEVEN), TD(U_ZERO) , KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
		KC_SPC , KC_TRNS, KC_TRNS, KC_TRNS, TD(F_TWO)  , TD(G_FIVE), TD(H_EIGHT), KC_TRNS    , KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          \
		KC_LCTL, KC_TRNS, KC_TRNS, KC_TRNS, TD(V_THREE), TD(B_SIX) , KC_TRNS    , TD(N_NINE) , KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
		KC_ESC , KC_LALT, KC_LSFT, KC_LSFT, KC_TRNS    , KC_TRNS   , KC_TRNS    , TO(DEFAULT)),

	[NAV] = LAYOUT( \
		KC_NO, KC_NO, KC_NO, KC_NO  , KC_NO, KC_NO   , KC_NO  , KC_PGUP, KC_HOME, KC_UP        , KC_END       , KC_PGDN, KC_NO, \
		KC_NO, KC_NO, KC_NO, KC_NO  , KC_NO, TO(GAME), KC_NO  , KC_NO  , KC_LEFT, KC_DOWN      , KC_RGHT      , KC_TRNS,        \
		KC_NO, KC_NO, KC_NO, KC_NO  , KC_NO, KC_NO   , KC_NO  , KC_NO  , KC_NO  , LCTL(KC_LEFT), LCTL(KC_RGHT), KC_NO  , KC_NO, \
		KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_TRNS , KC_TRNS, KC_NO  ),

	[SYM_FUNC] = LAYOUT( \
		KC_GRV, KC_EXLM, KC_AT  , KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR,      KC_LPRN, KC_RPRN, KC_TILD, KC_GRV, \
		KC_F1 , KC_F2  , KC_F3  , KC_F4  , KC_F5 , KC_MINS, KC_PLUS, KC_NO  , KC_LBRC,      KC_RBRC, KC_BSLS, KC_PIPE,         \
		KC_F6 , KC_F7  , KC_F8  , KC_F9  , KC_F10, KC_UNDS, KC_TRNS, KC_EQL , LSFT(KC_DOT), KC_LCBR, KC_RCBR, KC_QUES, KC_NO , \
		KC_F12, KC_F11          , KC_LALT, LSFT_T(KC_SPC) , KC_ENT          , KC_NO                         , KC_TRNS, KC_NO),

	[MEDIA] = LAYOUT( \
		KC_NO  , KC_MUTE, KC_VOLD , KC_VOLU, RGB_HUD, RGB_HUI, KC_NO, KC_NO, KC_NO, KC_PWR, KC_NO, KC_NO, RESET, \
		KC_TRNS, RGB_TOG, RGB_RMOD, RGB_MOD, RGB_VAD, RGB_VAI, KC_NO, KC_NO, KC_NO, KC_NO , KC_NO, KC_NO,        \
		KC_NO  , RGB_M_P, RGB_SPD , RGB_SPI, RGB_SAD, RGB_SAI, KC_NO, KC_NO, KC_NO, KC_NO , KC_NO, KC_NO, KC_NO, \
		AG_NORM, AG_SWAP, RGB_M_K , RGB_M_G, KC_NO  , KC_NO  , KC_NO, KC_NO),

	[NUM] = LAYOUT( \
		KC_NO  , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8 , KC_9 , KC_0   , KC_SLSH, KC_BSPC, \
		KC_NO  , KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PLUS, KC_4   , KC_5 , KC_6 , KC_ASTR, KC_ENT ,          \
		KC_LCTL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MINS, KC_COMM, KC_1 , KC_2 , KC_3   , KC_DOT , KC_TRNS, \
		KC_LSFT, KC_NO  , KC_TRNS, KC_TRNS, KC_TRNS, KC_0   , KC_TRNS, KC_RCTL)

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

}

// function for layer indicator LED
layer_state_t layer_state_set_user(layer_state_t state) {
    switch(get_highest_layer(state)) {
        case NUM:
            writePinHigh(B3);
            break;
        case MEDIA:
            writePinHigh(B2);
            break;
        case SYM_FUNC:
            writePinHigh(B1);
            writePinHigh(B2);
            break;
        case NAV:
            writePinHigh(B1);
            break;
        default:
            writePinLow(B1);
            writePinLow(B2);
            writePinLow(B3);
            break;
    }
    return state;
}
