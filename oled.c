#include QMK_KEYBOARD_H
#include <stdio.h>

#include "oled.h"
#include "james9909.h"

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

const char *read_layer_state(void);

void draw_current_layer(void) {
    char display[16];
    switch (get_highest_layer(layer_state)) {
        case QWERTY:
            snprintf(display, sizeof(display), "Layer: QWERTY");
            break;
        case WRK:
            snprintf(display, sizeof(display), "Layer: Workman");
            break;
        case SYM:
            snprintf(display, sizeof(display), "Layer: Symbols");
            break;
        case FUN:
            snprintf(display, sizeof(display), "Layer: Fn");
            break;
        case AJS:
            snprintf(display, sizeof(display), "Layer: Adjust");
            break;
        default:
            snprintf(display, sizeof(display), "Layer: %ld", layer_state);
            break;
    }
    oled_write_ln(display, false);
}

// SSD1306 OLED update loop
void oled_task_user(void) {
  if (is_keyboard_master()) {
      draw_current_layer();
  } else {
    oled_write(read_logo(), false);
  }
}
