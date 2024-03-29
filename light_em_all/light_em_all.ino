#include "light_em_all.h"

void setup() {
    Serial.begin(9600);   // serial port begin
    prox_sens_init(PROX_SENS_TRIGGER_PIN, PROX_SENS_ECHO_PIN);
    light_sens_init(LIGHT_SENS_PIN);
    smart_leds_init(1, SMART_LEDS_NUMBER);
    sound_sens_init(SOUND_SENS_PIN);

    PROX_SENS_CONNECTED = prox_sens_check_if_connected(PROX_SENS_TRIGGER_PIN, PROX_SENS_ECHO_PIN);
    LIGHT_SENS_CONNECTED = light_sens_check_if_connected(LIGHT_SENS_PIN);
    SOUND_SENS_CONNECTED = sound_sens_check_if_connected(SOUND_SENS_PIN);

    delay(200);
}

void loop() {
    int light_sens_output = -1;

    if (LIGHT_SENS_CONNECTED) {
        light_sens_output = light_sens_run(LIGHT_SENS_PIN);
    }

    // if there's no light or the light sens is not connected
    if (light_sens_output == 1 || light_sens_output == -1) {
        if (PROX_SENS_CONNECTED) {
            long prox_sens_output = prox_sens_run(PROX_SENS_TRIGGER_PIN, PROX_SENS_ECHO_PIN);

            Serial.print("Proximity sensor: ");
            Serial.print(prox_sens_output);
            Serial.println(" cm\n");

            // person very close -> light all lights at full brightness
            if (prox_sens_output < 100) {
                Serial.print("person very close -> light all lights at full brightness");
            }
            // run normal
            else if (prox_sens_output < 1000) {
                if (SOUND_SENS_CONNECTED) {
                    int x = sound_sens_run(SOUND_SENS_PIN);
                    Serial.println(x);
                    if (x) {
                        Serial.println("sound!");
                    }
                    // run smart leds rocket effect
                }
                Serial.print("run normal");
            }
            else if (prox_sens_output >= 1000) {
                // value too big -> error -> ignore this case
            }
        }
        else {
            // no prox sens connected
        }
    }
    else {
        // too much light in the room -> do nothing
    }

    //  smart_leds_run(1, SMART_LEDS_NUMBER);
    Serial.println();
    delay(100);
}