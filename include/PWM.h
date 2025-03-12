#include <Arduino.h>

#ifndef UNTITLED_UTIL_H
#define UNTITLED_UTIL_H

class PWM {
public:
    PWM(uint8_t pin, double freq, uint8_t dutyCycle) {
        this->pin = pin;
        this->freq = freq;
        this->dutyCycle = constrain(dutyCycle, 0, 100);

        pinMode(pin, OUTPUT);
        digitalWrite(pin, LOW);

        lastTime = micros();
        state = false;

        updateTimings();
    }

    void loop();

private:
    uint8_t pin;
    double freq;
    uint8_t dutyCycle;
    unsigned long lastTime;
    bool state;

    unsigned long highTime, lowTime;

    void updateTimings();
};

#endif // UNTITLED_UTIL_H