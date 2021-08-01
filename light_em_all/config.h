#ifndef CONFIG_H_INCLUDED
#define CONFIG_H_INCLUDED

// PINS
constexpr int LIGHT_SENS_PIN = 7;
constexpr int SMART_LEDS_PIN = 8;
constexpr int PROX_SENS_TRIGGER_PIN = 11; // output from arduino
constexpr int PROX_SENS_ECHO_PIN = 12; // input for arduino (output from sensor)
constexpr int SOUND_SENS_PIN = A0;

// OTHERS
constexpr int SMART_LEDS_NUMBER = 178;

#endif
