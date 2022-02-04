#include QMK_KEYBOARD_H
#include <stdio.h>
char wpm_str[10];


/* uint16_t copy_paste_timer; */

enum layers {
  DVORAK = 0,
  QWERTY,
  LAYERS,
  NUMSYM,
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

/*
// https://docs.qmk.fm/#/feature_rgblight?id=lighting-layers
const rgblight_segment_t PROGMEM led_qwerty_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {1, 9, HSV_ORANGE},
);

const rgblight_segment_t PROGMEM led_dvorak_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {1, 9, HSV_CYAN}
);

const rgblight_segment_t PROGMEM led_index_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {1, 9, HSV_WHITE}
);

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    led_qwerty_layer,
    led_dvorak_layer,
    led_index_layer
);

// Enable the LED layers
void keyboard_post_init_user(void) {
    rgblight_layers = my_rgb_layers;
}


// Assign LED settings to Layers
bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(0, led_state.caps_lock);
    return true;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(1, layer_state_cmp(state, _DVORAK));
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(2, layer_state_cmp(state, _FN));
    rgblight_set_layer_state(3, layer_state_cmp(state, _ADJUST));
    return state;
}
*/





const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*
 * Base Layer: DVORAK
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  ESC   |  ' " | , <  |   .  |   P  |   Y  |                              |   F  |   G  |   C  |   R  |   L  |L_Qwerty|
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |  Tab   |   A  |   O  |   E  |   U  |   I  |                              |   D  |   H  |   T  |   N  |   S  |L_Layers|
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LShift | :  ; |   Q  |   J  |   K  |   X  |      |L_NumS|  |  Win |      |   B  |   M  |   W  |   V  |   Z  | RShift |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'	
 *                        | Left |Right | LCtrl| Space| Bksp |  |R_Alt | ENTER|  Del |  Up  | Down |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
  [DVORAK] = LAYOUT(
    KC_ESC,  KC_QUOT, KC_COMM,KC_DOT ,KC_P,    KC_Y,                                                KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    DF(QWERTY),
    KC_TAB,  KC_A,    KC_O,   KC_E,   KC_U,    KC_I,                                                KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    DF(LAYERS),
    KC_LSFT, KC_SCLN, KC_Q,   KC_J,   KC_K,    KC_X,  XXXXXXX,  MO(NUMSYM),  KC_LWIN,    XXXXXXX,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_RSFT,
                          KC_LEFT,   KC_RGHT, KC_LCTL,  KC_SPC,   KC_BSPC,  KC_RALT,    KC_ENT,     KC_DEL,  KC_UP,  KC_DOWN
  ),





/*
 * Base Layer: QWERTY
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  ESC   |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |L_Dvorak|
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |  Tab   |   A  |   S  |   D  |   F  |   G  |                              |   H  |   J  |   K  |   L  | ;  : |L_Layers|
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |L_NumS|  |  Win |      |   N  |   M  | ,  < | . >  | /  ? | RShift |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'	
 *                        | Left |Right | LCtrl| Space| Bksp |  | RAlt | ENTER|  Del |  Up  | Down |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [QWERTY] = LAYOUT(
      KC_ESC,  KC_Q,   KC_W,   KC_E,   KC_R,    KC_T,                                                KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    DF(DVORAK),
      KC_TAB,  KC_A,   KC_S,   KC_D,   KC_F,    KC_G,                                                KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, DF(LAYERS),
      KC_LSFT, KC_Z,   KC_X,   KC_C,   KC_V,    KC_B,  XXXXXXX, MO(NUMSYM),    KC_LWIN,  XXXXXXX,     KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                            KC_LEFT,   KC_RGHT, KC_LCTL, KC_SPC,  KC_BSPC,    KC_RALT,  KC_ENT,     KC_DEL,  KC_UP,  KC_DOWN
    ),





/*
 * Sym Layer: Numbers, symbols & Vol control
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |    `   |  1   |  2   |  3   |  4   |  5   |                              |   6  |  7   |  8   |  9   |  0   |   =    |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |    ~   |  !   |  @   |  #   |  $   |  %   |                              |   ^  |  &   |  *   |  (   |  )   |   +    |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |    |   |   \  |  :   |  ;   |  -   |  [   |  {   |      |  |      |   }  |   ]  |  _   |  ,   |  .   |  /   |   ?    |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      | LCtrl|      |      |  |      |      | Mute |Vol U |Vol D |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [NUMSYM] = LAYOUT(
      KC_GRV ,   KC_1 ,   KC_2 ,   KC_3 ,   KC_4 ,   KC_5 ,                                       KC_6 ,   KC_7 ,   KC_8 ,   KC_9 ,   KC_0 , KC_EQL ,
      KC_TILD , KC_EXLM,  KC_AT , KC_HASH,  KC_DLR, KC_PERC,                                     KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PLUS,
      KC_PIPE , KC_BSLS, KC_COLN, KC_SCLN, KC_MINS, KC_LBRC, KC_LCBR, _______, _______, KC_RCBR, KC_RBRC, KC_UNDS, KC_COMM,  KC_DOT, KC_SLSH, KC_QUES,
                                  _______, _______, KC_LCTL, _______, _______, _______, _______, KC_MUTE, KC_VOLU, KC_VOLD
    ),





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



/*
 * Adjust Layer: Layer index
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |Dvorak|      |                              |      |      |      |      |      |L_Dvorak|
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |      |QWERTY|      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |NUMSYM|      |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [LAYERS] = LAYOUT(
      _______, _______, _______, _______, DF(DVORAK), _______,                                    _______, _______, _______, _______,  _______, DF(DVORAK),
      _______, _______, _______, _______, DF(QWERTY), _______,                                    _______, _______, _______, _______,  _______, _______,
      _______, _______, _______, _______, MO(NUMSYM), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

};

// END LAYERS





///////////////////////////
// OLED Display settings
#ifdef OLED_ENABLE




// WPM-responsive animation stuff here
#    define IDLE_FRAMES 2
#    define IDLE_SPEED 20  // below this wpm value your animation will idle

// #define PREP_FRAMES 1 // uncomment if >1

#    define TAP_FRAMES 2
#    define TAP_SPEED 40  // above this wpm value typing animation to trigger

#    define ANIM_FRAME_DURATION 200  // how long each frame lasts in ms
// #define SLEEP_TIMER 60000 // should sleep after this period of 0 wpm, needs fixing
#    define ANIM_SIZE 1024  // number of bytes in array, minimize for adequate firmware size, max is 1024

uint32_t anim_timer         = 0;
uint32_t anim_sleep         = 0;
uint8_t  current_idle_frame = 0;
// uint8_t current_prep_frame = 0; // uncomment if PREP_FRAMES >1
uint8_t current_tap_frame = 0;

// Code containing pixel art, contains:
// 5 idle frames, 1 prep frame, and 2 tap frames

// To make your own pixel art:
// save a png/jpeg of an 128x32 image (resource: https://www.pixilart.com/draw )
// follow this guide up to and including "CONVERT YOUR IMAGE" https://docs.splitkb.com/hc/en-us/articles/360013811280-How-do-I-convert-an-image-for-use-on-an-OLED-display-
// replace numbers in brackets with your own
// if you start getting errors when compiling make sure you didn't accedentally delete a bracket

/*
static void render_anim(void) {
    static const char PROGMEM idle[IDLE_FRAMES][ANIM_SIZE] = {{0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x7f, 0x3f, 0xbf, 
0xbf, 0x9f, 0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0x9f, 0x3f, 0x7f, 0x7f, 0x7f, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0x9f, 0xcf, 
0xe7, 0xf3, 0xf9, 0xfd, 0x3d, 0xbd, 0x9d, 0xdd, 0xdd, 0xdb, 0xd0, 0xc6, 0xce, 0x9f, 0x1f, 0xef, 
0xef, 0xf7, 0x77, 0x33, 0xbb, 0x99, 0xdc, 0xde, 0xce, 0xef, 0x67, 0x76, 0x74, 0xf1, 0xf7, 0xef, 
0xdf, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0f, 0xef, 0x9f, 0xe7, 
0x1b, 0xe5, 0x1b, 0xe5, 0x33, 0xcf, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0x87, 0xf7, 0xf7, 0xf3, 0x7b, 0x60, 0x1f, 0x4f, 
0x67, 0xf7, 0xf3, 0xfb, 0xfb, 0xfb, 0x19, 0x1d, 0x0d, 0x0d, 0x4d, 0x4c, 0x1e, 0x1e, 0x3e, 0x7e, 
0x1c, 0x40, 0x7e, 0x3f, 0xbf, 0xbf, 0x9f, 0x5f, 0x41, 0xc0, 0xe4, 0x64, 0x70, 0x30, 0x99, 0xcd, 
0x61, 0x4e, 0xbf, 0xbf, 0x3f, 0xff, 0xff, 0x7f, 0x3f, 0x9f, 0xcf, 0xe7, 0xf0, 0xf7, 0xf7, 0xef, 
0x2f, 0x8f, 0xf7, 0xf1, 0xfd, 0xfc, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0x03, 0xf8, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xfe, 0xfe, 0xfe, 0xfe, 0xee, 0xee, 0x76, 0x34, 0xb4, 0xb4, 0x74, 0x78, 0x6e, 0xb4, 0xba, 
0x1f, 0x5f, 0x4f, 0x2f, 0xae, 0x86, 0x52, 0x4b, 0x29, 0xa5, 0x94, 0xd2, 0xcb, 0x69, 0x04, 0x56, 
0x42, 0xb9, 0x99, 0xcc, 0xe6, 0xf3, 0xf8, 0xfe, 0xff, 0xff, 0xff, 0x7f, 0x3f, 0x8f, 0xe3, 0xf8, 
0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x7f, 0x7f, 0x7f, 0xbf, 0xbf, 0xbf, 0xbf, 0xdf, 
0xdf, 0xdf, 0xdf, 0xef, 0xef, 0xef, 0xef, 0xf7, 0xf7, 0xf7, 0xf7, 0xfb, 0xfb, 0xfb, 0xfb, 0xfd, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0xf3, 0xc7, 0x1f, 0x7f, 0x3f, 0xbf, 0x9f, 0xdf, 0xdf, 0xdf, 
0xdf, 0xdf, 0x9f, 0x3f, 0x7f, 0x7f, 0x7f, 0x78, 0x73, 0x77, 0x66, 0x2d, 0xa5, 0x95, 0xd6, 0xd2, 
0xcb, 0x6b, 0x69, 0x65, 0x34, 0xb6, 0x96, 0xd3, 0x4b, 0x69, 0x65, 0x74, 0xb2, 0xba, 0xb9, 0xbd, 
0xde, 0xdf, 0xdf, 0xdf, 0xef, 0xef, 0xef, 0xef, 0xf7, 0xf1, 0xf4, 0xf6, 0xfb, 0xfb, 0xfb, 0xfb, 
0xfd, 0xfd, 0xfd, 0xfe, 0xfe, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0f, 0xe1, 0xfc, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfd, 0xfd, 0xf9, 0xf1, 0xf5, 0xe5, 0xe4, 0xca, 0x9a, 0xba, 
0xba, 0x3c, 0x7d, 0x7d, 0x7e, 0xfe, 0xfe, 0xfe, 0xff, 0xef, 0x0f, 0x07, 0x07, 0x87, 0xe7, 0xff, 
0xff, 0x7f, 0x1f, 0x0f, 0x1f, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0x7f, 0x7f, 0x7f, 0x7f, 0xbf, 0xbf, 0xbf, 0x3f, 0xdf, 0xaf, 0xef, 0x5f, 0xdf, 0xbf, 
0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x7f, 0x7f, 0x7f, 0xbf, 0xbf, 
0xbf, 0xbf, 0xdf, 0xdf, 0xdf, 0xdf, 0xef, 0xef, 0xef, 0xef, 0xf7, 0xf7, 0xf7, 0xf7, 0xfb, 0xfb, 
0xfb, 0xfd, 0xfd, 0xfd, 0xfd, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfd, 0xfd, 0xfd, 0xfd, 0xf9, 
0xfb, 0xfb, 0xfb, 0xfb, 0xfb, 0xfb, 0xf7, 0xf7, 0xf7, 0xe7, 0xef, 0xef, 0xcf, 0xdf, 0xdf, 0x9f, 
0xbf, 0x7f, 0x7f, 0x3f, 0xbe, 0x9c, 0xd9, 0xc3, 0xef, 0xb7, 0x77, 0x54, 0xd6, 0x8f, 0x3f, 0x77, 
0x71, 0x30, 0xb8, 0xbc, 0xbe, 0xbf, 0x9f, 0xdf, 0xdf, 0xdf, 0xcf, 0xef, 0xef, 0xe7, 0xf7, 0xf7, 
0xf3, 0xfa, 0xf9, 0xfd, 0xf3, 0xe6, 0xc3, 0xd6, 0x95, 0xbb, 0xbb, 0x3a, 0x7b, 0xfb, 0xfd, 0xfe, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xfb, 0xfb, 0xfd, 0xfd, 0xfd, 0xfd, 0xfe, 0xfe, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xfb, 0xf4, 0xf4, 0xc9, 0xd7, 0xd0, 0xd3, 0xd6, 0xe5, 0xe3, 0xe7, 0xe2, 0xe9, 0xf5, 0xf8, 
0xfe, 0xfd, 0xfd, 0xf9, 0xf9, 0xf1, 0xf1, 0xe1, 0xe3, 0xf3, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xfe, 0xfc, 
0xfd, 0xfd, 0xf9, 0xfb, 0xfb, 0xfb, 0xf3, 0xf7, 0xf7, 0xf7, 0xf7, 0xf7, 0xe7, 0xef, 0xef, 0xef},
    {0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x7f, 0x3f, 0xbf, 
0xbf, 0x9f, 0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0x9f, 0x3f, 0x7f, 0x7f, 0x7f, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0x9f, 0xcf, 
0xe7, 0xf3, 0xf9, 0xfd, 0x3d, 0xbd, 0x9d, 0xdd, 0xdd, 0xdb, 0xd0, 0xc6, 0xce, 0x9f, 0x1f, 0xef, 
0xef, 0xf7, 0x77, 0x33, 0xbb, 0x99, 0xdc, 0xde, 0xce, 0xef, 0x67, 0x76, 0x74, 0xf1, 0xf7, 0xef, 
0xdf, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0f, 0x67, 0x99, 0xf2, 0x8d, 0xf2, 0x8d, 0xf3, 0xcf, 0xf7, 
0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0x87, 0xf7, 0xf7, 0xf3, 0x7b, 0x60, 0x1f, 0x4f, 
0x67, 0xf7, 0xf3, 0xfb, 0xfb, 0xfb, 0x19, 0x1d, 0x0d, 0x0d, 0x4d, 0x4c, 0x1e, 0x1e, 0x3e, 0x7e, 
0x1c, 0x40, 0x7e, 0x3f, 0xbf, 0xbf, 0x9f, 0x5f, 0x41, 0xc0, 0xe4, 0x64, 0x70, 0x30, 0x99, 0xcd, 
0x61, 0x4e, 0xbf, 0xbf, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xf8, 0xfb, 0x07, 0xf7, 0xf7, 0xfb, 0xfb, 
0xf8, 0xf3, 0x07, 0x7f, 0xff, 0x03, 0xf8, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xfe, 0xfe, 0xfe, 0xfe, 0xee, 0xee, 0x76, 0x34, 0xb4, 0xb4, 0x74, 0x78, 0x6e, 0xb4, 0xba, 
0x1f, 0x5f, 0x4f, 0x2f, 0xae, 0x86, 0x52, 0x4b, 0x29, 0xa5, 0x94, 0xd2, 0xcb, 0x69, 0x04, 0xd6, 
0xc2, 0xe9, 0xe9, 0xec, 0xee, 0xef, 0xcf, 0xdf, 0xbf, 0xbf, 0x7f, 0x7f, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x7f, 0x7f, 0x7f, 0xbf, 0xbf, 0xbf, 0xbf, 0xdf, 
0xdf, 0xdf, 0xdf, 0xef, 0xef, 0xef, 0xef, 0xf7, 0xf7, 0xf7, 0xf7, 0xfb, 0xfb, 0xfb, 0xfb, 0xfd, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xc7, 0x1f, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xf8, 0xc3, 0x18, 0x73, 0xc7, 0x1f, 0x7f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0x7f, 
0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x78, 0x73, 0x77, 0x66, 0x2d, 0xa5, 0x95, 0xd6, 0xd2, 
0xcb, 0x6b, 0x69, 0x65, 0x34, 0xb6, 0x96, 0xd3, 0x4b, 0x69, 0x65, 0x74, 0xb2, 0xba, 0xb9, 0xbd, 
0xdf, 0xdf, 0xdf, 0x9f, 0xbf, 0x3f, 0x7f, 0x7f, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xfd, 0xfb, 0xfb, 
0xf5, 0xed, 0xdd, 0xde, 0xbe, 0x7e, 0xfe, 0xff, 0xff, 0xfb, 0xe3, 0x03, 0xc3, 0xf3, 0xff, 0xff, 
0xff, 0xff, 0xff, 0x3f, 0x0f, 0x07, 0x0f, 0x9f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xf8, 0xc3, 
0x1f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xfc, 0x7d, 0x78, 0x7a, 0x72, 0xb6, 0xb6, 0xb6, 
0x93, 0xdb, 0xdb, 0xdb, 0xdb, 0xeb, 0xeb, 0xe9, 0xed, 0xf5, 0xf5, 0xf5, 0xf4, 0xfa, 0xfa, 0xfa, 
0xfa, 0xfc, 0xfd, 0xfd, 0xfe, 0xfe, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfc, 0xfd, 0xfd, 0xf9, 0xfb, 0xfb, 0xf3, 0xf7, 
0xe7, 0xdf, 0x1f, 0x0f, 0x6f, 0xe7, 0x36, 0xf1, 0xbb, 0x6d, 0xdd, 0xd5, 0xb5, 0x63, 0x4f, 0x1f, 
0x9f, 0xfb, 0xf8, 0x78, 0x7c, 0x7e, 0x3f, 0x3f, 0x3f, 0x3f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x7f, 0x7f, 0x7f, 0xbf, 0xbf, 
0xbf, 0xbf, 0xdf, 0xdf, 0xdf, 0xdf, 0xef, 0xef, 0xef, 0xef, 0xf7, 0xf7, 0xf7, 0xf7, 0xfb, 0xfb, 
0xfb, 0xfc, 0xfc, 0xfd, 0xfd, 0xfe, 0xfe, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xbf, 0xbf, 0x7f, 0x7f, 0x7f, 
0x7f, 0x3f, 0xbf, 0xbf, 0xbf, 0xbf, 0x9f, 0xdf, 0xdf, 0xdf, 0xcf, 0xef, 0xef, 0xe7, 0xf7, 0xf7, 
0xf3, 0xfa, 0xfd, 0xfd, 0xf2, 0xe5, 0xc4, 0xd4, 0x95, 0xb9, 0xb8, 0x39, 0x78, 0xfa, 0xfd, 0xfe, 
0xff, 0xfe, 0xfe, 0xfe, 0xfc, 0xfc, 0xfc, 0xfc, 0xf8, 0xf8, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xfb, 0xfb, 0xfd, 0xfd, 0xfd, 0xfd, 0xfe, 0xfe, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xfb, 0xf5, 0xf5, 0xcd, 0xdd, 0xda, 0xd6, 0xde, 0xea, 0xef, 0xea, 0xef, 0xed, 0xf7, 0xfa, 
0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xfe, 0xfc, 
0xfd, 0xfd, 0xf9, 0xfb, 0xfb, 0xfb, 0xf3, 0xf7, 0xf7, 0xf7, 0xf7, 0xf7, 0xe7, 0xef, 0xef, 0xef}
};



    // assumes 1 frame prep stage
    void animation_phase(void) {
      current_idle_frame = (current_idle_frame + 1) % IDLE_FRAMES;
      oled_write_raw_P(idle[abs((IDLE_FRAMES - 1) - current_idle_frame)], ANIM_SIZE);
    }
    
    if (get_current_wpm() != 000) {
        oled_on();  // not essential but turns on animation OLED with any alpha keypress
        if (timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION) {
            anim_timer = timer_read32();
            animation_phase();
        }
        anim_sleep = timer_read32();
    } else {
        if (timer_elapsed32(anim_sleep) > OLED_TIMEOUT) {
            oled_off();
        } else {
            if (timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION) {
                anim_timer = timer_read32();
                animation_phase();
            }
        }
    }
}
*/






oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	return OLED_ROTATION_180;
}


static void render_keymap(void) {
  // Host Keyboard Layer Status
  oled_write_P(PSTR("Layer: "), false);
  switch (get_highest_layer(default_layer_state)) {
      case DVORAK:
          oled_write_P(PSTR("Dvorak\n\n"), false);
          oled_write_P(PSTR("' , . p y   f g c r l \n"), false);
          oled_write_P(PSTR("a o e i u   d h t n s \n"), false);
          oled_write_P(PSTR("; q j k x   b m w v z \n"), false);
          break;
      case QWERTY:
          oled_write_P(PSTR("Qwerty\n\n"), false);
          break;
      case NUMSYM:
          oled_write_P(PSTR("Num & Sym\n\n"), false);
          oled_write_P(PSTR("`12345 | 67890= \n"), false);
          oled_write_P(PSTR("~!@#$P | ^&*()+ \n"), false);
          oled_write_P(PSTR("|\\:;-[{ }]_,./? \n"), false);
          break;
      case LAYERS:
          oled_write_P(PSTR("Index Layer\n\n"), false);
          oled_write_P(PSTR("- - - D - | - - - - - \n"), false);
          oled_write_P(PSTR("- - - Q - | - - - - - \n"), false);
          oled_write_P(PSTR("- - - N - | - - - - - \n"), false);
          break;
      default:
          oled_write_P(PSTR("ERR No Layer!\n"), false);
  }
}



// Host Keyboard LED Status
/*
static void render_indicator_status(void) {
  led_t led_state = host_keyboard_led_state();
  oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("       "), false);
  oled_write_P(led_state.caps_lock ? PSTR("CAPS ") : PSTR("       "), false);
  oled_write_P(led_state.scroll_lock ? PSTR("SCRLCK ") : PSTR("       "), false);
}
*/

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    render_keymap();
  } else {
    //render_indicator_status();
    //oled_write_P(PSTR("       Kyria rev1.4\n\n"), false);
    //render_anim();  // renders pixelart
  }
  return false;
}
#endif