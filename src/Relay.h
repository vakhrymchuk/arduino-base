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
    Relay(const byte pin, const byte enabledVoltage = HIGH) : pin(pin), enabledVoltage(enabledVoltage) {
        pinMode(pin, OUTPUT);
    }

    Relay(const byte pin, const byte basePin, const byte enabledVoltage = HIGH) : pin(pin),
                                                                                  enabledVoltage(enabledVoltage) {
        pinMode(pin, OUTPUT);
        pinMode(basePin, OUTPUT);
        digitalWrite(basePin, HIGH - enabledVoltage);
    }

    void enable() {
        digitalWrite(pin, enabledVoltage);
        enabled = true;
    }

    void disable() {
        digitalWrite(pin, HIGH - enabledVoltage);
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
    const byte enabledVoltage;
    bool enabled = false;
};

#endif
