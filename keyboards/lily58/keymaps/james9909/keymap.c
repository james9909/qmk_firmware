#include QMK_KEYBOARD_H

#ifdef PROTOCOL_LUFA
  #include "lufa.h"
  #include "split_util.h"
#endif
#ifdef SSD1306OLED
  #include "ssd1306.h"
#endif

#include "james9909.h"

extern uint8_t is_master;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  \   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------| ADJUST|    |  WORK |------+------+------+------+------+------|
 * |LCtrl |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  | SYMB |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |ADJUST| LGUI | LAlt | /Space  /       \Enter \  |BackSP|  FUN | RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [QWERTY] = LAYOUT( \
    KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,     KC_7,    KC_8,   KC_9,    KC_0, KC_MINS, \
    KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,     KC_U,    KC_I,   KC_O,    KC_P, KC_BSLS, \
   KC_LSFT,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,     KC_J,    KC_K,   KC_L, KC_SCLN, KC_QUOT, \
  KC_LCTRL,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, MO(AJS), TG(WRK),    KC_N,     KC_M, KC_COMM, KC_DOT, KC_SLSH, MO(SYM), \
                              MO(AJS), KC_LGUI, KC_LALT,  KC_SPC,  KC_ENT, KC_BSPC, MO(FUN),  KC_RGUI \
),
/* WORKMAN
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |   ⇩  |   ⇩  |   ⇩  |   ⇩  |   ⇩  |   ⇩  |                    |   ⇩  |   ⇩  |   ⇩  |   ⇩  |   ⇩  |   ⇩  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   ⇩  |   Q  |   D  |   R  |   W  |   B  |                    |   J  |   F  |   U  |   P  |   ;  |   ⇩  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   ⇩  |   A  |   S  |   H  |   I  |   G  |-------.    ,-------|   Y  |   N  |   E  |   O  |   I  |   ⇩  |
 * |------+------+------+------+------+------|   ⇩   |    |   ⇩   |------+------+------+------+------+------|
 * |   ⇩  |   Z  |   X  |   M  |   C  |   V  |-------|    |-------|   K  |   L  |   ⇩  |   ⇩  |   ⇩  |   ⇩  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |   ⇩  |   ⇩  |   ⇩  | /   ⇩   /       \   ⇩  \  |   ⇩  |   ⇩  |   ⇩  |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [WRK] = LAYOUT( \
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
  _______,    KC_Q,    KC_D,    KC_R,    KC_W,    KC_B,                      KC_J,    KC_F,    KC_U,    KC_P, KC_SCLN, _______, \
  _______,    KC_A,    KC_S,    KC_H,    KC_T,    KC_G,                      KC_Y,    KC_N,    KC_E,    KC_O,    KC_I, _______, \
  _______,    KC_Z,    KC_X,    KC_M,    KC_C,    KC_V, _______, _______,    KC_K,    KC_L, _______, _______, _______, _______, \
                             _______, _______, _______, _______, _______,  _______, _______, _______ \
),
/* SYMBOLS
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |   ⇩  |      |      |      |      |      |                    |      |      |      |      |      |   ⇩  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   ⇩  |   !  |   @  |   #  |   $  |   %  |                    |   ^  |   &  |   *  |   (  |   )  |   ⇩  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   ⇩  |   [  |   ]  |   _  |   :  |   +  |-------.    ,-------|   -  |   =  |   {  |   }  |   ⇩  |   ⇩  |
 * |------+------+------+------+------+------|   ⇩   |    |   ⇩   |------+------+------+------+------+------|
 * |   ⇩  |      |      |      |      |   `  |-------|    |-------|   \  |   /  |   ⇩  |   ⇩  |   ⇩  |   ⇩  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |   ⇩  |   ⇩  |   ⇩  | /   ⇩   /       \   ⇩  \  |   ⇩  |   ⇩  |   ⇩  |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[SYM] = LAYOUT( \
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, \
  _______, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______, \
  _______, KC_LBRC, KC_RBRC, KC_UNDS, KC_COLN, KC_PLUS,                   KC_MINS,  KC_EQL, KC_LCBR, KC_RCBR, _______, _______, \
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_TILD, _______, _______, KC_BSLS, KC_SLSH, _______, _______, _______, _______, \
                             _______, _______, _______, _______, _______,  _______, _______, _______ \
),
/* Fn Keys and Arrows
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  F6  |  F7  |  F8  |  F9  | F10  |-------.    ,-------| Left | Down |  Up  |Right |      |      |
 * |------+------+------+------+------+------|   ⇩   |    |   ⇩   |------+------+------+------+------+------|
 * |      |      |      |      | F11  | F12  |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |   ⇩  |   ⇩  |   ⇩  | /   ⇩   /       \   ⇩  \  |   ⇩  |   ⇩  |   ⇩  |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[FUN] = LAYOUT( \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,                     KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_F11,  KC_F12,  _______, _______,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
                            _______, _______, _______,  _______, _______,  _______, _______, _______ \
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |   ⇩  |   ⇩  |   ⇩  | /   ⇩   /       \   ⇩  \  |   ⇩  |   ⇩  |   ⇩  |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [AJS] = LAYOUT( \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
                             _______, _______, _______, _______, _______,  _______, _______, _______ \
)
};

//

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef OLED_DRIVER_ENABLE
    // set_keylog(keycode, record);
#endif
  }
  return true;
}
