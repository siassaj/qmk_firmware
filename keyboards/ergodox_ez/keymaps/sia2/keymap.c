#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE 0 // default layout
#define SYMB 1 // symbols
#define MACR 2 // function keys & macros

enum custom_keycodes {
  /////  PLACEHOLDER = SAFE_RANGE,
  MY_VRSN
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap 0: Basic layer
   *
   * ,--------------------------------------------------.           ,--------------------------------------------------.
   * | Esc    |   1  |   2  |   3  |   4  |   5  | LEFT |           | DEL  |   6  |   7  |   8  |   9  |   0  | BSpace |
   * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
   * | Tab    |   '  |   ,  |   .  |   P  |   Y  |  /   |           | PgUp |   F  |   G  |   C  |   R  |   L  |  \     |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * | BkSp   |   A  |   O  |   E  |   U  |   I  |------|           |------|   D  |   H  |   T  |   N  |   S  | ENT    |
   * |--------+------+------+------+------+------|  _   |           | PgDn |------+------+------+------+------+--------|
   * | LShift |   ;  |   Q  |   J  |   K  |   X  |      |           |      |   B  |   M  |   W  |   V  |   Z  | RShift |
   * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
   *   | SYMB |      |      |      | SYMB |                                       | SYMB | Left | Down |  Up  | Right|
   *   `----------------------------------'                                       `----------------------------------'
   *                                        ,-------------.       ,-------------.
   *                                        | SYMB |      |       |      | MACR |
   *                                 ,------|------|------|       |------+------+------.
   *                                 |      |      |      |       |      |      |      |
   *                                 | Space| Ctrl |------|       |------| Alt  |Space |.
   *                                 |      |      | Win  |       | MACR |      |      |
   *                                 `--------------------'       `--------------------'
   */
  // If it accepts an argument (i.e, is a function), it doesn't need KC_.
  // Otherwise, it needs KC_*
  [BASE] = LAYOUT_ergodox_pretty(
    KC_ESC,    KC_1,     KC_2,     KC_3,     KC_4,      KC_5,      KC_LEFT,     KC_DEL,    KC_6,      KC_7,      KC_8,     KC_9,     KC_0,   KC_BSPC,
    KC_TAB,    KC_QUOT,  KC_COMM,  KC_DOT,   KC_P,      KC_Y,      KC_SLSH,     KC_PGUP,   KC_F,      KC_G,      KC_C,     KC_R,     KC_L,   KC_BSLS,
    KC_BSPC,   KC_A,     KC_O,     KC_E,     KC_U,      KC_I,                              KC_D,      KC_H,      KC_T,     KC_N,     KC_S,   KC_ENT,
    KC_LSFT,   KC_SCLN,  KC_Q,     KC_J,     KC_K,      KC_X,      KC_UNDS,     KC_PGDN,   KC_B,      KC_M,      KC_W,     KC_V,     KC_Z,   KC_RSFT,
    TT(SYMB),  KC_TRNS,  KC_TRNS,  KC_TRNS,  TT(SYMB),                                                TT(SYMB),  KC_LEFT,  KC_DOWN,  KC_UP,  KC_RIGHT,
                                                        TT(SYMB),  KC_TRNS,     KC_TRNS,   TT(MACR),
                                                                   KC_TRNS,     KC_TRNS,
                                             KC_SPC,    KC_LCTL,   KC_LGUI,     TT(MACR),  KC_LALT,  KC_SPC
                   ),

  /* Keymap 1: Symbol Layer
   *
   * ,--------------------------------------------------.           ,--------------------------------------------------.
   * |Version |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
   * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
   * |        |  &   |  :   |  {   |  }   |  "   |      |           | Home |  @   |  -   |  >   |  ~   |      |        |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * |        |  $   |  #   |  (   |  )   |  '   |------|           |------|  !   |  =   |  >   |  %   |  ?   |        |
   * |--------+------+------+------+------+------|      |           | End  |------+------+------+------+------+--------|
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
  [SYMB] = LAYOUT_ergodox_pretty(
    MY_VRSN,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_AMPR,  KC_COLN,  KC_LCBR,  KC_RCBR,  KC_DQUO,  KC_TRNS,       KC_HOME,  KC_AT,    KC_MINS,  KC_GT,    KC_TILD,  KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_DLR,   KC_HASH,  KC_LPRN,  KC_RPRN,  KC_QUOT,                 KC_EXLM,  KC_EQL,   KC_GT,    KC_PERC,  KC_QUES,  KC_TRNS,
    KC_TRNS,  KC_CIRC,  KC_ASTR,  KC_LBRC,  KC_RBRC,  KC_GRV,   KC_TRNS,       KC_END,   KC_LT,    KC_PIPE,  KC_GT,    KC_PLUS,  KC_BSLS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,                                               KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
                                                      KC_TRNS,  KC_TRNS,       KC_TRNS,  KC_TRNS,
                                                                KC_TRNS,       KC_TRNS,
                                            KC_TRNS,  KC_TRNS,  KC_TRNS,       KC_TRNS,  KC_TRNS,  KC_TRNS
                  ),

  /* Keymap 1: Macro Layer
   *
   * ,--------------------------------------------------.           ,--------------------------------------------------.
   * |Version |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |  F11   |
   * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
   * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |  F12   |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
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
  // Functions & Macros
  [MACR] = LAYOUT_ergodox_pretty(
     MY_VRSN,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_TRNS,     KC_TRNS,  KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,
     KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,     KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_F12,
     KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,                         KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
     KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,     KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
     KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,                                             KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
                                                       KC_TRNS,  KC_TRNS,     KC_TRNS,  KC_TRNS,
                                                                 KC_TRNS,     KC_TRNS,
                                             KC_TRNS,  KC_TRNS,  KC_TRNS,     KC_TRNS,  KC_TRNS,  KC_TRNS
                                 ),
};

const uint16_t PROGMEM fn_actions[] = {
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch(keycode) {
    case MY_VRSN:
      SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      return false;
    }
  }
  return true;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

};

// Runs whenever there is a layer state change.
uint32_t layer_state_set_user(uint32_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = biton32(state);
  switch (layer) {
  case 0:
#ifdef RGBLIGHT_COLOR_LAYER_0
    rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#else
#ifdef RGBLIGHT_ENABLE
    rgblight_init();
#endif
#endif
    break;
  case 1:
    ergodox_right_led_1_on();
#ifdef RGBLIGHT_COLOR_LAYER_1
    rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
#endif
    break;
  case 2:
    ergodox_right_led_2_on();
#ifdef RGBLIGHT_COLOR_LAYER_2
    rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
#endif
    break;
  case 3:
    ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_3
    rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
#endif
    break;
  case 4:
    ergodox_right_led_1_on();
    ergodox_right_led_2_on();
#ifdef RGBLIGHT_COLOR_LAYER_4
    rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
#endif
    break;
  case 5:
    ergodox_right_led_1_on();
    ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_5
    rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
#endif
    break;
  case 6:
    ergodox_right_led_2_on();
    ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_6
    rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
#endif
    break;
  case 7:
    ergodox_right_led_1_on();
    ergodox_right_led_2_on();
    ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_7
    rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
#endif
    break;
  default:
    break;
  }

  return state;
};
