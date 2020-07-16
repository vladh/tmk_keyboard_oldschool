#include "keymap_common.h"

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* 0: Regular layout with Mac media keys on the right */
  [0] = KEYMAP_ASK(
    GRV,  1,    2,    3,    4,    5,    6,    7,    8,    9,    0,    MINS, EQL,    FN10, \
    TAB,  Q,    W,    E,    R,    T,    Y,    U,    I,    O,    P,    LBRC, RBRC, BSLS, MPLY, \
    ESC,  A,    S,    D,    F,    G,    H,    J,    K,    L,    SCLN, QUOT,    ENT,     VOLU, \
    LSFT, Z,    X,    C,    V,    B,    N,    M,    COMM, DOT,  SLSH,    RSFT,    UP,   VOLD, \
    LCTL,  RALT,  LGUI,  FN1,       SPC,      BSPC,  LANG1,   LALT,   RCTL,  LEFT,  DOWN, RGHT
  ),
  /* 1: FN keys and more Mac media keys */
  [1] = KEYMAP_ASK(
    TRNS, F1,   F2,   F3,   F4,   F5,   F6,   F7,   F8,   F9,   F10,  F11,  F12,     FN20, \
    FN22, F19,  F20,  F21, TRNS, TRNS, TRNS, P7,   P8,   P9,   NUMLOCK, TRNS, TRNS, TRNS,  MUTE, \
    FN21, F16,  F17,  F18, TRNS, TRNS, TRNS, P4,   P5,   P6,   TRNS,    TRNS,    TRNS,     MNXT, \
    TRNS, F13,  F14,  F15, TRNS, TRNS, TRNS, P1,   P2,   P3,   TRNS,       TRNS,    TRNS,  MPRV, \
    TRNS,  TRNS,  TRNS,   TRNS,     TRNS,     P0,    DEL,  TRNS,   TRNS,  TRNS,  TRNS,  TRNS
  )
};

enum macro_id {MACRO_POTATO, MACRO_BOOTLOADER, MACRO_LOCK, MACRO_ALT_TAB};

const uint16_t PROGMEM fn_actions[] = {
  [0] = ACTION_DEFAULT_LAYER_SET(0),
  [1] = ACTION_LAYER_MOMENTARY(1),

  [10] = ACTION_MACRO(MACRO_POTATO),

  // Jump to bootloader
  /* [20] = ACTION_MODS_KEY(MOD_LSFT | MOD_RSFT, KC_PAUSE), */
  [20] = ACTION_MACRO(MACRO_BOOTLOADER),
  // Lock
  [21] = ACTION_MODS_KEY(MOD_LSFT | MOD_RSFT, KC_CAPSLOCK),
  /* [21] = ACTION_MACRO(MACRO_LOCK), */
  // Alt+Tab
  /* [21] = ACTION_MODS_KEY(MOD_LALT, KC_TAB), */
  [22] = ACTION_MACRO(MACRO_ALT_TAB),
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
  keyevent_t event = record->event;
  switch (id) {
    case MACRO_POTATO:
      return record->event.pressed ?
        MACRO(I(0), T(P), T(O), T(T), T(A), T(T), T(O), END) :
        MACRO_NONE;
    case MACRO_BOOTLOADER:
      return MACRO(D(LSFT), D(RSFT), D(PAUSE), END);
    /* case MACRO_LOCK: */
    /*   return record->event.pressed ? */
    /*     MACRO(D(LSFT), D(RSFT), D(CAPSLOCK), END) : */
    /*     MACRO_NONE; */
    case MACRO_ALT_TAB:
      return record->event.pressed ?
        MACRO(D(LALT), T(TAB), END) :
        MACRO(U(TAB), END);
  }
  return MACRO_NONE;
}
