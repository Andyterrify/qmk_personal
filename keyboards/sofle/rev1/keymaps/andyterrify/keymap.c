// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
// vim: shiftwidth=2 tabstop=2
#include QMK_KEYBOARD_H
#include "keymap_uk.h" // clang-format off
#include <stdio.h>
#include "quantum.h"

char wpm_str[10];
uint16_t last_keycode = KC_NO;

enum sofle_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _BASE,
    _LOWER,
    _RAISE,
    _GAME,
    _ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * BASE
 *  ,-----------------------------------------.                    ,-----------------------------------------.
 *  |      | #### | #### | #### | #### | #### |                    | #### | #### | #### | #### | #### | #### |
 *  |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 *  |ESC[`]|   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
 *  |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 *  | Tab  | C-A  | S-S  | G-D  | A-F  |   G  |-------.    ,-------|   H  | A-J  | G-K  | S-L  | C-;-:| #####|
 *  |------+------+------+------+------+------|  MUTE |    | MUTE  |------+------+------+------+------+------|
 *  | \ [|]|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |  ,-< |  .-> |  /-? | #   |
 *  `----------------------------------------/       /    \      \-----------------------------------------'
 *            | RBT  | #####| #####| #####| / Space /       \ Enter\  | Raise| PSCR | #####| RBT  |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_BASE] = LAYOUT(
/* 1 */ KC_GRV,  XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,        /* SPLIT */           XXXXXXX, XXXXXXX,         XXXXXXX,         XXXXXXX,         XXXXXXX,             XXXXXXX, /* # */
/* 2 */ QK_GESC,  KC_Q,         KC_W,         KC_E,         KC_R,         KC_T,           /* SPLIT */           KC_Y, KC_U,         KC_I,         KC_O,         KC_P,             KC_BSPC, /* # */
/* 3 */ KC_TAB,   LCTL_T(KC_A), LSFT_T(KC_S), LGUI_T(KC_D), LALT_T(KC_F), KC_G,           /* SPLIT */           KC_H, RALT_T(KC_J), RGUI_T(KC_K), RSFT_T(KC_L), RCTL_T(KC_SCLN),  KC_QUOT, /* # */
/* 4 */ KC_BSLS,  KC_Z,         KC_X,         KC_C,         KC_V,         KC_B,   KC_MUTE,  /* SPLIT */ KC_MUTE,  KC_N, KC_M,         KC_COMM,      KC_DOT,       KC_SLSH,          KC_TILD, /* # */
/* Special */   QK_BOOT,  XXXXXXX,  OSL(_LOWER), MO(_LOWER), KC_SPC, /* SPLIT */ KC_ENT, MO(_RAISE), OSL(_RAISE),  XXXXXXX,  QK_BOOT
),


/* LOWER
*  ,-----------------------------------------.                    ,-----------------------------------------.
*  |      |      |      |      |      |      |                    |      |      |      |      |      |      |
*  |------+------+------+------+------+------|                    |------+------+------+------+------+------|
*  | ____ | !    | "    | #    | $    |   %  |-------.            |   ^  |   &  |   *  | - (_)| = (+)| F12  |
*  |------+------+------+------+------+------|                    |------+------+------+------+------+------|
*  | ____ | !    | "    | #    | (    |   {  |-------.            |   }  |   )  |   `  | - (_)| = (+)| F12  |
*  |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
*  | ____ | ____ | ____ | ____ |   {  |  [   |-------|    |-------|  ]   |   }  |   :  | ____ | ____ |  #   |
*  `-----------------------------------------/       /     \      \-----------------------------------------'
*             | ____ | ____ | ____ |_____ | /_____  /       \_____ \  |_____ | _____| _____| ____ |
*             |      |      |      |      |/       /         \      \ |      |      |      |      |
*             `----------------------------------'           '------''---------------------------'
*/
[_LOWER] = LAYOUT( /* This one is for symbols and misc */
/* 4 */ XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,            /* SPLIT */             XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    /* # */
/* 3 */ XXXXXXX,    KC_EXLM,    KC_DQUO,    KC_HASH,     KC_DLR,     KC_PERC,            /* SPLIT */             KC_CIRC,    KC_AMPR,    KC_ASTR,    KC_MINS,    KC_EQL,     KC_F12,     /* # */
/* 3 */ XXXXXXX,    XXXXXXX,    KC_GRV,    KC_LCBR,     KC_LPRN,     KC_LBRC,            /* SPLIT */             KC_RBRC,    KC_RPRN,    KC_RCBR,    KC_AT,    KC_TILD,     XXXXXXX,     /* # */
/* 4 */ KC_TILD,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX, XXXXXXX,   /* SPLIT */ XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    _______,    _______,    KC_HASH,    /* # */
/* Special */                            QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,            KC_ENT, MO(_RAISE), OSL(_RAISE),  XXXXXXX,  XXXXXXX
),
// /* 3 */ XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_LPRN,            /* SPLIT */             KC_RPRN,    XXXXXXX,    KC_HASH,    KC_PIPE,    KC_TILD,    _______,    /* # */

/*
 *
 *                                      ,----------------------------------------.                    ,-----------------------------------------.
 *                                      | ____ | ____ | ____ | ____ | ____ | ____ |                    | ____ | ____ | ____ | ____ | ____ | ____ |
 *                                      |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 *                                      | ____ | ____ | ____ | ____ |CPSTOG|CPSLCK|-------.    ,-------| <L>  | <D>  | <U>  | <R>  |      | Del  |
 *                                      |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 *                                      | ____ |  1   |  2   |  3   |  4   |  5   |                    |  6   |  7   |  8   |  9   |  0   | ____ |
 *                                      |------+------+------+------+------+------| ____  |    | ____  |------+------+------+------+------+------|
 *                                      | ____ | ____ | ____ | ____ | ____ | ____ |-------|    |-------| Home | PGDN | PGUP | End  | Dot | ____  |
 *                                      `-----------------------------------------/       /     \      \-----------------------------------------'
 *                                                 | ____ | ____ | ____ | ____ | / ____  /       \ ____ \  | ____ | PrtSc| ____ | ____ |
 *                                                 |      |      |      |      |/       /         \      \ |      |      |      |      |
 *                                                 `----------------------------------'           '------''---------------------------'
 */
[_RAISE] = LAYOUT(
/* 1 */ XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,            /* SPLIT */             XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_BSPC,    /* # */
/* 2 */ XXXXXXX,    KC_1,       KC_2,       KC_3,       KC_4,       KC_5,               /* SPLIT */             KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       XXXXXXX,    /* # */
/* 2 */ XXXXXXX,    XXXXXXX,       XXXXXXX,       XXXXXXX,       CW_TOGG,       KC_CAPS,               /* SPLIT */             XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       KC_DEL,       XXXXXXX,    /* # */
/* 4 */ XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,  XXXXXXX,  /* SPLIT */ XXXXXXX,    KC_HOME,    KC_PGUP,    KC_PGDN,    KC_END,     KC_DOT,     XXXXXXX,     /* # */
/* Special */                XXXXXXX,  XXXXXXX,  OSL(_LOWER), MO(_LOWER), KC_SPC,       /* SPLIT */     XXXXXXX, XXXXXXX, KC_PSCR, XXXXXXX, XXXXXXX                                     /* # */
),
/* ADJUST
 *                                      ,-----------------------------------------.                    ,-----------------------------------------.
*                                       | ____ | F1   | F2   | F3   | F4   | F5   |                    | F6   | F7   | F8   | F9   | F10  | F11  |
 *                                      |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 *                                      | QK_BOOT|      |BASE|COLEMAK|      |      |                    |      |      |      |      |      |      |
 *                                      |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 *                                      |      |      |MACWIN|      |      |      |-------.    ,-------|      | VOLDO| MUTE | VOLUP|      |      |
 *                                      |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 *                                      |      |      |      |      |      |      |-------|    |-------|      | PREV | PLAY | NEXT |      |      |
 *                                      `-----------------------------------------/       /     \      \-----------------------------------------'
 *                                                 | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *                                                 |      |      |      |      |/       /         \      \ |      |      |      |      |
 *                                                 `----------------------------------'           '------''---------------------------'
 */
  [_ADJUST] = LAYOUT(
/* 1 */ XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,            /* SPLIT */             XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    /* # */
/* 1 */ KC_TILD,    KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,              /* SPLIT */             KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,     /* # */
/* 3 */ XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_LEFT,    KC_DOWN,            /* SPLIT */             KC_LEFT,    KC_DOWN,    KC_UP,    KC_RGHT,    KC_MUTE,    XXXXXXX,    /* # */
/* 4 */ XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX, XXXXXXX,   /* SPLIT */ XXXXXXX,    XXXXXXX,    KC_MPRV,    KC_MPLY,    KC_MNXT,    XXXXXXX,    XXXXXXX,    /* # */
/* Special */                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,        /* SPLIT */     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX                                     /* # */
  ),

/*
 * GAME
 *                                                  ,-----------------------------------------.                    ,-----------------------------------------.
 *                                                  | ESC  | 1 (!)|  2(")|  3(£)|  4($)| 5(%) |                    | 6(^) | 7(&) | 8(*) |  9(  | 0 )  | Bspc |
 *                                                  |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 *                                                  | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | #####|
 *                                                  |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 *                                                  | SHFT |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  | ' (@)|
 *                                                  |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 *                                                  | CTRL |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  | , (<) | . (>) | / (?)|# (~)|
 *                                                  `-----------------------------------------/       /     \      \-----------------------------------------'
 *                                                             | #### | #### | #### |GLOWER| / Space /       \ Enter\  |RAISE | #### | #### | #### |
 *                                                             |      |      |      |      |/       /         \      \ |      |      |      |      |
 *                                                             `----------------------------------'           '------''---------------------------'
 */

[_GAME] = LAYOUT(
/* 1 */ QK_GESC,    KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           /* SPLIT */             KC_6,   KC_7,           KC_8,           KC_9,           KC_0,               KC_BSPC, /* # */
/* 2 */ KC_TAB,     KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           /* SPLIT */             KC_Y,   KC_U,           KC_I,           KC_O,           KC_P,               XXXXXXX, /* # */
/* 3 */ KC_LSFT,     KC_A,           KC_S,           KC_D,           KC_F,           KC_G,           /* SPLIT */             KC_H,   KC_J,           KC_K,           KC_L,           KC_SCLN,            KC_QUOT, /* # */
/* 4 */ KC_LCTL,    KC_Z,           KC_X,           KC_C,           KC_V,           KC_B, KC_MUTE,  /* SPLIT */ XXXXXXX,    KC_N,   KC_M,           KC_COMM,        KC_DOT,         KC_SLSH,            KC_HASH, /* # */
/* Special */                                   XXXXXXX, XXXXXXX, KC_LALT, XXXXXXX,   KC_SPC,     /* SPLIT */     KC_ENT, MO(_RAISE), XXXXXXX, XXXXXXX, XXXXXXX
    ),

};

// static void render_logo(void) {
//     static const char PROGMEM qmk_logo[] = {
//         0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
//         0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
//         0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
//     };
//
//     oled_write_P(qmk_logo, false);
// }

static void render_right_oled(void) {
  oled_write_ln("Last Key:", false);
  char key_str[8];
  snprintf(key_str, sizeof(key_str), "0x%X", last_keycode);
  oled_write_ln(key_str, false);
}

static void render_left_oled(void) {
    // Print current mode
    oled_write_P(PSTR("      "), false);
    sprintf(wpm_str, "%03d", get_current_wpm());
    oled_write(wpm_str, false);
    oled_write_P(PSTR(" WPM  "), false);


    // oled_write_P(PSTR("\n\n"), false);
    // oled_write_ln_P(PSTR("MODE"), false);
    // oled_write_ln_P(PSTR(""), false);
    // oled_write_ln_P(PSTR("LIN"), false);

    oled_write_P(PSTR("\n"), false);
    // Print current layer
    oled_write_ln_P(PSTR("LAYER"), false);
    switch (get_highest_layer(layer_state)) {
        case _BASE:
            oled_write_P(PSTR("Base\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Raise"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Lower"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Adj\n"), false);
            break;
        case _GAME:
            oled_write_P(PSTR("Game"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }

    oled_write_P(PSTR("\n\n"), false);

    // Print if caps lock or word lock is on
    if (is_caps_word_on()) {
        oled_write_ln_P(PSTR("CPWRD"), true);
    } else {
        led_t led_usb_state = host_keyboard_led_state();
        oled_write_ln_P(PSTR("CPSLK"), led_usb_state.caps_lock);
    }
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        render_left_oled();
    } else {
        render_right_oled();
    }
    return false;
}

void oled_render_boot(bool bootloader) {
    oled_clear();
    for (int i = 0; i < 16; i++) {
        oled_set_cursor(0, i);
        if (bootloader) {
            oled_write_P(PSTR("Awaiting New Firmware "), false);
        } else {
            oled_write_P(PSTR("Rebooting "), false);
        }
    }

    oled_render_dirty(true);
}

bool shutdown_user(bool jump_to_bootloader) {
    oled_render_boot(jump_to_bootloader);
    return false;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        last_keycode = keycode;  // Store the latest pressed key
    }
    return true;  // Continue with normal key processing
}

