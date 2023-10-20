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
    FWDSLSH_BCKSLSH,
    R_ONE,
    F_TWO,
    V_THREE,
    C_THREE,
    T_FOUR,
    G_FIVE,
    B_SIX,
    Y_SEVEN,
    H_EIGHT,
    U_ZERO
};

// https://docs.qmk.fm/#/feature_tap_dance
tap_dance_action_t tap_dance_actions[] = {
    [FWDSLSH_BCKSLSH] = ACTION_TAP_DANCE_DOUBLE(KC_SLSH, KC_BSLS),
    [R_ONE] = ACTION_TAP_DANCE_DOUBLE(KC_R, KC_1),
    [F_TWO] = ACTION_TAP_DANCE_DOUBLE(KC_F, KC_2),
    [V_THREE] = ACTION_TAP_DANCE_DOUBLE(KC_V, KC_3),
    [C_THREE] = ACTION_TAP_DANCE_DOUBLE(KC_C, KC_3),
    [T_FOUR] = ACTION_TAP_DANCE_DOUBLE(KC_T, KC_4),
    [G_FIVE] = ACTION_TAP_DANCE_DOUBLE(KC_G, KC_5),
    [B_SIX] = ACTION_TAP_DANCE_DOUBLE(KC_B, KC_6),
    [Y_SEVEN] = ACTION_TAP_DANCE_DOUBLE(KC_Y, KC_7),
    [H_EIGHT] = ACTION_TAP_DANCE_DOUBLE(KC_H, KC_8),
    [U_ZERO] = ACTION_TAP_DANCE_DOUBLE(KC_U, KC_0),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[DEFAULT] = LAYOUT_1( \
		LT(NUM,KC_ESC)  , KC_Q          , KC_W          , KC_F          , KC_P          , KC_B          , KC_J          , KC_L                , KC_U          , KC_Y          , KC_SCLN       , KC_BSPC       , \
		LT(MEDIA,KC_TAB), KC_A          , KC_S          , KC_R          , KC_T          , KC_G          , KC_M          , KC_N                , KC_E          , KC_I          , KC_O          , KC_ENT        , \
		KC_GRV          , KC_LCTL       , KC_X          , KC_C          , KC_D          , KC_V          , KC_Z          , LT(SYM_FUNC,KC_QUOT), KC_K          , KC_H          , KC_COMM       , KC_DOT        , TD(FWDSLSH_BCKSLSH), KC_RSFT       , \
		KC_LGUI         , KC_LALT       , LSFT_T(KC_SPC), KC_SPC        , MO(NAV)       , KC_RALT       , KC_RGUI       ),

	[GAME] = LAYOUT_1( \
		KC_TAB , KC_Q   , KC_W   , KC_E  , TD(R_ONE)  , TD(T_FOUR) , TD(Y_SEVEN), TD(U_ZERO), KC_I, KC_O, KC_P   , KC_TRNS, \
		KC_SPC , KC_A   , KC_S   , KC_D  , TD(F_TWO)  , TD(G_FIVE) , TD(H_EIGHT), KC_J      , KC_K, KC_L, KC_SCLN, KC_TRNS, \
		KC_LCTL, KC_LCTL, KC_Z   , KC_X  , TD(C_THREE), TD(V_THREE), TD(B_SIX)  , KC_9      , KC_N, KC_M, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
		KC_ESC , KC_LALT, KC_LSFT, KC_SPC, KC_TRNS    , TO(DEFAULT), KC_TRNS    ),

	[NAV] = LAYOUT_1( \
		KC_NO, KC_NO, KC_NO  , KC_NO, KC_NO  , KC_NO   , KC_NO, KC_PGUP, KC_HOME, KC_UP  , KC_END       , KC_PGDN      , \
		KC_NO, KC_NO, KC_NO  , KC_NO, KC_NO  , TO(GAME), KC_NO, KC_NO  , KC_LEFT, KC_DOWN, KC_RGHT      , KC_TRNS      , \
		KC_NO, KC_NO, KC_NO  , KC_NO, KC_NO  , KC_NO   , KC_NO, KC_NO  , KC_NO  , KC_NO  , LCTL(KC_LEFT), LCTL(KC_RGHT), KC_NO, KC_NO, \
		KC_NO, KC_NO, KC_TRNS, KC_NO, KC_TRNS, KC_TRNS , KC_NO),

	[SYM_FUNC] = LAYOUT_1( \
		KC_GRV, KC_EXLM, KC_AT         , KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN     , KC_RPRN, KC_TILD, \
		KC_F1 , KC_F2  , KC_F3         , KC_F4  , KC_F5 , KC_MINS, KC_PLUS, KC_NO  , KC_LBRC, KC_RBRC     , KC_BSLS, KC_PIPE, \
		KC_F6 , KC_F6  , KC_F7         , KC_F8  , KC_F9 , KC_F10 , KC_UNDS, KC_TRNS, KC_EQL , LSFT(KC_DOT), KC_LCBR, KC_RCBR, KC_QUES, KC_NO , \
		KC_F12, KC_F11 , LSFT_T(KC_SPC), KC_ENT , KC_NO , KC_TRNS, KC_NO  ),

	[MEDIA] = LAYOUT_1( \
		KC_NO  , KC_MUTE, KC_VOLD , KC_VOLU, RGB_HUD, RGB_HUI, KC_NO  , KC_NO, KC_NO, KC_PWR, KC_NO, QK_BOOT, \
		KC_TRNS, RGB_TOG, RGB_RMOD, RGB_MOD, RGB_VAD, RGB_VAI, KC_NO  , KC_NO, KC_NO, KC_NO , KC_NO, KC_NO  , \
		KC_NO  , KC_NO  , RGB_M_P , RGB_SPD, RGB_SPI, RGB_SAD, RGB_SAI, KC_NO, KC_NO, KC_NO , KC_NO, KC_NO  , KC_NO, KC_NO, \
		RGB_M_K, RGB_M_G, KC_NO   , KC_NO  , KC_NO  , AG_NORM, AG_SWAP),

	[NUM] = LAYOUT_1( \
		KC_NO  , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9 , KC_0   , KC_BSPC, \
		KC_NO  , KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PLUS, KC_4   , KC_5   , KC_6 , KC_ASTR, KC_ENT , \
		KC_LCTL, KC_LSFT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MINS, KC_COMM, KC_1 , KC_2   , KC_3   , KC_SLSH, KC_TRNS, \
		KC_NO  , KC_TRNS, KC_TRNS, KC_TRNS, KC_0   , KC_DOT , KC_RCTL)

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
