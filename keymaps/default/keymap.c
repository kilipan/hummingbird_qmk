#include QMK_KEYBOARD_H
#include "hummingbird.h"

//// definitions
// layers
enum hummingbird_layers {
    _ALPHA,
    _NUM,
    _NAV,
    _SYM,
    _FUN
};
// custom keycodes
enum custom_keycodes {
    COLEMAK = SAFE_RANGE,
    NUM,
    NAV,
    SYM,
    FUN,
    KC_MDOT
};
// LEFT HAND HOME ROW MODS
#define CTL_A MT(MOD_LCTL, KC_A)
#define ALT_R MT(MOD_LALT, KC_R)
#define GUI_S MT(MOD_LGUI, KC_S)
#define SHT_T MT(MOD_LSFT, KC_T)
#define RALT_G MT(MOD_RALT, KC_G)
// RIGHT HAND HOME ROW MODS
#define RALT_M MT(MOD_RALT, KC_M)
#define SHT_N MT(MOD_RSFT, KC_N)
#define GUI_E MT(MOD_LGUI, KC_E)
#define ALT_I MT(MOD_LALT, KC_I)
#define CTL_O MT(MOD_LCTL, KC_O)
// LAYER TAP BEHAVIORS
#define NUM_ESC LT(_NUM, KC_ESC)
#define NAV_SPC LT(_NAV, KC_SPC)
#define SYM_ENT LT(_SYM, KC_ENT)
#define FUN_BSP LT(_FUN, KC_BSPC)
// OTHER
#define KC_MDOT LSFT(RALT(KC_SCLN))
// combos
enum combo_events {
    CAPSWORD_COMBO,
    Z_COMBO,
    V_COMBO,
    K_COMBO,
    SLASH_COMBO,
    COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;
const uint16_t PROGMEM capsword_combo[] = {SHT_T, SHT_N, COMBO_END};
const uint16_t PROGMEM z_combo[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM v_combo[] = {KC_C, KC_D, COMBO_END};
const uint16_t PROGMEM k_combo[] = {KC_H, KC_COMMA, COMBO_END};
const uint16_t PROGMEM slash_combo[] = {KC_COMMA, KC_DOT, COMBO_END};
combo_t key_combos[] = {
    [CAPSWORD_COMBO] = COMBO(capsword_combo, CW_TOGG),
    [Z_COMBO] = COMBO(z_combo, KC_Z),
    [V_COMBO] = COMBO(v_combo, KC_V),
    [K_COMBO] = COMBO(k_combo, KC_K),
    [SLASH_COMBO] = COMBO(slash_combo, KC_SLASH)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┬───┐┌───┬───┬───┬───┬───┐
     * │ Q │ W │ F │ P │ B ││ J │ L │ U │ Y │ ; │
     * ├───┼───┼───┼───┼───┤├───┼───┼───┼───┼───┤
     * │ A │ R │ S │ T │ G ││ M │ N │ E │ I │ O │
     * └───┼───┼───┼───┼───┘└───┼───┼───┼───┼───┘
     *     │ X │ C │ D │        │ H │ , │ . │
     *     └───┴───┼───┼───┐┌───┼───┼───┴───┘
     *             │ESC│SPC││RET│BSP│
     *             └───┴───┘└───┴───┘
     */
    [_ALPHA] = LAYOUT_hummingbird(
        KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,
        CTL_A,   ALT_R,   GUI_S,   SHT_T,   RALT_G,  RALT_M,  SHT_N,   GUI_E,   ALT_I,   CTL_O,  
                 KC_X,    KC_C,    KC_D,                      KC_H,    KC_COMM, KC_DOT,
                                   NUM_ESC, NAV_SPC, SYM_ENT, FUN_BSP
    ),
    [_NUM] = LAYOUT_hummingbird(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PLUS, KC_7,    KC_8,    KC_9,    KC_ASTR,
        KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, XXXXXXX, KC_MINS, KC_4,    KC_5,    KC_6,    KC_SLASH,
                 XXXXXXX, XXXXXXX, XXXXXXX,                   KC_1,    KC_2,    KC_3,
                                   _______, _______, KC_LSFT, KC_0
    ),
    [_NAV] = LAYOUT_hummingbird(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLD, KC_VOLU, KC_BSPC, KC_DEL,  KC_INS,   KC_MPLY,
        KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, KC_MUTE, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_TAB,
                 XXXXXXX, XXXXXXX, XXXXXXX,                   KC_HOME, XXXXXXX, KC_END,
                                   _______, _______, _______, _______
    ),
    [_SYM] = LAYOUT_hummingbird(
        KC_GRV,  XXXXXXX, KC_DQT,  KC_MDOT, KC_LBRC, KC_RBRC, KC_BSLS, KC_PIPE, KC_LT,   KC_GT,
        KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_AMPR, KC_ASTR, KC_PERC, KC_CIRC,
                 XXXXXXX, KC_QUOT, KC_UNDS,                   KC_MINS, KC_PLUS, KC_EQL,
                                   _______, KC_LSFT, _______, _______
    ),
    [_FUN] = LAYOUT_hummingbird(
        QK_RBT,  QK_BOOT, _______, _______, _______, XXXXXXX, KC_F7,   KC_F8,   KC_F9,   KC_F12,
        _______, _______, _______, _______, _______, XXXXXXX, KC_F4,   KC_F5,   KC_F6,   KC_F11,
                 _______, _______, _______,                   KC_F1,   KC_F2,   KC_F3,
                                   _______, _______, _______, _______
    )
};
