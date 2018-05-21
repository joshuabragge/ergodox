#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

/* Layers */

enum {
  BASE = 0,
  MVMNT,
  SYMB
};


enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD
};

/* Custom keycodes */

enum {
  CT_LBP,
  CT_RBP,
  CT_ESCF4,
  CT_TA,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | \ / |  |   1  |   2  |   3  |   4  |   5  | GUI+L|    | ctrl+alt+del|   6  |   7  |   8  |   9  |   0  |   =/+  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   Q  |   W  |   F  |   P  |   G  |  (   |           |   )  |   J  |   L  |   U  |   Y  |   ;  |   -    |
 * |--------+------+------+------+------+------|  [   |           |   ]  |------+------+------+------+------+--------|
 * |Tab/MVMT|   A  |   R  |   S  |   T  |   D  |------|           |------|   H  |   N  |   E  |   I  |   O  |  '     |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  SYMB  |  Z   |   X  |   C  |   V  |   B  |      |           |      |   K  |   M  |   ,  |   .  |   /  | Enter  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |  Del | Alt  | Ctrl |                                       |      |      |      | MVMNT | SYMB |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | LAlt |  Del |       | RESET|      |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Ctrl |       |      |        |      |
 *                                 | Space|Tab   |------|       |------| Enter  | BkSp |
 *                                 |      |Shift | ESC  |       | LGui |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_BSLS,        KC_1,      KC_2,   KC_3,   KC_4,   KC_5,   LGUI(KC_L),
        KC_NO,          KC_Q,      KC_W,   KC_F,   KC_P,   KC_G,   TD(CT_LBP),
        TD(CT_TA),      KC_A,      KC_R,   KC_S,   KC_T,   KC_D,
        TT(SYMB),       KC_Z,      KC_X,   KC_C,   KC_V,   KC_B,   KC_NO,
        KC_NO,         KC_NO,      KC_DELT,KC_LALT,KC_LCTRL,
                                                              KC_LALT,       KC_DELT,
                                                                             KC_LCTRL,
                                                    KC_SPC, RSFT_T(KC_TAB),TD(CT_ESCF4),
        // right hand
             ALTG(KC_DELT),  KC_6,   KC_7,  KC_8,   KC_9,    KC_0,               KC_EQL,
             TD(CT_RBP),     KC_J,   KC_L,  KC_U,   KC_Y,   KC_SCLN,             KC_MINS,
                             KC_H,   KC_N,  KC_E,   KC_I,   KC_O,                KC_QUOT,
             KC_NO,          KC_K,   KC_M,  KC_COMM,KC_DOT, KC_SLSH,             KC_ENT,
                                     KC_NO, KC_NO,  KC_NO,  TT(MVMNT),               TT(SYMB),
             RESET,           KC_NO,
             KC_NO,
             KC_LGUI,         KC_ENT, KC_BSPC
    ),

/* Keymap 2: Arrow layer
 *
 * ,-----------------------------------------------------.           ,-----------------------------------------------------.
 * |           |      |      |      |      |      |      |           |      |      |      |      |      |      |           |
 * |-----------+------+------+------+------+-------------|           |------+------+------+------+------+------+-----------|
 * |           |MwhlL |MwhlD | MwhlU| MwhlR|      |      |           |      |      | Msp2 | Msp0 | Msp1 |      |           |
 * |-----------+------+------+------+------+------| PgUp |           |      |------+------+------+------+------+-----------|
 * |   Tab     |MsLeft|MsDown| MsUp |MsRght|      |------|           |------|      | Left | Down | Up   |  Rght|           |
 * |-----------+------+------+------+------+------| PgDn |           |      |------+------+------+------+------+-----------|
 * |           |Ctrl+z|Ctrl+x|Ctrl+c|Ctrl+v|      |      |           |      |      |      |      |      |      |           |
 * `-----------+------+------+------+------+-------------'           `-------------+------+------+------+------+-----------'
 *      |      |      |      |      |      |                                       |      |      |      |      |      |
 *      `----------------------------------'                                       `----------------------------------'
 *                                         ,-------------.           ,-------------.
 *                                         |      |      |           |      |      |
 *                                  ,------|------|------|           |------+------+------.
 *                                  |      |      |      |           |      |Ctrl+  |      |
 *                                  | Rclk |Shift |------|           |------|Shift  | Lclk |
 *                                  |      | Tab  | ESC  |           | GUI  |  Enter|      |
 *                                  `--------------------'           `--------------------'
 */

[MVMNT] = LAYOUT_ergodox(
// left hand
 KC_TRNS ,KC_TRNS          ,KC_TRNS         ,KC_TRNS          ,KC_TRNS    ,KC_TRNS    ,KC_TRNS
,KC_TRNS ,KC_MS_WH_LEFT    ,KC_MS_WH_DOWN   ,KC_MS_WH_UP       ,KC_MS_WH_RIGHT    ,KC_TRNS    ,KC_PGUP
,KC_TRNS ,KC_MS_L          ,KC_MS_D         ,KC_MS_U          ,KC_MS_R    ,KC_TRNS
,KC_TRNS ,LCTL(KC_Z)       ,LCTL(KC_X)      ,LCTL(KC_C)       ,LCTL(KC_V) ,KC_TRNS    ,KC_PGDN
,KC_TRNS ,KC_TRNS         ,KC_TRNS         ,KC_TRNS          ,KC_TRNS

                                             ,KC_TRNS ,KC_TRNS
                                                      ,KC_TRNS
                                    ,KC_BTN2  ,RSFT_T(KC_TAB) ,TD(CT_ESCF4)

                                                                // right hand
                                                               ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS
                                                               ,KC_TRNS ,KC_TRNS ,KC_MS_ACCEL2 ,KC_MS_ACCEL0   ,KC_MS_ACCEL1  ,KC_TRNS ,KC_TRNS
                                                                        ,KC_TRNS ,KC_LEFT ,KC_DOWN ,KC_UP ,KC_RGHT ,KC_TRNS
                                                               ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS
                                                                                 ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS

                                                               ,KC_TRNS ,KC_TRNS
                                                               ,KC_TRNS
                                                               ,KC_LGUI ,C_S_T(KC_ENT) ,KC_BTN1
    ),

/* Keymap 1: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |         |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |  ^   |  &   |   *  |   ~  |   `  |      |           |      |   =  |   7  |   8  |   9  |   *  |   F12  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |  !   |   @  |   #  |   $  |   %  |------|           |------|   .  |   4  |   5  |   6  |   +  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |      |      |      |      |      |           |      |  0   |   1  |   2  |   3  |   /  |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      |      |      |                                       | Left | Down |  Up  | Right|      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */

// SYMBOLS
[SYMB] = LAYOUT_ergodox(
       // left hand
       KC_TRNS,   KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_TRNS,
       
       KC_TRNS,KC_CIRC,KC_AMPR, KC_ASTR,KC_TILD,KC_GRV,  KC_TRNS,
       KC_TRNS,KC_EXLM,KC_AT,  KC_HASH,KC_DLR,KC_PERC,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TILD,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand 
       KC_TRNS, KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,
       KC_TRNS, KC_EQL,   KC_7,   KC_8,    KC_9,    KC_ASTR, KC_F12,
                KC_DOT, KC_4,   KC_5,    KC_6,    KC_PLUS, KC_TRNS,
       KC_TRNS, KC_0,     KC_1,   KC_2,     KC_3,     KC_SLASH,  KC_TRNS,
                         KC_LEFT, KC_DOWN,  KC_UP,    KC_RIGHT,  KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),

};

#define TAP_ONCE(code)  \
  register_code (code); \
  unregister_code (code)

typedef struct {
  bool layer_toggle;
  bool sticky;
} td_ta_state_t;

static void ang_tap_dance_ta_finished (qk_tap_dance_state_t *state, void *user_data) {
  td_ta_state_t *td_ta = (td_ta_state_t *) user_data;

  if (td_ta->sticky) {
    td_ta->sticky = false;
    td_ta->layer_toggle = false;
    layer_off (MVMNT);
    return;
  }

  if (state->count == 1 && !state->pressed) {
    register_code (KC_TAB);
    td_ta->sticky = false;
    td_ta->layer_toggle = false;
  } else {
    td_ta->layer_toggle = true;
    layer_on (MVMNT);
    td_ta->sticky = (state->count == 2);
  }
}

static void ang_tap_dance_ta_reset (qk_tap_dance_state_t *state, void *user_data) {
  td_ta_state_t *td_ta = (td_ta_state_t *) user_data;

  if (!td_ta->layer_toggle)
    unregister_code (KC_TAB);
  if (!td_ta->sticky)
    layer_off (MVMNT);
}


const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(BASE)                // FN1 - Momentary Layer 1 (Symbols)
};

qk_tap_dance_action_t tap_dance_actions[] = {
   [CT_LBP] = ACTION_TAP_DANCE_DOUBLE (KC_LPRN, KC_LBRC)
  ,[CT_TA]  = {
      .fn = { NULL, ang_tap_dance_ta_finished, ang_tap_dance_ta_reset },
      .user_data = (void *)&((td_ta_state_t) { false, false })
    }
  ,[CT_RBP] = ACTION_TAP_DANCE_DOUBLE (KC_RPRN, KC_RBRC)
  ,[CT_ESCF4] = ACTION_TAP_DANCE_DOUBLE (KC_ESC, LALT(KC_F4))
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
  switch(id) {
    case 0:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      break;
    case 1:
      if (record->event.pressed) { // For resetting EEPROM
        eeconfig_init();
      }
      break;
  }
  return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (keycode == KC_ESC && record->event.pressed) {
    bool queue = true;

    if ((get_oneshot_mods ()) && !has_oneshot_mods_timed_out ()) {
      clear_oneshot_mods ();
      queue = false;
    }
    if (layer_state & (1UL << MVMNT)) {
      layer_off (MVMNT);
      queue = false;
    }
    return queue;
  }

  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode(1);
        #endif
      }
      return false;
      break;
  }
  return true;
}


// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

};

