#include QMK_KEYBOARD_H

enum custom_keycodes { TJDEV_RESET = SAFE_RANGE, TJDEV_TURBO_SHIFT };

/* clang-format off */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	LAYOUT(
		KC_GESC           , KC_1       , KC_2       , KC_3        , KC_4       , KC_5    , KC_6        , KC_7    , KC_8    , KC_9    , KC_0    , KC_MINS , KC_EQL  , KC_NO   , KC_BSPC ,
		KC_TAB            , KC_Q       , KC_W       , KC_E        , KC_R       , KC_T    , KC_Y        , KC_U    , KC_I    , KC_O    , KC_P    , KC_LBRC , KC_RBRC , KC_BSLS ,
		KC_CAPS           , KC_A       , KC_S       , KC_D        , KC_F       , KC_G    , KC_H        , KC_J    , KC_K    , KC_L    , KC_SCLN , KC_QUOT , KC_ENT  ,
		KC_LSFT           , KC_RGUI    , KC_Z       , KC_X        , KC_C       , KC_V    , KC_B        , KC_N    , KC_M    , KC_COMM , KC_DOT  , KC_SLSH , KC_RSFT , MO(1)   ,
		KC_LCTL           , KC_LALT    , KC_LGUI    , KC_TRNS     , KC_SPC     , KC_TRNS , KC_RGUI     , KC_NO   , KC_NO   , TG(2)   , KC_RCTL
  )                   ,

	LAYOUT(
		KC_GRV            , KC_F1      , KC_F2      , KC_F3       , KC_F4      , KC_F5   , KC_F6       , KC_F7   , KC_F8   , KC_F9   , KC_F10  , KC_F11  , KC_F12  , KC_TRNS , KC_DEL  ,
		KC_TRNS           , RGB_TOG    , RGB_MOD    , RGB_HUI     , RGB_HUD    , RGB_SAI , RGB_SAD     , RGB_VAI , RGB_VAD , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , RESET   ,
		KC_TRNS           , KC_TRNS    , KC_TRNS    , KC_TRNS     , KC_TRNS    , KC_TRNS , KC_TRNS     , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,
		TJDEV_TURBO_SHIFT , KC_TRNS    , KC_TRNS    , KC_TRNS     , KC_TRNS    , KC_TRNS , TJDEV_RESET , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,
		KC_TRNS           , KC_TRNS    , KC_TRNS    , KC_TRNS     , KC_TRNS    , KC_TRNS , KC_TRNS     , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS
  )                   ,

	LAYOUT(
    TO(0)             , KC_TRNS    , KC_TRNS    , KC_TRNS     , KC_TRNS    , KC_TRNS , KC_TRNS     , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,
    KC_TRNS           , KC_TRNS    , KC_TRNS    , KC_TRNS     , KC_TRNS    , KC_TRNS , KC_TRNS     , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,
    KC_TRNS           , KC_TRNS    , KC_TRNS    , KC_TRNS     , KC_TRNS    , KC_TRNS , KC_TRNS     , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,
    KC_TRNS           , KC_TRNS    , KC_TRNS    , KC_TRNS     , KC_TRNS    , KC_TRNS , KC_TRNS     , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_UP   , TG(3)   ,
    KC_TRNS           , KC_TRNS    , KC_TRNS    , KC_TRNS     , KC_TRNS    , KC_TRNS , KC_TRNS     , KC_LEFT , KC_TRNS , KC_DOWN , KC_RIGHT
  )                   ,

	LAYOUT(
    KC_GESC           , KC_TRNS    , KC_TRNS    , KC_TRNS     , KC_TRNS    , KC_TRNS , KC_TRNS     , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,
    KC_TRNS           , KC_TRNS    , KC_MS_UP   , KC_TRNS     , KC_TRNS    , KC_TRNS , KC_TRNS     , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,
    KC_TRNS           , KC_MS_LEFT , KC_MS_DOWN , KC_MS_RIGHT , KC_TRNS    , KC_TRNS , KC_TRNS     , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,
    KC_TRNS           , KC_TRNS    , KC_TRNS    , KC_TRNS     , KC_TRNS    , KC_TRNS , KC_TRNS     , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_UP   , KC_TRNS ,
    KC_MS_BTN2        , KC_TRNS    , KC_TRNS    , KC_TRNS     , KC_MS_BTN1 , KC_TRNS , KC_TRNS     , KC_LEFT , KC_TRNS , KC_DOWN , KC_RIGHT
  ),

};
/* clang-format on */

void tjdev_rgb_reset(void) {
  rgblight_enable_noeeprom();
  rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
  rgblight_sethsv_noeeprom(134, 255, 80);
  rgblight_mode_noeeprom(RGBLIGHT_MODE_RAINBOW_SWIRL);
}

static bool turbo_shift = false;
int turbo_timer;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case TO(0):
    if (record->event.pressed) {
      tjdev_rgb_reset();
    }
    return true;
  case TG(2):
    if (record->event.pressed) {
      rgblight_enable_noeeprom();
      rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
      rgblight_sethsv_noeeprom(68, 150, 80);
      SEND_STRING(SS_TAP(X_DOWN));
    }
    return true;
  case TJDEV_RESET:
    if (record->event.pressed) {
      rgblight_enable_noeeprom();
      rgblight_setrgb(255, 0, 0);
      reset_keyboard();
    }
    return false;
  case TJDEV_TURBO_SHIFT:
    turbo_shift = record->event.pressed;
    turbo_timer = timer_read();
    return false;
  default:
    return true; // Process all other keycodes normally
  }
}
void suspend_wakeup_init_user(void) { tjdev_rgb_reset(); }
void suspend_power_down_user(void) { rgblight_disable_noeeprom(); }

void matrix_scan_user(void) {
  if (turbo_shift && (timer_elapsed(turbo_timer) > 50)) {
    /* SEND_STRING(SS_TAP(X_LSHIFT)); */
    SEND_STRING(SS_DOWN(X_LSHIFT));
    wait_ms(75);
    turbo_timer = timer_read();
    SEND_STRING(SS_UP(X_LSHIFT));
  }
}
/*
static uint16_t key_timer;
key_timer = timer_read();

if (timer_elapsed(key_timer) < 100) {
  // do something if less than 100ms have passed
} else {
  // do something if 100ms or more have passed
}
*/
