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
#define LAYOUT_lily58_base( \
    K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A,      \
    K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, \
    K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A       \
  ) \
  LAYOUT_wrapper( \
    KC_GRV,  ________________NUMBER_LEFT________________,                           ________________NUMBER_RIGHT_______________, KC_BSPC, \
    KC_TAB,  K01,     K02,     K03,     K04,     K05,                               K06,     K07,     K08,     K09,     K0A,     KC_BSLS, \
    CTL_ESC, K11,     K12,     K13,     K14,     K15,                               K16,     K17,     K18,     K19,     K1A,     K1B,     \
    KC_LSFT, K21,     K22,     K23,     K24,     K25,     KC_MINS,         KC_EQL,  K26,     K27,     K28,     K29,     K2A,     KC_RSFT, \
                               KC_LALT, KC_LGUI, KC_SPC,  LOWER,           RAISE,   KC_BSPC, KC_RGUI, NUMPAD                              \
  )
// clang-format on

#define LAYOUT_lily58_base_wrapper(...) LAYOUT_lily58_base(__VA_ARGS__)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_lily58_base_wrapper( \
        _________________QWERTY_L1_________________, _________________QWERTY_R1_________________,          \
        _________________QWERTY_L2_________________, _________________QWERTY_R2_________________, CTL_QUT, \
        _________________QWERTY_L3_________________, _________________QWERTY_R3_________________           \
    ),

    [_DVORAK] = LAYOUT_lily58_base_wrapper( \
        _________________DVORAK_L1_________________, _________________DVORAK_R1_________________,          \
        _________________DVORAK_L2_________________, _________________DVORAK_R2_________________, CTL_SLS, \
        _________________DVORAK_L3_________________, _________________DVORAK_R3_________________           \
    ),

    [_COLEMAK] = LAYOUT_lily58_base_wrapper( \
        ________________COLEMAK_DH_L1______________, ________________COLEMAK_DH_R1______________,          \
        ________________COLEMAK_DH_L2______________, ________________COLEMAK_DH_R2______________, CTL_QUT, \
        ________________COLEMAK_DH_L3______________, ________________COLEMAK_DH_R3______________           \
    ),

    [_QWERTY_OVERLAY] = LAYOUT_wrapper( \
        _______, ___________________________________________,                           ___________________________________________, _______,  \
        _______, _________________QWERTY_L1_________________,                           _________________QWERTY_R1_________________, _______, \
        _______, _________________QWERTY_L2_________________,                           _________________QWERTY_R2_________________, _______, \
        _______, _________________QWERTY_L3_________________, _______,         _______, _________________QWERTY_R3_________________, _______, \
                                   __________________________________,         __________________________________                             \
    ),

    [_NUMPAD] = LAYOUT_wrapper( \
        _____________________DISABLED_______________________,                           KC_NLCK, ____________NUMPAD_R0_____________, KC_BSPC, \
        _____________________DISABLED_______________________,                           XXXXXXX, ____________NUMPAD_R1_____________, XXXXXXX, \
        _____________________DISABLED_______________________,                           XXXXXXX, ____________NUMPAD_R2_____________, XXXXXXX, \
        _____________________DISABLED_______________________, XXXXXXX,         XXXXXXX, XXXXXXX, ____________NUMPAD_R3_____________, KC_PENT, \
                                   ____________DISABLED______________,         _______, _______, XXXXXXX, _______                             \
    ),

    [_LOWER] = LAYOUT_wrapper( \
        KC_F11,  _________________FUNC_LEFT_________________,                           _________________FUNC_RIGHT________________, KC_F12,  \
        _______, _________________LOWER_L1__________________,                           _________________LOWER_R1__________________, _______, \
        KC_CAPS, _________________LOWER_L2__________________,                           _________________LOWER_R2__________________, _______, \
        _______, _________________LOWER_L3__________________, RESCUE,          _______, _________________LOWER_R3__________________, _______, \
                                   __________________________________,         _______, KC_DEL,  _______, _______                             \
    ),

    [_RAISE] = LAYOUT_wrapper( \
        KC_F11,  _________________FUNC_LEFT_________________,                           _________________FUNC_RIGHT________________, KC_F12,  \
        _______, _________________RAISE_L1__________________,                           _________________RAISE_R1__________________, _______, \
        _______, _________________RAISE_L2__________________,                           _________________RAISE_R2__________________, _______, \
        _______, _________________RAISE_L3__________________, _______,         RESCUE,  _________________RAISE_R3__________________, _______, \
                                   __________________________________,         __________________________________                             \
    ),

    [_ADJUST] = LAYOUT_wrapper( \
        _____________________DISABLED_______________________,                           _____________________DISABLED_______________________, \
        EEP_RST, _________________ADJUST_L1_________________,                           _________________ADJUST_R1_________________, XXXXXXX, \
        RESET,   _________________ADJUST_L2_________________,                           _________________ADJUST_R2_________________, XXXXXXX, \
        XXXXXXX, _________________ADJUST_L3_________________, XXXXXXX,         XXXXXXX, _________________ADJUST_R3_________________, XXXXXXX, \
                                   ____________DISABLED______________,         ____________DISABLED______________                             \
    ),

    [_RESCUE] = LAYOUT_wrapper( \
        _____________________DISABLED_______________________,                           _____________________DISABLED_______________________, \
        EEP_RST, RGB_VAI, ____________DISABLED______________,                           ____________DISABLED______________, RGB_VAI, EEP_RST, \
        RESET,   RGB_VAD, ____________DISABLED______________,                           ____________DISABLED______________, RGB_VAD, RESET,   \
        _____________________DISABLED_______________________, RESCUE,          RESCUE,  _____________________DISABLED_______________________, \
                                   ____________DISABLED______________,         ____________DISABLED______________                             \
    )
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
