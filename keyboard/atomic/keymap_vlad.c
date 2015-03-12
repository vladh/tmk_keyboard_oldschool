#include "keymap_common.h"

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* 0: qwerty */
    [0] = KEYMAP_ASK(GRV,  1,    2,    3,    4,    5,    6,    7,    8,    9,    0,    MINS, EQL,    BSPC, \
                     TAB,  Q,    W,    E,    R,    T,    Y,    U,    I,    O,    P,    LBRC, RBRC, BSLS, MPLY, \
                     ESC,  A,    S,    D,    F,    G,    H,    J,    K,    L,    SCLN, QUOT,    ENT,     VOLU, \
                     LSFT, Z,    X,    C,    V,    B,    N,    M,    COMM, DOT,  SLSH,    RSFT,    UP,  VOLD, \
                     LCTL,    LALT,  LGUI,   SPC,     FN1,    SPC,       RGUI, RALT, RCTL, LEFT,   DOWN, RGHT),
    [1] = KEYMAP_ASK(TRNS, F1,   F2,   F3,   F4,   F5,   F6,   F7,   F8,   F9,   F10,  F11,  F12,     TRNS, \
                     TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, \
                     TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,    TRNS,    TRNS, \
                     TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,    TRNS,    TRNS,  TRNS, \
                     TRNS,   TRNS,  TRNS,  TRNS,      TRNS,    TRNS,   TRNS, TRNS, TRNS, TRNS,     TRNS,  TRNS)
};
const uint16_t PROGMEM fn_actions[] = {
  [1] = ACTION_LAYER_MOMENTARY(1)
};
