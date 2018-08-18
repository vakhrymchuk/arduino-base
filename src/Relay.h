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

    void enable() {
        digitalWrite(pin, HIGH);
        enabled = true;
    }

    void disable() {
        digitalWrite(pin, LOW);
        enabled = false;
    }

    void set(bool state) {
        state ? enable() : disable();
    }

    void invert() {
        set(!isEnabled());
    }

    bool isEnabled() const {
        return enabled;
    }

    const byte getPin() const {
        return pin;
    }

private:
    const byte pin;
    bool enabled = false;
};

#endif
