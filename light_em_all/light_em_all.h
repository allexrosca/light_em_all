#ifndef LIGHT_EM_ALL_H_INCLUDED
#define LIGHT_EM_ALL_H_INCLUDED

#include <Arduino.h>
#include "src/prox_sens/prox_sens.h"
#include "src/light_sens/light_sens.h"
#include "src/sound_sens/sound_sens.h"
#include "src/smart_leds/smart_leds.h"
#include "config.h"

bool PROX_SENS_CONNECTED = false;
bool LIGHT_SENS_CONNECTED = false;
bool SOUND_SENS_CONNECTED = false;

extern void prox_sens_init(const int prox_sens_trigger_pin, const int prox_sens_echo_pin);
extern long prox_sens_run(const int prox_sens_trigger_pin, const int prox_sens_echo_pin);
extern bool prox_sens_check_if_connected(const int prox_sens_trigger_pin, const int prox_sens_echo_pin);

extern void light_sens_init(const int light_sens_pin);
extern int light_sens_run(const int light_sens_pin);
extern bool light_sens_check_if_connected(const int light_sens_pin);

extern int sound_sens_run(const int sound_sens_pin);
extern void sound_sens_init(const int sound_sens_pin);
extern bool sound_sens_check_if_connected(const int sound_sens_pin);

extern void smart_leds_init(const int animation_no, const int smart_leds_number);
extern void smart_leds_run(const int animation_no, const int smart_leds_number);

#endif