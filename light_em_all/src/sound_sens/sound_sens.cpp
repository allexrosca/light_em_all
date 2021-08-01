#include "sound_sens.h"

void sound_sens_init(const int sound_sens_pin) {
    pinMode(sound_sens_pin, INPUT);
}

int sound_sens_run(const int sound_sens_pin) {
    long sum = 0;
    for (int i = 0; i < reading_loops; i++)
    {
        sum += analogRead(sound_sens_pin);
    }
    // here something doesn't work. if the sensor it's not connected, it returns like it's connected. maybe the threshold should be different
    Serial.println(sensor_threshold - (sum / reading_loops) > 3);
    Serial.println((sum / reading_loops) < sensor_threshold);
    Serial.println((sum / reading_loops));
    if (sensor_threshold - (sum / reading_loops) > 3) {
        return 1;
    }
    else if ((sum / reading_loops) < sensor_threshold){
        return -1;
    }
    return 0;
}


bool sound_sens_check_if_connected(const int sound_sens_pin) {
    return sound_sens_run(sound_sens_pin) != -1;
}
