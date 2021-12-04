/*

Introduction:
This keyboard layout centers around Dvorak,  harnesing the power of the Kyria thumb
clusters and layers to reduce finger movement.
Qwerty is present so you don't have to remap games and any other programs you use.


Guiding ideology:
- Use thumb keys as much as possible
- Minimise home row departure
- Minimize or eliminate non home row pinkie finger use
- Create macros for very common key shortcuts (ctrl + c/v/s, ctrl+shift+home etc.)
- Create macros for very common commands (git status, git pull, git push etc.)

- Use hints to indicate current layer (rgb lighting/OLED display)
- Allow graceful layer handling (emergency return to default layer/layer index layer)


Layers (6)

Base1: dvorak
Base2: qwerty

Layer_1: navigation & keypad
Layer_2: F keys
Layer_3: FE macros
Layer_4: Git macros

*/

// https://github.com/qmk/qmk_firmware/blob/master/keyboards/splitkb/kyria/keymaps/asapjockey/keymap.c

#include QMK_KEYBOARD_H

/* uint16_t copy_paste_timer; */

enum layers {
  DVORAK = 0,
  QWERTY,
};

// Future Layers
/*
  NAVKEYPAD,
  FKEYS,
  FEMACROS,
  GITMACROS
*/

/* Future custom keycodes
enum custom_keycodes {
    KC_LBR = SAFE_RANGE,
    KC_RBR
};
*/


// Future Macros
// enum {
//   HIGHLIGHT_WORD_HOME,
//   HIGHLIGHT_WORD_LEFT,
//   HIGHLIGHT_WORD_RIGHT,
//   HIGHLIGHT_WORD_END
// };

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//   switch (keycode) {
//     case KC_LBR: {
//       if (record->event.pressed) {
//         switch(keycode) {
//           case HIGHLIGHT_WORD_HOME:
//             SEND_STRING("commands");
//             return false; break;
//         }
//       }
//     }
//   }
// };



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*
 * Base Layer: DVORAK
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  ESC   |  ' " | , <  |   .  |   P  |   Y  |                              |   F  |   G  |   C  |   R  |   L  |L_Qwerty|
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |  Tab   |   A  |   O  |   E  |   U  |   I  |                              |   D  |   H  |   T  |   N  |   S  |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LShift | :  ; |   Q  |   J  |   K  |   X  |      |      |  |  Win |      |   B  |   M  |   W  |   V  |   Z  | RShift |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'	
 *                        |      |      | LCtrl| Space| Bksp |  |      | ENTER|  Del |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
  [DVORAK] = LAYOUT(
    KC_ESC,  KC_QUOT,KC_COMM,KC_DOTT,KC_P,    KC_Y,                                                KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    TG(QWERTY),
    KC_TAB,  KC_A,   KC_O,   KC_E,   KC_U,    KC_I,                                                KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    XXXXXXX,
    KC_LSFT, KC_SCLN KC_Q,   KC_J,   KC_K,    KC_X,    XXXXXXX,  XXXXXXX,  KC_LWIN,    XXXXXXX,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_RSFT,
                          XXXXXXX,   XXXXXXX, KC_LCTL, KC_SPC,  KC_BSPC,   XXXXXXX,    KC_ENT,     KC_DEL,  XXXXXXX,  XXXXXXX
  ),





/*
 * Base Layer: QWERTY
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  ESC   |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |  Tab   |   A  |   S  |   D  |   F  |   G  |                              |   H  |   J  |   K  |   L  | ;  : |L_Dvorak|
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |      |  |  Win |      |   N  |   M  | ,  < | . >  | /  ? | RShift |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'	
 *                        |      |      | LCtrl| Space| Bksp |  |      | ENTER|  Del |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [QWERTY] = LAYOUT(
      KC_ESC,  KC_Q,   KC_W,   KC_E,   KC_R,    KC_T,                                                KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    XXXXXXX,
      KC_TAB,  KC_A,   KC_S,   KC_D,   KC_F,    KC_G,                                                KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, TG(DVORAK),
      KC_LSFT, KC_Z,   KC_X,   KC_C,   KC_V,    KC_B,    XXXXXXX, XXXXXXX,    KC_LWIN,  XXXXXXX,     KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_LSFT,
                            XXXXXXX,   XXXXXXX, KC_LCTL, KC_SPC,  KC_BSPC,   XXXXXXX,  KC_ENT,     KC_DEL,  XXXXXXX,  XXXXXXX
    ),





/*
 * Base Layer: nav_keypad_layer
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              |      |   7  |   8  |   9  |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |                              |      |   4  |   5  |   6  |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LShift |      |      |      |      |      |      |      |  |      |      |      |   1  |   2  |   3  |      | RShift |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'	
 *                        |      |      | DEL  | Space| TAB  |  | Bksp | ENTER|      |      |      |
 *                        |      | LCTR |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 *
 *
 *  LAYER MACROS
 *
 *  shift + home
 *  ctrl + shft + left
 *  ctrl + shft + right
 *  shift + end
 *

  [NAVKEYPAD] = LAYOUT(
    KC_TAB,  KC_Q,   KC_W,   KC_E,   KC_R,    KC_T,                                                KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_RCTL,
    KC_LCTL, KC_A,   KC_S,   KC_D,   KC_F,    KC_G,                                                KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,   KC_X,   KC_C,   KC_V,    KC_B,    KC_DEL,  MO(RAISE), MO(ADJUST), KC_ESC,     KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_LSFT,
                          XXXXXXX,   KC_LALT, XXXXXXX, KC_BSPC, MO(LOWER), KC_ENT,     KC_SPC,     KC_LBR,  KC_RBR,  XXXXXXX
  ),
 */




/*
 * Base Layer: f_keys
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |                              |  F6  |  F7  |  F8  |  F9  |  F10 |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LShift |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      | RShift |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'	
 *                        |      |      | DEL  | Space| TAB  |  | Bksp | ENTER|      |      |      |
 *                        |      | LCTR |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'

  [FKEYS] = LAYOUT(
    KC_TAB,  KC_Q,   KC_W,   KC_E,   KC_R,    KC_T,                                                KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_RCTL,
    KC_LCTL, KC_A,   KC_S,   KC_D,   KC_F,    KC_G,                                                KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,   KC_X,   KC_C,   KC_V,    KC_B,    KC_DEL,  MO(RAISE), MO(ADJUST), KC_ESC,     KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_LSFT,
                          XXXXXXX,   KC_LALT, XXXXXXX, KC_BSPC, MO(LOWER), KC_ENT,     KC_SPC,     KC_LBR,  KC_RBR,  XXXXXXX
  ),
 */




/*
 * Base Layer: fe_macros
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  ESC   |      |      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LShift |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      | RShift |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'	
 *                        |      |      | DEL  | Space| TAB  |  | Bksp | ENTER|      |      |      |
 *                        |      | LCTR |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 
  [FEMACROS] = LAYOUT(
    KC_TAB,  KC_Q,   KC_W,   KC_E,   KC_R,    KC_T,                                                KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_RCTL,
    KC_LCTL, KC_A,   KC_S,   KC_D,   KC_F,    KC_G,                                                KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,   KC_X,   KC_C,   KC_V,    KC_B,    KC_DEL,  MO(RAISE), MO(ADJUST), KC_ESC,     KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_LSFT,
                          XXXXXXX,   KC_LALT, XXXXXXX, KC_BSPC, MO(LOWER), KC_ENT,     KC_SPC,     KC_LBR,  KC_RBR,  XXXXXXX
  ),

*/




/*
 * Base Layer: git_macros
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  ESC   |      |      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LShift |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      | RShift |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'	
 *                        |      |      | DEL  | Space| TAB  |  | Bksp | ENTER|      |      |      |
 *                        |      | LCTR |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'

  [GITMACROS] = LAYOUT(
    KC_TAB,  KC_Q,   KC_W,   KC_E,   KC_R,    KC_T,                                                KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_RCTL,
    KC_LCTL, KC_A,   KC_S,   KC_D,   KC_F,    KC_G,                                                KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,   KC_X,   KC_C,   KC_V,    KC_B,    KC_DEL,  MO(RAISE), MO(ADJUST), KC_ESC,     KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_LSFT,
                          XXXXXXX,   KC_LALT, XXXXXXX, KC_BSPC, MO(LOWER), KC_ENT,     KC_SPC,     KC_LBR,  KC_RBR,  XXXXXXX
  ),
 */



// /*
//  * Layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),

};

// END LAYERS





///////////////////////////
// OLED Display settings
#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	return OLED_ROTATION_180;
}

static void render_kyria_logo(void) {
    static const char PROGMEM kyria_logo[] = {
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,192,224,240,112,120, 56, 60, 28, 30, 14, 14, 14,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 14, 14, 14, 30, 28, 60, 56,120,112,240,224,192,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,192,224,240,124, 62, 31, 15,  7,  3,  1,128,192,224,240,120, 56, 60, 28, 30, 14, 14,  7,  7,135,231,127, 31,255,255, 31,127,231,135,  7,  7, 14, 14, 30, 28, 60, 56,120,240,224,192,128,  1,  3,  7, 15, 31, 62,124,240,224,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,240,252,255, 31,  7,  1,  0,  0,192,240,252,254,255,247,243,177,176, 48, 48, 48, 48, 48, 48, 48,120,254,135,  1,  0,  0,255,255,  0,  0,  1,135,254,120, 48, 48, 48, 48, 48, 48, 48,176,177,243,247,255,254,252,240,192,  0,  0,  1,  7, 31,255,252,240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,255,255,255,  0,  0,  0,  0,  0,254,255,255,  1,  1,  7, 30,120,225,129,131,131,134,134,140,140,152,152,177,183,254,248,224,255,255,224,248,254,183,177,152,152,140,140,134,134,131,131,129,225,120, 30,  7,  1,  1,255,255,254,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0,255,255,  0,  0,192,192, 48, 48,  0,  0,240,240,  0,  0,  0,  0,  0,  0,240,240,  0,  0,240,240,192,192, 48, 48, 48, 48,192,192,  0,  0, 48, 48,243,243,  0,  0,  0,  0,  0,  0, 48, 48, 48, 48, 48, 48,192,192,  0,  0,  0,  0,  0,
        0,  0,  0,255,255,255,  0,  0,  0,  0,  0,127,255,255,128,128,224,120, 30,135,129,193,193, 97, 97, 49, 49, 25, 25,141,237,127, 31,  7,255,255,  7, 31,127,237,141, 25, 25, 49, 49, 97, 97,193,193,129,135, 30,120,224,128,128,255,255,127,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0, 63, 63,  3,  3, 12, 12, 48, 48,  0,  0,  0,  0, 51, 51, 51, 51, 51, 51, 15, 15,  0,  0, 63, 63,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 48, 48, 63, 63, 48, 48,  0,  0, 12, 12, 51, 51, 51, 51, 51, 51, 63, 63,  0,  0,  0,  0,  0,
        0,  0,  0,  0, 15, 63,255,248,224,128,  0,  0,  3, 15, 63,127,255,239,207,141, 13, 12, 12, 12, 12, 12, 12, 12, 30,127,225,128,  0,  0,255,255,  0,  0,128,225,127, 30, 12, 12, 12, 12, 12, 12, 12, 13,141,207,239,255,127, 63, 15,  3,  0,  0,128,224,248,255, 63, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  3,  7, 15, 62,124,248,240,224,192,128,  1,  3,  7, 15, 30, 28, 60, 56,120,112,112,224,224,225,231,254,248,255,255,248,254,231,225,224,224,112,112,120, 56, 60, 28, 30, 15,  7,  3,  1,128,192,224,240,248,124, 62, 15,  7,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  7, 15, 14, 30, 28, 60, 56,120,112,112,112,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,112,112,112,120, 56, 60, 28, 30, 14, 15,  7,  3,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
    };
    oled_write_raw_P(kyria_logo, sizeof(kyria_logo));
}

static void render_qmk_logo(void) {
  static const char PROGMEM qmk_logo[] = {
    0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
    0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
    0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};

  oled_write_P(qmk_logo, false);
}

static void render_status(void) {
    // QMK Logo and version information
    render_qmk_logo();
    oled_write_P(PSTR("       Kyria rev1.4\n\n"), false);

    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case DVORAK:
            oled_write_P(PSTR("Dvorak\n"), false);
            break;
        case QWERTY:
            oled_write_P(PSTR("Qwerty\n"), false);
            break;
        default:
            oled_write_P(PSTR("ERR No Layer!\n"), false);
    }

    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("       "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAPS ") : PSTR("       "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCRLCK ") : PSTR("       "), false);
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status(); // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
        render_kyria_logo();
    }
}
#endif