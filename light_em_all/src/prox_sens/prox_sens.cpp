#include "prox_sens.h"

void prox_sens_init(const int prox_sens_trigger_pin, const int prox_sens_echo_pin){
  pinMode(prox_sens_trigger_pin, OUTPUT); // output from arduino
  pinMode(prox_sens_echo_pin, INPUT); // input for arduino (output from sensor)
}
 
long prox_sens_run(const int prox_sens_trigger_pin, const int prox_sens_echo_pin){
  long duration;
  
  // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  digitalWrite(prox_sens_trigger_pin, LOW);
  delayMicroseconds(5);
  digitalWrite(prox_sens_trigger_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(prox_sens_trigger_pin, LOW);
 
  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(prox_sens_echo_pin, INPUT);
  duration = pulseIn(prox_sens_echo_pin, HIGH);
 
  return (duration/2) / 29.1; // Convert the time into a distance in cm
}

bool prox_sens_check_if_connected(const int prox_sens_trigger_pin, const int prox_sens_echo_pin){
  bool firstCheck = prox_sens_run(prox_sens_trigger_pin, prox_sens_echo_pin);
  delay(200);
  bool secondCheck = prox_sens_run(prox_sens_trigger_pin, prox_sens_echo_pin);
  delay(200);
  bool thirdCheck = prox_sens_run(prox_sens_trigger_pin, prox_sens_echo_pin);
  return firstCheck || secondCheck || thirdCheck;
}
