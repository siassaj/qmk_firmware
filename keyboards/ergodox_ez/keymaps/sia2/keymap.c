#include "ergodox.h"
#include "debug.h"
#include "action_layer.h"

#define BASE 0 // default layout
#define SYMB 1 // symbols

#define MY_PRVR MY_PRINT_VERSION

enum my_keycodes {
  MY_PRINT_VERSION = SAFE_RANGE
};

  const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap 0: Basic layer
   *
   * ,--------------------------------------------------.           ,--------------------------------------------------.
   * | Esc    |   1  |   2  |   3  |   4  |   5  | LEFT |           | DEL  |   6  |   7  |   8  |   9  |   0  | BSpace |
   * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
   * | Tab    |   '  |   ,  |   .  |   P  |   Y  | Home |           | PgUp |   F  |   G  |   C  |   R  |   L  |  \     |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * | BkSp   |   A  |   O  |   E  |   U  |   I  |------|           |------|   D  |   H  |   T  |   N  |   S  | ENT    |
   * |--------+------+------+------+------+------| End  |           | PgDn |------+------+------+------+------+--------|
   * | LShift |   ;  |   Q  |   J  |   K  |   X  |      |           |      |   B  |   M  |   W  |   V  |   Z  | RShift |
   * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
   *   |      |      |      |      | /    |                                       |  _   | Left | Down |  Up  | Right|
   *   `----------------------------------'                                       `----------------------------------'
   *                                        ,-------------.       ,-------------.
   *                                        |      |      |       |      |      |
   *                                 ,------|------|------|       |------+------+------.
   *                                 |      |      | Win  |       |      |      |      |
   *                                 | Space| Ctrl |------|       |------| Alt  |Space |
   *                                 |      |      | SYMB |       |      |      |      |
   *                                 `--------------------'       `--------------------'
   */
  // If it accepts an argument (i.e, is a function), it doesn't need KC_.
  // Otherwise, it needs KC_*
  [BASE] = KEYMAP(  // layer 0 : default
                  // left hand
                  KC_ESC,    KC_1,      KC_2,      KC_3,      KC_4,       KC_5,     KC_LEFT,
                  KC_TAB,    KC_QUOT,   KC_COMM,   KC_DOT,    KC_P,       KC_Y,     KC_HOME,
                  KC_BSPC,   KC_A,      KC_O,      KC_E,      KC_U,       KC_I,
                  KC_LSFT,   KC_SCLN,   KC_Q,      KC_J,      KC_K,       KC_X,     KC_END,
                  KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_SLSH,

                  KC_TRNS,   KC_TRNS,
                  KC_LGUI,
                  KC_SPC,    KC_LCTL,   TT(SYMB),


                  // right hand
                  KC_DEL,    KC_6,      KC_7,      KC_8,      KC_9,       KC_0,     KC_BSPC,
                  KC_PGUP,   KC_F,      KC_G,      KC_C,      KC_R,       KC_L,     KC_BSLS,
                  KC_D,      KC_H,      KC_T,      KC_N,      KC_S,       KC_ENT,
                  KC_PGDN,   KC_B,      KC_M,      KC_W,      KC_V,       KC_Z,     KC_RSFT,
                  KC_UNDS,   KC_LEFT,   KC_DOWN,   KC_UP,     KC_RIGHT,

                  KC_TRNS,   KC_TRNS,
                  KC_TRNS,
                  KC_TRNS,   KC_LALT,   KC_SPC
                    ),
  /* Keymap 1: Symbol Layer
   *
   * ,--------------------------------------------------.           ,--------------------------------------------------.
   * |Version |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
   * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
   * |        |  &   |  :   |  (   |  )   |  "   |      |           |      |  @   |  -   |  >   |  ~   |      |   F12  |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * |        |  $   |  #   |  {   |  }   |  '   |------|           |------|  !   |  =   |  >   |  %   |  ?   |        |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * |        |  ^   |  *   |  [   |  ]   |  `   |      |           |      |  <   |  |   |  >   |  +   |  \   |        |
   * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
   *   |      |      |      |      |      |                                       |      |      |      |      |      |
   *   `----------------------------------'                                       `----------------------------------'
   *                                        ,-------------.       ,-------------.
   *                                        |      |      |       |      |      |
   *                                 ,------|------|------|       |------+------+------.
   *                                 |      |      |      |       |      |      |      |
   *                                 |      |      |------|       |------|      |      |
   *                                 |      |      |      |       |      |      |      |
   *                                 `--------------------'       `--------------------'
   */
  // SYMBOLS
  [SYMB] = KEYMAP(
                  // left hand
                  MY_PRVR,   KC_F1,     KC_F2,     KC_F3,     KC_F4,     KC_F5,     KC_TRNS,
                  KC_TRNS,   KC_AMPR,   KC_COLN,   KC_LPRN,   KC_RPRN,   KC_DQUO,   KC_TRNS,
                  KC_TRNS,   KC_DLR,    KC_HASH,   KC_LCBR,   KC_RCBR,   KC_QUOT,
                  KC_TRNS,   KC_CIRC,   KC_ASTR,   KC_LBRC,   KC_RBRC,   KC_GRV,    KC_TRNS,
                  KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,

                  KC_TRNS,   KC_TRNS,
                  KC_TRNS,
                  KC_TRNS,   KC_TRNS,   KC_TRNS,

                  // right hand
                  KC_TRNS,   KC_F6,     KC_F7,     KC_F8,     KC_F9,     KC_F10,    KC_F11,
                  KC_TRNS,   KC_AT,     KC_MINS,   KC_GT,     KC_TILD,   KC_TRNS,   KC_F12,
                  KC_EXLM,   KC_EQL,    KC_GT,     KC_PERC,   KC_QUES,   KC_TRNS,
                  KC_TRNS,   KC_LT,     KC_PIPE,   KC_GT,     KC_PLUS,   KC_BSLS,   KC_TRNS,
                  KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,

                  KC_TRNS,   KC_TRNS,
                  KC_TRNS,
                  KC_TRNS,   KC_TRNS,   KC_TRNS
                  ),
};

const uint16_t PROGMEM fn_actions[] = {
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch(keycode) {
    case MY_PRVR:
      SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      return false;
    }
  }
  return true;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

  uint8_t layer = biton32(layer_state);

  ergodox_board_led_on();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  switch (layer) {
    // TODO: Make this relevant to the ErgoDox EZ.
  case 1:
    ergodox_right_led_1_on();
    break;
  case 2:
    ergodox_right_led_3_on();
    break;
  default:
    // none
    break;
  }

};
