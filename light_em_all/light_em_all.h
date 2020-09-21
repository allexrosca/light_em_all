#ifndef LIGHT_EM_ALL_H_INCLUDED
#define LIGHT_EM_ALL_H_INCLUDED

#include <Arduino.h>
#include "src/prox_sens/prox_sens.h"
#include "src/light_sens/light_sens.h"
#include "src/smart_leds/smart_leds.h"


const int LIGHT_SENS_PIN = 7;
const int SMART_LEDS_PIN = 8;
const int PROX_SENS_TRIGGER_PIN = 11; // output from arduino
const int PROX_SENS_ECHO_PIN = 12; // input for arduino (output from sensor)

constexpr int SMART_LEDS_NUMBER = 50;

bool PROX_SENS_CONNECTED = false;
bool LIGHT_SENS_CONNECTED = false;

extern void prox_sens_init(const int prox_sens_trigger_pin, const int prox_sens_echo_pin);
extern long prox_sens_run(const int prox_sens_trigger_pin, const int prox_sens_echo_pin);
extern bool prox_sens_check_if_connected(const int prox_sens_trigger_pin, const int prox_sens_echo_pin);

extern void light_sens_init(const int light_sens_pin);
extern int light_sens_run(const int light_sens_pin);
extern bool light_sens_check_if_connected(const int light_sens_pin);

extern void smart_leds_init(const int animation_no, const int smart_leds_pin, const int smart_leds_number);
extern void smart_leds_run(const int animation_no, const int smart_leds_number);

#endif