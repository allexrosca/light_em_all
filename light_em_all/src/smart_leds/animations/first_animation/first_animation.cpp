#include "first_animation.h"

CRGB leds[SMART_LEDS_NUMBER];
void first_animation_init(const int smart_leds_number) {
    FastLED.addLeds<WS2812B, SMART_LEDS_PIN, GRB>(leds, smart_leds_number); //smart_leds_pin should be used instead of 8
    FastLED.setBrightness(5);
}

void first_animation_run(const int smart_leds_number, const int charge_led_number) {
    for (int i = 0; i < smart_leds_number; i++) {
        leds[i] = CRGB::Green;
        FastLED.show();
        delay(100);
        if (i != smart_leds_number - 1) {
            leds[i] = CRGB::Black;
        }
    }

    for (int i = smart_leds_number; i >= 0; --i) {
        leds[i] = CRGB::Red;
        FastLED.show();
        delay(50);
        leds[i] = CRGB::Black;
    }

    for (int i = 0; i < charge_led_number; i++) {
        leds[i] = CRGB::Blue;
        FastLED.show();
        delay(50);
    }

    for (int i = 0; i < charge_led_number; i++) {
        leds[i] = CRGB::Green;
        FastLED.show();
        delay(40);
    }

    for (int i = 0; i < charge_led_number; i++) {
        FastLED.setBrightness(100);
        leds[i] = CRGB::Cyan;
        FastLED.show();
        delay(20);
    }
}
