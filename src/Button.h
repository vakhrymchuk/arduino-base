/*********************************************************************
 * Button implementations for arduino.
 * The class stores pin, you do not need to remember it, just read
 * values from created object.
 *
 * Written by Valery Akhrymchuk
*********************************************************************/

#ifndef BUTTON_H
#define BUTTON_H

#include <Arduino.h>

/**
 * Simple button implementation.
 * Signal is HIGH when button is enabled.
 * Should be connected to ground with pull down resistor.
 */
class Button {
public:
    Button(const byte pin) : pin(pin) {
        pinMode(pin, INPUT);
    }

    virtual bool read() const {
        return (bool) digitalRead(pin);
    }

protected:
    const byte pin;
};

/**
 * Signal is LOW when button is enabled.
 * Button connected through built in pull up resistor.
 * No need to wire additional resistors.
 */
class ButtonPullUp : public Button {
public :
    ButtonPullUp(const byte pin) : Button(pin) {
        pinMode(pin, INPUT_PULLUP);
    }

    bool read() const final override {
        return !Button::read();
    }
};

#endif
