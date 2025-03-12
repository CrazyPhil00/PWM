#include <Arduino.h>
#include <PWM.h>

#define LED 4 // Led on pin 4

// Initialize PWM object
PWM blink(LED, 10, 50); // Pin 4, Frequency (hz), Dutycyle (%)

void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  // Call the loop function
  blink.loop();
}