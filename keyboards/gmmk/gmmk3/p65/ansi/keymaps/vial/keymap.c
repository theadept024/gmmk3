#include QMK_KEYBOARD_H

enum layers {
    _BASE,
    _FN,
    _GAME,
    _LIGHT,
};

enum custom_keycodes {
    AC_TOG = SAFE_RANGE,
    AC_HUI,
    AC_HUD,
    AC_VAI,
    AC_VAD,
};

static bool accent_enabled = true;

static void apply_accent_state(void) {
#if defined(RGBLIGHT_ENABLE)
    if (accent_enabled) {
        rgblight_enable_noeeprom();
    } else {
        rgblight_disable_noeeprom();
    }
#endif

#if defined(RGB_MATRIX_ENABLE)
    if (accent_enabled) {
        rgb_matrix_enable_noeeprom();
    } else {
        rgb_matrix_disable_noeeprom();
    }
#endif
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed) {
        return true;
    }

    switch (keycode) {
        case AC_TOG:
            accent_enabled = !accent_enabled;
            apply_accent_state();
            return false;
        case AC_HUI:
#if defined(RGBLIGHT_ENABLE)
            rgblight_increase_hue_noeeprom();
#endif
            return false;
        case AC_HUD:
#if defined(RGBLIGHT_ENABLE)
            rgblight_decrease_hue_noeeprom();
#endif
            return false;
        case AC_VAI:
#if defined(RGBLIGHT_ENABLE)
            rgblight_increase_val_noeeprom();
#endif
            return false;
        case AC_VAD:
#if defined(RGBLIGHT_ENABLE)
            rgblight_decrease_val_noeeprom();
#endif
            return false;
    }

    return true;
}

// Adjust this LAYOUT(...) to match the exact 65% ANSI LAYOUT macro in keyboard.h
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,
        KC_LCTL, KC_LGUI, KC_LALT, KC_RALT,                   KC_SPC,                             MO(_FN),  KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [_FN] = LAYOUT(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  QK_BOOT,
        _______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, RM_TOGG, RM_NEXT, RM_HUEU, RM_SATU, RM_VALU, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PGUP,
        _______, _______, _______, _______,                   _______,                            TO(_LIGHT), KC_MUTE, KC_HOME, KC_PGDN, KC_END
    ),

    [_GAME] = LAYOUT(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______, _______, _______, _______, _______, _______, _______, _______,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    _______, _______, _______, _______, _______, _______, _______, _______,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    _______, _______, _______, _______, _______, _______,          _______,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    _______, _______, _______, _______, _______, _______, _______,
        KC_LCTL, KC_LGUI, KC_LALT, _______,                   KC_SPC,                             TO(_BASE), _______, _______, _______, _______
    ),

    [_LIGHT] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, AC_TOG,  AC_HUD,  AC_HUI,  AC_VAD,  AC_VAI,  RM_TOGG, RM_PREV, RM_HUED, RM_HUEU, RM_VALD, RM_VALU, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______,                   _______,                            TO(_BASE), _______, _______, _______, _______
    ),
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [_BASE]  = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_FN]    = { ENCODER_CCW_CW(KC_PGDN, KC_PGUP) },
    [_GAME]  = { ENCODER_CCW_CW(KC_WH_D, KC_WH_U) },
    [_LIGHT] = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
};
#endif
