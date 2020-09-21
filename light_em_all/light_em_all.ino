#include "light_em_all.h"

void setup() {
  Serial.begin (9600);   // serial port begin
  prox_sens_init(PROX_SENS_TRIGGER_PIN, PROX_SENS_ECHO_PIN);
  light_sens_init(LIGHT_SENS_PIN);
  smart_leds_init(1, SMART_LEDS_PIN, SMART_LEDS_NUMBER);

  PROX_SENS_CONNECTED = prox_sens_check_if_connected(PROX_SENS_TRIGGER_PIN, PROX_SENS_ECHO_PIN);
  LIGHT_SENS_CONNECTED = light_sens_check_if_connected(LIGHT_SENS_PIN);

  delay(200);
}
 
void loop() {
  if(PROX_SENS_CONNECTED){
    long prox_sens_output = prox_sens_run(PROX_SENS_TRIGGER_PIN, PROX_SENS_ECHO_PIN); 
    
    if(prox_sens_output < 100){
      // light all the lights at full brightness
      Serial.print("Proximity sensor: ");
      Serial.print(prox_sens_output);
      Serial.print(" cm\n");
    }
    else if(prox_sens_output < 1000){
      Serial.print("Proximity sensor: ");
      Serial.print(prox_sens_output);
      Serial.print(" cm\n");
    }
    else if(prox_sens_output >= 1000){
      Serial.print("Proximity sensor value error (too big)!\n");
    }
  }
  
  if(LIGHT_SENS_CONNECTED){
    int light_sens_output = light_sens_run(LIGHT_SENS_PIN);
    if(light_sens_output){
      Serial.print("Light sensor: no light\n");  
    }
    else{
      Serial.print("Light sensor: light\n");  
    }
  }
  smart_leds_run(1, SMART_LEDS_NUMBER);
  Serial.println();
  delay(500);
}
