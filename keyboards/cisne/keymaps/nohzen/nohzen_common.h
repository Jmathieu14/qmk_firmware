#pragma once


/* tap dance */
enum {
    TD_BRC,
};
tap_dance_action_t tap_dance_actions[] = {
    [TD_BRC] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_RBRC),
};


/* combos */
const uint16_t PROGMEM vb_combo[] = {KC_V, KC_B, COMBO_END};
const uint16_t PROGMEM nm_combo[] = {KC_N, KC_M, COMBO_END};
const uint16_t PROGMEM qw_combo[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM as_combo[] = {KC_A, KC_S, COMBO_END}; // ミスタイプが発生するので使えない
combo_t key_combos[COMBO_COUNT] = {
  COMBO(vb_combo, KC_LNG2),
  COMBO(nm_combo, KC_LNG1),
  COMBO(qw_combo, KC_TAB),
};


/* macros */
#define LW_SPC LT(1, KC_SPC)
#define CTL_F MT(MOD_LCTL, KC_F)
#define CTL_J MT(MOD_RCTL, KC_J)
#define CTL_BT1 KC_BTN1
#define CTL_ENT MT(MOD_LCTL, KC_ENT)
#define SFT_D MT(MOD_LSFT, KC_D)
#define SFT_K MT(MOD_RSFT, KC_K)
#define SFT_DEL MT(MOD_LSFT, KC_DEL)
#define SFT_MNS MT(MOD_LSFT, KC_MINUS)
#define ALT_S KC_S
#define ALT_L MT(MOD_LALT, KC_L)
#define GUI_A KC_A
#define GUI_CLN MT(MOD_RGUI, KC_SCLN)


/* Setting */
bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CTL_F:
            return false;
        case CTL_J:
            return false;
        case CTL_BT1:
            return false;
        case CTL_ENT:
            return false;
        case SFT_D:
            return false;
        case SFT_K:
            return false;
        case SFT_DEL:
            return false;
        case SFT_MNS:
            return false;
        case GUI_A:
            return false;
        case GUI_CLN:
            return false;
        case ALT_S:
            return false;
        case ALT_L:
            return false;
        default:
            return true;
    }
}
uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(1, KC_SPC):
            return 0;
        default:
            return QUICK_TAP_TERM;
    }
}
