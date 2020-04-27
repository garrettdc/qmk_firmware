#pragma once

// This prevents accentally sending Ctrl when typing fast
#undef PERMISSIVE_HOLD
#define IGNORE_MOD_TAP_INTERRUPT

/* Set default TAPPING_TERM for all keyboards */
#if defined(TAPPING_TERM)
    #undef TAPPING_TERM
    #define TAPPING_TERM 200
#endif

/* Set default step and limit for all keyboards with RGB underlight */
#if defined(RGBLIGHT_ENABLE)
    #define RGBLIGHT_HUE_STEP 8
    #define RGBLIGHT_SAT_STEP 8
    #define RGBLIGHT_VAL_STEP 5
    #define RGBLIGHT_LIMIT_VAL 120
#endif

/* Set default step and limit for all keyboards with RGB matrix */
#if defined(RGB_MATRIX_ENABLE)
    #define RGB_MATRIX_HUE_STEP 8
    #define RGB_MATRIX_SAT_STEP 8
    #define RGB_MATRIX_VAL_STEP 5
    #define RGB_MATRIX_SPD_STEP 10
    #define RGB_MATRIX_MAXIMUM_BRIGHTNESS 120
    #define RGB_MATRIX_STARTUP_VAL 120
#endif
