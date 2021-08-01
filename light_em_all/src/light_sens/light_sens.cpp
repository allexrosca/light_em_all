#include "light_sens.h"

void light_sens_init(const int light_sens_pin) {
    pinMode(light_sens_pin, INPUT);
}

int light_sens_run(const int light_sens_pin) {
    // 0 -> light; 1 -> no light
    return digitalRead(light_sens_pin);
}


bool light_sens_check_if_connected(const int light_sens_pin) {
    bool firstCheck = light_sens_run(light_sens_pin);
    delay(500);
    bool secondCheck = light_sens_run(light_sens_pin);
    delay(500);
    bool thirdCheck = light_sens_run(light_sens_pin);
    return firstCheck || secondCheck || thirdCheck;
}
