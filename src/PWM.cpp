#include <Arduno.h>
#include "include/PWM.h"

/// Generates a PWM signal based on the set frequency and dutycylce.
/// This function must be called continuously within the loop without interruption to maintain consistent signal generation.
void PWM::loop() {
    unsigned long currentTime = micros();
    unsigned long elapsedTime = currentTime - lastTime;

    if (state && elapsedTime >= highTime) {
        digitalWrite(pin, LOW);
        lastTime += highTime;
        state = false;
    }
    else if (!state && elapsedTime >= lowTime) {
        digitalWrite(pin, HIGH);
        lastTime += lowTime;
        state = true;
    }
}

/// Updates the PWM signal timing based on the current frequency and duty cycle.
void PWM::updateTimings() {
    unsigned long period = (1.0 / freq) * 1000000.0;
    highTime = (period * dutyCycle) / 100;
    lowTime = period - highTime;
}