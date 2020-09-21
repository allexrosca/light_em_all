#ifndef SMART_LEDS_H_INCLUDED
#define SMART_LEDS_H_INCLUDED

#include "animations/first_animation/first_animation.h"

const int CHARGE_LED_NUMBER = 10;

extern void first_animation_init(const int smart_leds_pin, const int smart_leds_number);
extern void first_animation_run(const int smart_leds_number, const int charge_led_number);

#endif