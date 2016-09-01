/*********************************************************************
 * Simple pin wrapper that represent Led for arduino.
 * Library set up pin mode to OUTPUT and store pin.
 *
 * Written by Valery Akhrymchuk
*********************************************************************/

#ifndef LED_H
#define LED_H

#include <Arduino.h>

/**
 * Simple led implementation.
 * Require one pin and set it to output
 */
class Led {
public:
    Led(const byte pin) : pin(pin) {
        pinMode(pin, OUTPUT);
    }

    void high() const {
        digitalWrite(pin, HIGH);
    }

    void low() const {
        digitalWrite(pin, LOW);
    }

    void set(const bool value) {
        value ? high() : low();
    }

    void pwm(const int value) {
        analogWrite(pin, value);
    }

private:
    const byte pin;
};

#endif
