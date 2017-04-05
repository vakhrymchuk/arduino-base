/*********************************************************************
 * Simple pin wrapper that represent Relay module.
 * Library set up pin mode to OUTPUT and store pin.
 *
 * Written by Valery Akhrymchuk
*********************************************************************/

#ifndef RELAY_H
#define RELAY_H

#include <Arduino.h>

/**
 * Simple relay implementation.
 * Require one pin and set it to output
 */
class Relay {
public:
    Relay(const byte pin) : pin(pin) {
        pinMode(pin, OUTPUT);
    }

    void enable() const {
        digitalWrite(pin, HIGH);
    }

    void disable() const {
        digitalWrite(pin, LOW);
    }

private:
    const byte pin;
};

#endif
