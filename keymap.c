#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "keymap_plover.h"
#include "version.h"
#include <print.h>

/* Layers */

enum {
  BASE = 0,
  MVMNT,
  FUNC,
  NMBR,
  PLVR,
  SWPHND,
};


enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  VRSN,
};

/* Fn keys */

enum {
  F_BSE = 0,
  F_SFT,
  F_ALT,
  F_CTRL
};

/* Custom keycodes */

enum {
  CT_LBP,
  CT_RBP,
  CT_ESCF4,
  CT_COL,
  CT_TA,
  CT_WINDOWS,
  CT_UNDER,
  CT_SWITCH,
};

bool log_enable = false;

/* Lead Variables */

const char JB[15] = "joshua.bragge";
const char DB[20] = "joshua.bragge.db";
const char SVR[20] = "joshua.bragge.svr";
const char SCD[10] = "[SCD]";
const char FROM[10] = "from:";



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 *|ESC/AltF4|   1  |  2   |   3  |   4  |   5  |ScrLCK|           |Unlock|   6  |   7  |   8  |   9  |   0  |    \   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  Del   |   Q  |   W  |   F  |   P  |   G  |  (   |           |   )  |   J  |   L  |   U  |   Y  | ;/:  |    =   |
 * |--------+------+------+------+------+------|  [   |           |   ]  |------+------+------+------+------+--------|
 * |Tab/NMBR|   A  |   R  |   S  |   T  |   D  |------|           |------|   H  |   N  |   E  |   I  |   O  |    '   |
 * |--------+------+------+------+------+------| Snip |           |  >>  |------+------+------+------+------+--------| 
 * |  Ctrl  |   Z  |  X   |  C   |   V  |   B  |Divvy |           |  <<  |   K  |   M  |   ,  |   .  |   /  |   -/_  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | PgUp |PgDwn | Alt  |SWPHND| NMBR |                                       | MVMNT|      |      |      | NMBR |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | FUNC |      |       |      | FUNC |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |  F2  |       |  F5  |        |      |
 *                                 | Space|Shift |------|       |------| Enter  | BkSp |
 *                                 |      |      | LGui |       | Lead |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        TD(CT_ESCF4),       KC_1,      KC_2,     KC_3,      KC_4,       KC_5,        LGUI(KC_L),
        KC_DELT,            KC_Q,      KC_W,     KC_F,      KC_P,       KC_G,        TD(CT_LBP),
        TD(CT_TA),          KC_A,      KC_R,     KC_S,      KC_T,       KC_D,
        KC_LCTRL,           KC_Z,      KC_X,     KC_C,      KC_V,       KC_B,        TD(CT_WINDOWS),
        KC_PGUP,            KC_PGDN,   KC_LALT, TT(SWPHND),MO(NMBR),
                                                                        OSL(FUNC),  KC_NO,
                                                                                     KC_F2,
                                                            KC_SPC,     KC_LSHIFT,   KC_LGUI,
        // right hand'
             ALTG(KC_DELT),  KC_6,   KC_7,     KC_8,      KC_9,     KC_0,               KC_BSLS,
             TD(CT_RBP),     KC_J,   KC_L,     KC_U,      KC_Y,     TD(CT_COL),         KC_EQL,
                             KC_H,   KC_N,     KC_E,      KC_I,     KC_O,               KC_QUOT,
             TD(CT_SWITCH),     KC_K,   KC_M,  KC_COMM,   KC_DOT,   KC_SLSH,            TD(CT_UNDER),
                                     MO(MVMNT),KC_NO ,    KC_NO,    KC_NO,              TG(NMBR),
             KC_NO,      OSL(FUNC),
             KC_F5,
             KC_LEAD,         KC_ENT, KC_BSPC
    ),

/* Keymap 1: Arrow layer
 *
 * ,-----------------------------------------------------.           ,-----------------------------------------------------.
 * |           |      |      |      |      |      |      |           |      |      |      |      |      |      |           |
 * |-----------+------+------+------+------+-------------|           |------+------+------+------+------+------+-----------|
 * |           |  !   |  @   |  #   |  $   |  %   |      |           |      |  ^   |  &   |  *   |  ~   |  `   |           |
 * |-----------+------+------+------+------+------|      |           |      |------+------+------+------+------+-----------|
 * |           |Insert| Home | PgUp | Vol+ | Play |------|           |------| Home | Left | Down | Up   | Rght |  End      |
 * |-----------+------+------+------+------+------|      |           |      |------+------+------+------+------+-----------|
 * |           | Del  | End  | PgDn | Vol- | Next |      |           |      |      |      |      |      |      |           |
 * `-----------+------+------+------+------+-------------'           `-------------+------+------+------+------+-----------'
 *      |PrnScn|      |      |      |      |                                       |      |      |      |      |      |
 *      `----------------------------------'                                       `----------------------------------'
 *                                         ,-------------.           ,-------------.
 *                                         |      |      |           |      |      |
 *                                  ,------|------|------|           |------+------+------.
 *                                  |      |      |      |           |      |      |      |
 *                                  |      |      |------|           |------|      |      |
 *                                  |      |      |      |           |      |      |      |
 *                                  `--------------------'           `--------------------'
 */

[MVMNT] = LAYOUT_ergodox(
// left hand
 KC_TRNS ,KC_TRNS     ,KC_TRNS         ,KC_TRNS          ,KC_TRNS    ,KC_TRNS    ,KC_TRNS
,KC_TRNS ,KC_EXLM     ,KC_AT           ,KC_HASH          ,KC_DLR     ,KC_PERC    ,KC_TRNS
,KC_TRNS ,KC_INSERT   ,KC_HOME         ,KC_PGUP          ,KC_VOLU    ,KC_MPLY
,KC_TRNS ,KC_DEL      ,KC_END          ,KC_PGDN          ,KC_VOLD    ,KC_MNXT    ,KC_TRNS
,KC_PSCR ,KC_TRNS     ,KC_TRNS         ,KC_TRNS          ,KC_TRNS

                                                                        ,KC_TRNS ,KC_TRNS
                                                                                 ,KC_TRNS
                                                      ,KC_TRNS        ,KC_TRNS   ,KC_TRNS

                                                                // right hand
                                                               ,KC_TRNS ,KC_TRNS ,KC_TRNS       ,KC_TRNS       ,KC_TRNS          ,KC_TRNS  ,KC_TRNS
                                                               ,KC_TRNS ,KC_CIRC ,KC_AMPR       ,KC_ASTR       ,KC_TILD          ,KC_GRV   ,KC_TRNS
                                                                        ,KC_HOME ,KC_LEFT       ,KC_DOWN       ,KC_UP            ,KC_RGHT  ,KC_END
                                                               ,KC_TRNS ,KC_TRNS ,KC_TRNS       ,KC_TRNS       ,KC_TRNS          ,KC_TRNS  ,KC_TRNS
                                                                                 ,KC_TRNS       ,KC_TRNS       ,KC_TRNS          ,KC_TRNS  ,KC_TRNS

                                                               ,KC_TRNS ,KC_TRNS
                                                               ,KC_TRNS
                                                               ,KC_TRNS ,KC_TRNS ,KC_TRNS
    ),

/* Keymap 2: Function Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |   F12   |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  | F10  |  F11   |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      |      |      |                                       |      |      |      |      | RESET|
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      | PLVR |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */

// Functions
[FUNC] = LAYOUT_ergodox(
       // left hand
       KC_F12, KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_TRNS,
       
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       KC_TRNS,TG(PLVR),
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_TRNS, KC_F6,   KC_F7,     KC_F8,     KC_F9,      KC_F10,  KC_F11,
       KC_TRNS,  KC_TRNS,   KC_TRNS,     KC_TRNS,     KC_TRNS,      KC_TRNS,   KC_TRNS,
                KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,   KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,  KC_TRNS,
                         KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,  RESET,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),

/* Keymap 3: Number Pad Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |         |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |      |      |      |      |      |      |           |      |      |   7  |   8  |   9  |   *  |   =    |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |      |      |      |      |------|           |------|      |   4  |   5  |   6  |   +  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |      |      |      |      |      |           |      |      |   1  |   2  |   3  |   /  |   -    |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      |      |      |                                       |      |   0  |   .  | Enter|      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */


[NMBR] = LAYOUT_ergodox(
       // left hand
       KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
       
       KC_TRNS,KC_TRNS,KC_TRNS, KC_TRNS,KC_TRNS,KC_TRNS,  KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,  KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_TRNS, KC_TRNS,   KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS,  KC_TRNS,
       KC_TRNS, KC_TRNS,  KC_7,   KC_8,    KC_9,    KC_ASTR, KC_EQL,
                KC_TRNS, KC_4,   KC_5,    KC_6,    KC_PLUS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_1,   KC_2,     KC_3,     KC_SLASH,  KC_MINS,
                         KC_TRNS, KC_0,  KC_DOT,   KC_KP_ENTER,  KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),


/* Keymap 5: Steno for Plover
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   #  |   #  |   #  |   #  |   #  |   #  |           |  #   |  #   |  #   |   #  |   #  |  #   |   #    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |   T  |   P  |   H  |      |------|           |------|      |  F   |   P  |   L  |  T   |   D    |
 * |--------+   S  +------+------+------+   *  |   *  |           |  *   |  *   +------+------+------+------+--------|
 * |        |      |   K  |   W  |   R  |      |      |           |      |      |  R   |   B  |   G  |  S   |   Z    |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |   A  |   O  |------|       |------|  E   |  U   |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */

[PLVR] = LAYOUT_ergodox(
// left hand
TG(PLVR),  KC_NO,  KC_NO,  KC_NO,   KC_NO,  KC_NO,   KC_NO,
KC_NO,  PV_NUM, PV_NUM, PV_NUM,  PV_NUM, PV_NUM,  PV_NUM,
KC_NO,  PV_LS,  PV_LT,  PV_LP,   PV_LH,  PV_STAR,
KC_NO,  PV_LS,  PV_LK,  PV_LW,   PV_LR,  PV_STAR, PV_STAR,
KC_NO,  KC_NO,  KC_NO,  KC_NO,   KC_NO,
                                           KC_NO, KC_TRNS,
                                           KC_NO,
                                           PV_A,  PV_O,  KC_NO,

                                                 // right hand
                                                 KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                                 PV_NUM,  PV_NUM,  PV_NUM,  PV_NUM,  PV_NUM,  PV_NUM,  PV_NUM,
                                                          PV_STAR, PV_RF,   PV_RP,   PV_RL,   PV_RT,   PV_RD,
                                                 PV_STAR, PV_STAR, PV_RR,   PV_RB,   PV_RG,   PV_RS,   PV_RZ,
                                                                   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                           KC_NO,      KC_TRNS,
                                           KC_NO,
                                           KC_NO,PV_E, PV_U
 ),

/* Keymap 6: Swap Hands
 *
 * ,-----------------------------------------------------.           ,-----------------------------------------------------.
 * |           |  6   |   7  |  8   |   9  |   0  |      |           |      |   1  |   2  |  3   |  4   |   5  |           |
 * |-----------+------+------+------+------+-------------|           |------+------+------+------+------+------+-----------|
 * |           |  J   |   L  |   U  |   Y  |  ;   |      |           |      |  Q   |  W   |   E  |   R  |   T  |           |
 * |-----------+------+------+------+------+------|      |           |      |------+------+------+------+------+-----------|
 * |           |  H   |  N   |   E  |   I  |  O   |------|           |------|  A   |  S   |   D  |   F  |   G  |           |
 * |-----------+------+------+------+------+------|      |           |      |------+------+------+------+------+-----------|
 * |           |  K   |  M   |   ,  |  .   |   /  |      |           |      |  Z   |  X   |   C  |   V  |   B  |           | 
 * `-----------+------+------+------+------+-------------'           `-------------+------+------+------+------+-----------'
 *      |      |      |      |      |      |                                       |      |      |      |      |      |
 *      `----------------------------------'                                       `----------------------------------'
 *                                         ,-------------.           ,-------------.
 *                                         |      |      |           |      |      |
 *                                  ,------|------|------|           |------+------+------.
 *                                  |      |      |      |           |      |      |      |
 *                                  | Enter| Back |------|           |------|Space |LShift|
 *                                  |      |      |      |           |      |      |      |
 *                                  `--------------------'           `--------------------'
 */

[SWPHND] = LAYOUT_ergodox(
// left hand
 KC_TRNS ,KC_6     ,KC_7         ,KC_8          ,KC_9    ,KC_0    ,KC_TRNS
,KC_TRNS ,KC_J        ,KC_L            ,KC_U             ,KC_Y      ,TD(CT_COL)      ,KC_TRNS
,KC_TRNS ,KC_H        ,KC_N            ,KC_E             ,KC_I       ,KC_O
,KC_TRNS ,KC_K        ,KC_M            ,KC_COMM          ,KC_DOT     ,KC_SLSH     ,KC_TRNS
,KC_TRNS ,KC_TRNS     ,KC_TRNS         ,KC_TRNS          ,KC_TRNS

                                                                        ,KC_TRNS ,KC_TRNS
                                                                                 ,KC_TRNS
                                                          ,KC_ENT, KC_BSPC, KC_TRNS

                                                                // right hand
                                                               ,KC_TRNS ,KC_1 ,KC_2       ,KC_3       ,KC_4          ,KC_5     ,KC_TRNS
                                                               ,KC_TRNS ,KC_Q    ,KC_W          ,KC_F          ,KC_P             ,KC_G        ,KC_TRNS
                                                                        ,KC_A    ,KC_R          ,KC_S          ,KC_T             ,KC_D     ,KC_TRNS
                                                               ,KC_TRNS ,KC_Z    ,KC_X          ,KC_C          ,KC_V             ,KC_B     ,KC_TRNS
                                                                                 ,KC_TRNS       ,KC_TRNS       ,KC_TRNS          ,KC_TRNS     ,KC_TRNS

                                                               ,KC_TRNS ,KC_TRNS
                                                               ,KC_TRNS
                                                               ,KC_TRNS ,KC_SPC ,KC_LSHIFT
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
    layer_off (NMBR);
    return;
  }

  if (state->count == 1 && !state->pressed) {
    register_code (KC_TAB);
    td_ta->sticky = false;
    td_ta->layer_toggle = false;
  } else {
    td_ta->layer_toggle = true;
    layer_on (NMBR);
    td_ta->sticky = (state->count == 2);
  }
}

static void ang_tap_dance_ta_reset (qk_tap_dance_state_t *state, void *user_data) {
  td_ta_state_t *td_ta = (td_ta_state_t *) user_data;

  if (!td_ta->layer_toggle)
    unregister_code (KC_TAB);
  if (!td_ta->sticky)
    layer_off (NMBR);
}

static void ang_tap_dance_toggle_window (qk_tap_dance_state_t *state, void *user_data) {

  if (state->count >= 2) {
    // back on windows
    register_code(KC_LALT);
    register_code(KC_LSHIFT);
    wait_ms(10);
    register_code(KC_ESC);
    unregister_code(KC_ESC);
    wait_ms(10);
    unregister_code(KC_LALT);
    unregister_code(KC_LSHIFT);
  }
  else {
    // toggle windows forward
    register_code(KC_LALT);
    wait_ms(10);
    register_code(KC_ESC);
    unregister_code(KC_ESC);
    wait_ms(10);
    unregister_code(KC_LALT);
  }
}


//const uint16_t PROGMEM fn_actions[] = {
//    [1] = ACTION_LAYER_TAP_TOGGLE(BASE)                // FN1 - Momentary Layer 1 (Symbols)
//};

const uint16_t PROGMEM fn_actions[] = {
   [F_BSE]  = ACTION_LAYER_CLEAR(ON_PRESS)
  ,[F_SFT]  = ACTION_MODS_ONESHOT (MOD_LSFT)
  ,[F_ALT]  = ACTION_MODS_ONESHOT (MOD_LALT)
  ,[F_CTRL] = ACTION_MODS_ONESHOT (MOD_LCTL)
};

qk_tap_dance_action_t tap_dance_actions[] = {
   [CT_LBP] = ACTION_TAP_DANCE_DOUBLE (KC_LPRN, KC_LBRC)
  ,[CT_TA]  = {
      .fn = { NULL, ang_tap_dance_ta_finished, ang_tap_dance_ta_reset },
      .user_data = (void *)&((td_ta_state_t) { false, false })
    }
  ,[CT_RBP] = ACTION_TAP_DANCE_DOUBLE (KC_RPRN, KC_RBRC)
  ,[CT_WINDOWS] = ACTION_TAP_DANCE_DOUBLE (MEH(KC_S), MEH(KC_W))
  ,[CT_COL] = ACTION_TAP_DANCE_DOUBLE (KC_SCLN, LSFT(KC_COLN))
  ,[CT_ESCF4] = ACTION_TAP_DANCE_DOUBLE (KC_ESC, LALT(KC_F4))
  ,[CT_UNDER] = ACTION_TAP_DANCE_DOUBLE (KC_MINS, LSFT(KC_MINS))
  ,[CT_SWITCH] = ACTION_TAP_DANCE_FN (ang_tap_dance_toggle_window)

  ,[CT_SWITCH]= ACTION_TAP_DANCE_FN (ang_tap_dance_toggle_window)
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
    uint8_t layer = biton32(layer_state);
    if (log_enable) {
      if (layer == BASE)
        uprintf ("KL|%02d|%02d|%d|%s\n", record->event.key.col, record->event.key.row, record->event.pressed, "BASE");
      else if (layer == MVMNT)
        uprintf ("KL|%02d|%02d|%d|%s\n", record->event.key.col, record->event.key.row, record->event.pressed, "MVMNT");
      else if (layer == FUNC)
        uprintf ("KL|%02d|%02d|%d|%s\n", record->event.key.col, record->event.key.row, record->event.pressed, "FUNC");
      else if (layer == NMBR)
        uprintf ("KL|%02d|%02d|%d|%s\n", record->event.key.col, record->event.key.row, record->event.pressed, "NMBR");
      else if (layer == SWPHND)
        uprintf ("KL|%02d|%02d|%d|%s\n", record->event.key.col, record->event.key.row, record->event.pressed, "SWPHND");
      else 
        uprintf ("KL|%02d|%02d|%d|%s\n", record->event.key.col, record->event.key.row, record->event.pressed, "OTHER");
    }

  return true;
}


// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
  ergodox_led_all_on();
  for (int i = LED_BRIGHTNESS_HI; i > LED_BRIGHTNESS_LO; i--) {
    ergodox_led_all_set (i);
    wait_ms (5);
  }
  wait_ms(100);
  for (int i = LED_BRIGHTNESS_LO; i > 0; i--) {
    ergodox_led_all_set (i);
    wait_ms (5);
  }
  ergodox_led_all_off();
};

LEADER_EXTERNS();

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
  uint8_t layer = biton32(layer_state);
  if (layer == MVMNT) {
        ergodox_right_led_2_on();
        ergodox_right_led_2_set (LED_BRIGHTNESS_LO);
      } else if (layer == FUNC) {
        ergodox_right_led_1_on();
        ergodox_right_led_1_set (LED_BRIGHTNESS_LO);
      } else if (layer == NMBR) {
        ergodox_right_led_3_on();
        ergodox_right_led_3_set (LED_BRIGHTNESS_LO);
      } else if (layer == PLVR) {
        ergodox_right_led_1_on();
        ergodox_right_led_1_set (LED_BRIGHTNESS_LO);
        ergodox_right_led_2_on();
        ergodox_right_led_2_set (LED_BRIGHTNESS_LO);
        ergodox_right_led_3_on();
        ergodox_right_led_3_set (LED_BRIGHTNESS_LO);
      } else if (layer == SWPHND) {
        ergodox_right_led_1_on();
        ergodox_right_led_1_set (LED_BRIGHTNESS_LO);
        ergodox_right_led_2_on();
        ergodox_right_led_2_set (LED_BRIGHTNESS_LO);
        ergodox_right_led_3_on();
        ergodox_right_led_3_set (LED_BRIGHTNESS_LO);
      } else {
       ergodox_right_led_3_off();
       ergodox_right_led_2_off();
       ergodox_right_led_1_off();
     }

  LEADER_DICTIONARY() {
        leading = false;
        leader_end();

        SEQ_THREE_KEYS(KC_M, KC_E, KC_H) {
          unicode_input_start(); register_hex(0xaf); unicode_input_finish();
          TAP_ONCE (KC_BSLS);
          register_code (KC_RSFT); TAP_ONCE (KC_MINS); TAP_ONCE (KC_9); unregister_code (KC_RSFT);
          unicode_input_start (); register_hex(0x30c4); unicode_input_finish();
          register_code (KC_RSFT); TAP_ONCE (KC_0); TAP_ONCE (KC_MINS); unregister_code (KC_RSFT);
          TAP_ONCE (KC_SLSH);
          unicode_input_start (); register_hex(0xaf); unicode_input_finish();
        }
        SEQ_ONE_KEY(KC_S) {
          send_string(SCD);
        }
        SEQ_THREE_KEYS(KC_S, KC_V, KC_R) {
          send_string(SVR);
        }
        SEQ_TWO_KEYS(KC_D, KC_B) {
          send_string(DB);
        }
        SEQ_TWO_KEYS(KC_J, KC_B) {
          send_string(JB);
        }   
        SEQ_ONE_KEY(KC_E) {
          register_code(KC_LGUI);
          register_code(KC_E);
          unregister_code(KC_E);
          unregister_code(KC_LGUI);
        }
        SEQ_ONE_KEY(KC_U) {
          register_code(KC_LCTRL);
          register_code(KC_LALT);
          register_code(KC_DELT);
          unregister_code(KC_LCTRL);
          unregister_code(KC_LALT);
          unregister_code(KC_DELT);
        } 
        SEQ_ONE_KEY(KC_L) {
          register_code(KC_LGUI);
          register_code(KC_L);
          unregister_code(KC_L);
          unregister_code(KC_LGUI);
        }
        SEQ_ONE_KEY(KC_F){
          send_string(FROM);
        }
        SEQ_TWO_KEYS (KC_W, KC_M) {
          register_code(KC_LGUI);
          register_code(KC_UP);
          unregister_code(KC_LGUI);
          unregister_code(KC_UP);
        }
        SEQ_ONE_KEY (KC_D) {
          ergodox_led_all_on();
          wait_ms(100);
          ergodox_led_all_off();
          log_enable = !log_enable;
        }
      }
    };