#include "first_animation.h"

void first_animation_init(const int smart_leds_pin, const int smart_leds_number) {
    CRGB leds[smart_leds_number];
    FastLED.addLeds<WS2812B, 5, GRB>(leds, smart_leds_number);
    FastLED.setBrightness(5);
}

void first_animation_run(const int smart_leds_number, const int charge_led_number) {
    CRGB leds[smart_leds_number];
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
    delay(200);

    fill_solid(leds, charge_led_number, CRGB::Black);
    delay(500);
    fill_solid(leds, charge_led_number, CRGB::White);
    delay(1000);

    delay(200);
}
