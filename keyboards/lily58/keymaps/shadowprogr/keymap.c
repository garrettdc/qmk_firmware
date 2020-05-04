#include QMK_KEYBOARD_H

#include "shadowprogr.h"

#if defined(PROTOCOL_LUFA)
#    include "lufa.h"
#    include "split_util.h"
#endif
#if defined(OLED_DRIVER_ENABLE)
#    include "ssd1306.h"
#endif

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT( \
    /* ,-----------------------------------------------------.                         ,-----------------------------------------------------. */
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                              KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
    /* |--------+--------+--------+--------+--------+--------|                         |--------+--------+--------+--------+--------+--------| */
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                              KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS, \
    /* |--------+--------+--------+--------+--------+--------|                         |--------+--------+--------+--------+--------+--------| */
        CTL_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                              KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, CTL_QUT, \
    /* |--------+--------+--------+--------+--------+--------|--------.       ,--------|--------+--------+--------+--------+--------+--------| */
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_MINS,         KC_EQL,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, \
    /* `----------------------------------------------------/--------/         \--------\----------------------------------------------------' */
                              KC_LALT, KC_LGUI, KC_SPC,     LOWER,               RAISE,      KC_BSPC, KC_RGUI, NUMPAD                         \
    /*                       `--------------------------' '--------'             '--------' `--------------------------'                       */
    ),

    [_DVORAK] = LAYOUT( \
    /* ,-----------------------------------------------------.                         ,-----------------------------------------------------. */
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                              KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
    /* |--------+--------+--------+--------+--------+--------|                         |--------+--------+--------+--------+--------+--------| */
        KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,                              KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSLS, \
    /* |--------+--------+--------+--------+--------+--------|                         |--------+--------+--------+--------+--------+--------| */
        CTL_ESC, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,                              KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    CTL_SLS, \
    /* |--------+--------+--------+--------+--------+--------|--------.       ,--------|--------+--------+--------+--------+--------+--------| */
        KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_MINS,         KC_EQL,  KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_RSFT, \
    /* `----------------------------------------------------/--------/         \--------\----------------------------------------------------' */
                              KC_LALT, KC_LGUI, KC_SPC,     LOWER,               RAISE,      KC_BSPC, KC_RGUI, NUMPAD                         \
    /*                       `--------------------------' '--------'             '--------' `--------------------------'                       */
    ),

    [_COLEMAK] = LAYOUT( \
    /* ,-----------------------------------------------------.                         ,-----------------------------------------------------. */
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                              KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
    /* |--------+--------+--------+--------+--------+--------|                         |--------+--------+--------+--------+--------+--------| */
        KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,                              KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSLS, \
    /* |--------+--------+--------+--------+--------+--------|                         |--------+--------+--------+--------+--------+--------| */
        CTL_ESC, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,                              KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    CTL_QUT, \
    /* |--------+--------+--------+--------+--------+--------|--------.       ,--------|--------+--------+--------+--------+--------+--------| */
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_MINS,         KC_EQL,  KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, \
    /* `----------------------------------------------------/--------/         \--------\----------------------------------------------------' */
                              KC_LALT, KC_LGUI, KC_SPC,     LOWER,               RAISE,      KC_BSPC, KC_RGUI, NUMPAD                         \
    /*                       `--------------------------' '--------'             '--------' `--------------------------'                       */
    ),

    [_NUMPAD] = LAYOUT( \
    /* ,-----------------------------------------------------.                         ,-----------------------------------------------------. */
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                           KC_NLCK, KC_P7,   KC_P8,   KC_P9,   KC_PSLS, KC_BSPC, \
    /* |--------+--------+--------+--------+--------+--------|                         |--------+--------+--------+--------+--------+--------| */
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                           XXXXXXX, KC_P4,   KC_P5,   KC_P6,   KC_PAST, XXXXXXX, \
    /* |--------+--------+--------+--------+--------+--------|                         |--------+--------+--------+--------+--------+--------| */
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                           XXXXXXX, KC_P1,   KC_P2,   KC_P3,   KC_PMNS, XXXXXXX, \
    /* |--------+--------+--------+--------+--------+--------|--------.       ,--------|--------+--------+--------+--------+--------+--------| */
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,         XXXXXXX, XXXXXXX, KC_P0,   KC_P00,  KC_PDOT, KC_PPLS, KC_PENT, \
    /* `----------------------------------------------------/--------/         \--------\----------------------------------------------------' */
                              XXXXXXX, XXXXXXX, XXXXXXX,    _______,             _______,    _______, XXXXXXX, _______                        \
    /*                       `--------------------------' '--------'             '--------' `--------------------------'                       */
    ),

    [_LOWER] = LAYOUT( \
    /* ,-----------------------------------------------------.                         ,-----------------------------------------------------. */
        KC_F11,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                             KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F12,  \
    /* |--------+--------+--------+--------+--------+--------|                         |--------+--------+--------+--------+--------+--------| */
        _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                           KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______, \
    /* |--------+--------+--------+--------+--------+--------|                         |--------+--------+--------+--------+--------+--------| */
        KC_CAPS, _______, _______, _______, _______, _______,                           KC_UNDS, KC_MINS, KC_EQL,  KC_LCBR, KC_RCBR, _______, \
    /* |--------+--------+--------+--------+--------+--------|--------.       ,--------|--------+--------+--------+--------+--------+--------| */
        _______, _______, _______, _______, _______, _______, RESCUE,          _______, _______, _______, _______, KC_LBRC, KC_RBRC, _______, \
    /* `----------------------------------------------------/--------/         \--------\----------------------------------------------------' */
                              _______, _______, _______,    _______,             _______,    KC_DEL,  _______, _______                        \
    /*                       `--------------------------' '--------'             '--------' `--------------------------'                       */
    ),

    [_RAISE] = LAYOUT( \
    /* ,-----------------------------------------------------.                         ,-----------------------------------------------------. */
        KC_F11,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                             KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F12,  \
    /* |--------+--------+--------+--------+--------+--------|                         |--------+--------+--------+--------+--------+--------| */
        _______, KC_VOLU, KC_INS,  KC_HOME, KC_PGUP, _______,                           _______, _______, _______, _______, _______, _______, \
    /* |--------+--------+--------+--------+--------+--------|                         |--------+--------+--------+--------+--------+--------| */
        _______, KC_VOLD, KC_DEL,  KC_END,  KC_PGDN, _______,                           KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______, \
    /* |--------+--------+--------+--------+--------+--------|--------.       ,--------|--------+--------+--------+--------+--------+--------| */
        _______, _______, _______, KC_MPRV, KC_MNXT, KC_MPLY, _______,         RESCUE,  _______, _______, _______, _______, _______, _______, \
    /* `----------------------------------------------------/--------/         \--------\----------------------------------------------------' */
                              _______, _______, _______,    _______,             _______,    _______, _______, _______                        \
    /*                       `--------------------------' '--------'             '--------' `--------------------------'                       */
    ),

    [_ADJUST] = LAYOUT( \
    /* ,-----------------------------------------------------.                         ,-----------------------------------------------------. */
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    /* |--------+--------+--------+--------+--------+--------|                         |--------+--------+--------+--------+--------+--------| */
        EEP_RST, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QWERTY,                            XXXXXXX, RGB_TOG, RGB_MOD, XXXXXXX, XXXXXXX, XXXXXXX, \
    /* |--------+--------+--------+--------+--------+--------|                         |--------+--------+--------+--------+--------+--------| */
        RESET,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DVORAK,                            XXXXXXX, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, XXXXXXX, \
    /* |--------+--------+--------+--------+--------+--------|--------.       ,--------|--------+--------+--------+--------+--------+--------| */
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, COLEMAK, XXXXXXX,         XXXXXXX, XXXXXXX, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, XXXXXXX, \
    /* `----------------------------------------------------/--------/         \--------\----------------------------------------------------' */
                              XXXXXXX, XXXXXXX, XXXXXXX,    _______,             _______,    XXXXXXX, XXXXXXX, XXXXXXX                        \
    /*                       `--------------------------' '--------'             '--------' `--------------------------'                       */
    ),

    [_RESCUE] = LAYOUT( \
    /* ,-----------------------------------------------------.                         ,-----------------------------------------------------. */
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    /* |--------+--------+--------+--------+--------+--------|                         |--------+--------+--------+--------+--------+--------| */
        EEP_RST, RGB_VAI, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_VAI, EEP_RST, \
    /* |--------+--------+--------+--------+--------+--------|                         |--------+--------+--------+--------+--------+--------| */
        RESET,   RGB_VAD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_VAD, RESET,   \
    /* |--------+--------+--------+--------+--------+--------|--------.       ,--------|--------+--------+--------+--------+--------+--------| */
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RESCUE,          RESCUE,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    /* `----------------------------------------------------/--------/         \--------\----------------------------------------------------' */
                              XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,             XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX                        \
    /*                       `--------------------------' '--------'             '--------' `--------------------------'                       */
    )
/*
    [_TEMPLATE] = LAYOUT( \
       ,-----------------------------------------------------.                         ,-----------------------------------------------------.
        _______, _______, _______, _______, _______, _______,                           _______, _______, _______, _______, _______, _______, \
       |--------+--------+--------+--------+--------+--------|                         |--------+--------+--------+--------+--------+--------|
        _______, _______, _______, _______, _______, _______,                           _______, _______, _______, _______, _______, _______, \
       |--------+--------+--------+--------+--------+--------|                         |--------+--------+--------+--------+--------+--------|
        _______, _______, _______, _______, _______, _______,                           _______, _______, _______, _______, _______, _______, \
       |--------+--------+--------+--------+--------+--------|--------.       ,--------|--------+--------+--------+--------+--------+--------|
        _______, _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______, _______, \
       `----------------------------------------------------/--------/         \--------\----------------------------------------------------'
                              _______, _______, _______,    _______,             _______,    _______, _______, _______                        \
                             `--------------------------' '--------'             '--------' `--------------------------'
    )
*/
};
// clang-format on

// clang-format off
#ifdef RGB_MATRIX_ENABLE
led_config_t g_led_config = { {
    {  11,  10,   9,   8,   7,   6 },
    {  12,  13,  14,  15,  16,  17 },
    {  23,  22,  21,  20,  19,  18 },
    {  24,  25,  26,  27,  28,  29 },
    {  NO_LED,      34,  33,  32,  31,  30 },
    {  46,  45,  44,  43,  42,  41 },
    {  47,  48,  49,  50,  51,  52 },
    {  58,  57,  56,  55,  54,  53 },
    {  59,  60,  61,  62,  63,  64 },
    {  NO_LED,      69,  68,  67,  66,  65 }
}, {
    {  89, 55 }, {  54, 52 }, {  19, 42 }, {  19, 13 }, {  54,  9 }, {  89, 12 }, {  89,  4 },
    {  72,  3 }, {  54,  1 }, {  37,  2 }, {  19,  6 }, {   1,  7 }, {   1, 21 }, {  19, 20 },
    {  37, 17 }, {  54, 16 }, {  72, 17 }, {  89, 19 }, {  89, 33 }, {  72, 31 }, {  54, 30 },
    {  37, 31 }, {  19, 35 }, {   1, 36 }, {   1, 50 }, {  19, 49 }, {  37, 46 }, {  54, 44 },
    {  72, 46 }, {  89, 47 }, { 107, 40 }, { 104, 62 }, {  81, 61 }, {  63, 60 }, {  45, 60 },
    { 135, 55 }, { 170, 52 }, { 205, 42 }, { 205, 13 }, { 170,  9 }, { 135, 12 }, { 135,  4 },
    { 152,  3 }, { 170,  1 }, { 187,  2 }, { 205,  6 }, { 223,  7 }, { 223, 21 }, { 205, 20 },
    { 187, 17 }, { 170, 16 }, { 152, 17 }, { 135, 19 }, { 135, 33 }, { 152, 31 }, { 170, 30 },
    { 187, 31 }, { 205, 35 }, { 223, 36 }, { 223, 50 }, { 205, 49 }, { 187, 46 }, { 170, 44 },
    { 152, 46 }, { 135, 47 }, { 117, 40 }, { 120, 62 }, { 143, 61 }, { 161, 60 }, { 179, 60 }
}, {
    2, 2, 2, 2, 2, 2, 4,
    4, 4, 4, 4, 1, 1, 4,
    4, 4, 4, 4, 4, 4, 4,
    4, 4, 1, 1, 4, 4, 4,
    4, 4, 4, 1, 1, 1, 1,
    2, 2, 2, 2, 2, 2, 4,
    4, 4, 4, 4, 1, 1, 4,
    4, 4, 4, 4, 4, 4, 4,
    4, 4, 1, 1, 4, 4, 4,
    4, 4, 4, 1, 1, 1, 1
} };
#endif
// clang-format off

void matrix_init_keymap(void) {
#ifdef RGB_MATRIX_ENABLE
    if (!isLeftHand) {
        // clang-format off
        g_led_config = (led_config_t) { {
            {  46,  45,  44,  43,  42,  41 },
            {  47,  48,  49,  50,  51,  52 },
            {  58,  57,  56,  55,  54,  53 },
            {  59,  60,  61,  62,  63,  64 },
            {  NO_LED,      69,  68,  67,  66,  65 },
            {  11,  10,   9,   8,   7,   6 },
            {  12,  13,  14,  15,  16,  17 },
            {  23,  22,  21,  20,  19,  18 },
            {  24,  25,  26,  27,  28,  29 },
            {  NO_LED,      34,  33,  32,  31,  30 }
        }, {
            { 135, 55 }, { 170, 52 }, { 205, 42 }, { 205, 13 }, { 170,  9 }, { 135, 12 }, { 135,  4 },
            { 152,  3 }, { 170,  1 }, { 187,  2 }, { 205,  6 }, { 223,  7 }, { 223, 21 }, { 205, 20 },
            { 187, 17 }, { 170, 16 }, { 152, 17 }, { 135, 19 }, { 135, 33 }, { 152, 31 }, { 170, 30 },
            { 187, 31 }, { 205, 35 }, { 223, 36 }, { 223, 50 }, { 205, 49 }, { 187, 46 }, { 170, 44 },
            { 152, 46 }, { 135, 47 }, { 117, 40 }, { 120, 62 }, { 143, 61 }, { 161, 60 }, { 179, 60 },
            {  89, 55 }, {  54, 52 }, {  19, 42 }, {  19, 13 }, {  54,  9 }, {  89, 12 }, {  89,  4 },
            {  72,  3 }, {  54,  1 }, {  37,  2 }, {  19,  6 }, {   1,  7 }, {   1, 21 }, {  19, 20 },
            {  37, 17 }, {  54, 16 }, {  72, 17 }, {  89, 19 }, {  89, 33 }, {  72, 31 }, {  54, 30 },
            {  37, 31 }, {  19, 35 }, {   1, 36 }, {   1, 50 }, {  19, 49 }, {  37, 46 }, {  54, 44 },
            {  72, 46 }, {  89, 47 }, { 107, 40 }, { 104, 62 }, {  81, 61 }, {  63, 60 }, {  45, 60 }
        }, {
            2, 2, 2, 2, 2, 2, 4,
            4, 4, 4, 4, 1, 1, 4,
            4, 4, 4, 4, 4, 4, 4,
            4, 4, 1, 1, 4, 4, 4,
            4, 4, 4, 1, 1, 1, 1,
            2, 2, 2, 2, 2, 2, 4,
            4, 4, 4, 4, 1, 1, 4,
            4, 4, 4, 4, 4, 4, 4,
            4, 4, 1, 1, 4, 4, 4,
            4, 4, 4, 1, 1, 1, 1
        } };
        // clang-format off
    }
#endif
}
