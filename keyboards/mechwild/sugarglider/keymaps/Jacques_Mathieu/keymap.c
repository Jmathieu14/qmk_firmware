// Copyright 2023 Kyle McCreery
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names {
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
    C_TWO,
    E_THREE,
    T_FOUR,
    G_FIVE,
    B_SIX,
    Y_SEVEN,
    H_EIGHT,
    N_NINE,
    U_ZERO,
    RSFT_RCTL
};

// https://docs.qmk.fm/#/feature_tap_dance
tap_dance_action_t tap_dance_actions[] = {
    [FWDSLSH_BCKSLSH] = ACTION_TAP_DANCE_DOUBLE(KC_SLSH, KC_BSLS),
    [R_ONE] = ACTION_TAP_DANCE_DOUBLE(KC_R, KC_1),
    [C_TWO] = ACTION_TAP_DANCE_DOUBLE(KC_C, KC_2),
    [E_THREE] = ACTION_TAP_DANCE_DOUBLE(KC_E, KC_3),
    [T_FOUR] = ACTION_TAP_DANCE_DOUBLE(KC_T, KC_4),
    [G_FIVE] = ACTION_TAP_DANCE_DOUBLE(KC_G, KC_5),
    [B_SIX] = ACTION_TAP_DANCE_DOUBLE(KC_B, KC_6),
    [Y_SEVEN] = ACTION_TAP_DANCE_DOUBLE(KC_Y, KC_7),
    [H_EIGHT] = ACTION_TAP_DANCE_DOUBLE(KC_H, KC_8),
    [N_NINE] = ACTION_TAP_DANCE_DOUBLE(KC_N, KC_9),
    [U_ZERO] = ACTION_TAP_DANCE_DOUBLE(KC_U, KC_0),
    [RSFT_RCTL] = ACTION_TAP_DANCE_DOUBLE(KC_RSFT, KC_RCTL),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

        [DEFAULT] = LAYOUT( \
                LT(NUM,KC_ESC)  , KC_Q          , KC_W          , KC_F          , KC_P          , KC_B          , TAP_UP        , KC_J                , KC_L          , KC_U          , KC_Y          , KC_SCLN            , KC_BSPC       , \
                LT(MEDIA,KC_TAB), KC_A          , KC_S          , KC_R          , KC_T          , KC_G          , KC_MUTE       , TAP_DN              , KC_M          , KC_N          , KC_E          , KC_I               , KC_O          , KC_ENT        , \
                KC_LCTL         , KC_X          , KC_C          , KC_D          , KC_V          , KC_Z          , TAP_TOG       , KC_K                , KC_H          , KC_COMM       , KC_DOT        , TD(FWDSLSH_BCKSLSH), TD(RSFT_RCTL) , \
                KC_BTN3         , KC_LGUI       , LSFT_T(KC_SPC), KC_LALT       , KC_BTN1       , KC_BTN2       , KC_RGUI       , LT(SYM_FUNC,KC_QUOT), KC_SPC        , MO(NAV)       , KC_MUTE       ),

        [GAME] = LAYOUT( \
                KC_TAB , KC_Q  , KC_W   , TD(E_THREE), TD(R_ONE), TD(T_FOUR), KC_TRNS    , TD(Y_SEVEN), TD(U_ZERO) , KC_I   , KC_O   , KC_P   , KC_TRNS, \
                KC_SPC , KC_A  , KC_S   , KC_D       , KC_F     , TD(G_FIVE), KC_TRNS    , KC_TRNS    , TD(H_EIGHT), KC_J   , KC_K   , KC_L   , KC_SCLN, KC_TRNS, \
                KC_LCTL, KC_Z  , KC_X   , TD(C_TWO)  , KC_V     , TD(B_SIX) , KC_TRNS    , TD(N_NINE) , KC_M       , KC_COMM, KC_DOT , KC_SLSH, KC_TRNS, \
                KC_TRNS, KC_ESC, KC_LSFT, KC_LALT    , KC_TRNS  , KC_TRNS   , TO(DEFAULT), KC_TRNS    , KC_TRNS    , KC_TRNS, KC_TRNS),

        [NAV] = LAYOUT( \
                KC_NO  , KC_NO, KC_NO, KC_NO, KC_NO, KC_NO   , DPI_UP  , KC_NO , KC_PGUP, KC_HOME      , KC_UP        , KC_END , KC_PGDN, \
                KC_NO  , KC_NO, KC_NO, KC_NO, KC_NO, TO(GAME), KC_NO   , DPI_DN, KC_NO  , KC_NO        , KC_LEFT      , KC_DOWN, KC_RGHT, KC_NO, \
                KC_NO  , KC_NO, KC_NO, KC_NO, KC_NO, KC_NO   , DPI_FINE, KC_NO , KC_NO  , LCTL(KC_LEFT), LCTL(KC_RGHT), KC_NO  , KC_NO  , \
                KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO   , KC_NO   , KC_NO , KC_NO  , KC_TRNS      , KC_TRNS      ),

        [SYM_FUNC] = LAYOUT( \
                KC_GRV , KC_EXLM, KC_AT , KC_HASH       , KC_DLR , KC_PERC, KC_TRNS, KC_CIRC, KC_AMPR, KC_LPRN, KC_RPRN, KC_ASTR, KC_TILD, \
                KC_F1  , KC_F2  , KC_F3 , KC_F4         , KC_F5  , KC_MINS, KC_TRNS, KC_TRNS, KC_PLUS, KC_TRNS, KC_LBRC, KC_RBRC, KC_BSLS, KC_PIPE, \
                KC_F6  , KC_F7  , KC_F8 , KC_F9         , KC_F10 , KC_UNDS, KC_TRNS, KC_EQL , KC_GT  , KC_LCBR, KC_RCBR, KC_QUES, KC_TRNS, \
                KC_TRNS, KC_F12 , KC_F11, LSFT_T(KC_SPC), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

        [MEDIA] = LAYOUT( \
                KC_NO  , KC_NO  , KC_NO   , KC_NO  , RGB_HUD, RGB_HUI, KC_NO, KC_NO, KC_NO, KC_NO, KC_PWR, KC_NO, QK_BOOT, \
                KC_TRNS, RGB_TOG, RGB_RMOD, RGB_MOD, RGB_VAD, RGB_VAI, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO , KC_NO, KC_NO  , KC_NO, \
                KC_NO  , BL_TOGG, BL_DOWN , BL_UP  , RGB_SAD, RGB_SAI, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO , KC_NO, KC_NO  , \
                KC_NO  , BL_BRTG, KC_NO   , KC_NO  , KC_NO  , KC_NO  , KC_NO, KC_NO, KC_NO, KC_NO, KC_NO ),

        [NUM] = LAYOUT( \
                KC_NO  , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_TRNS, KC_6   , KC_7   , KC_8  , KC_9   , KC_0   , KC_BSPC, \
                KC_NO  , KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PLUS, KC_4  , KC_5   , KC_6   , KC_ASTR, KC_ENT, \
                KC_LCTL, KC_LSFT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MINS, KC_1   , KC_2  , KC_3   , KC_SLSH, KC_TRNS, \
                KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_SPC , KC_0   , KC_DOT, KC_TRNS)

};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [DEFAULT] =  { ENCODER_CCW_CW(KC_WH_D, KC_WH_U), ENCODER_CCW_CW(KC_NO,   KC_NO),    ENCODER_CCW_CW(KC_PGUP, KC_PGDN),  ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
    [GAME] =     { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_LEFT, KC_RIGHT), ENCODER_CCW_CW(KC_HOME, KC_END),   ENCODER_CCW_CW(KC_TRNS, KC_TRNS)  },
    [NAV] =      { ENCODER_CCW_CW(KC_WH_L, KC_WH_R), ENCODER_CCW_CW(KC_HOME, KC_END),   ENCODER_CCW_CW(KC_LEFT, KC_RIGHT), ENCODER_CCW_CW(KC_TRNS, KC_TRNS)  },
    [SYM_FUNC] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_BRID, KC_BRIU),  ENCODER_CCW_CW(KC_TRNS, KC_TRNS),  ENCODER_CCW_CW(KC_TRNS, KC_TRNS)  },
    [MEDIA] =    { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_BRID, KC_BRIU),  ENCODER_CCW_CW(KC_TRNS, KC_TRNS),  ENCODER_CCW_CW(KC_TRNS, KC_TRNS)  },
    [NUM] =      { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_HOME, KC_END),   ENCODER_CCW_CW(KC_TRNS, KC_TRNS),  ENCODER_CCW_CW(KC_TRNS, KC_TRNS)  }
};
#endif

void pointing_device_init_user(void) {
    set_auto_mouse_layer(_MOUSE);
    set_auto_mouse_enable(true);
}
