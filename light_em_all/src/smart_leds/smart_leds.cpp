#include "smart_leds.h"

void smart_leds_init(const int animation_no, const int smart_leds_pin, const int smart_leds_number) {
    if (animation_no == 1) {
        first_animation_init(smart_leds_pin, smart_leds_number);
    }
}


void smart_leds_run(const int animation_no, const int smart_leds_number) {
    if (animation_no == 1) {
        first_animation_run(smart_leds_number, CHARGE_LED_NUMBER);
    }
}

