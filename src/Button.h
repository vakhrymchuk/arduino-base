/*********************************************************************
 * Button implementations for arduino.
 * The class stores pin, you do not need to remember it, just read
 * values from created object.
 *
 * Written by Valery Akhrymchuk
*********************************************************************/

#pragma once

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

/**
 * Like ButtonPullUp but with additional GND pin.
 */
class ButtonPullUpWithGnd : public ButtonPullUp {
public :
    ButtonPullUpWithGnd(const byte pin, const byte pinGnd) : ButtonPullUp(pin) {
        pinMode(pin, INPUT_PULLUP);

        pinMode(pinGnd, OUTPUT);
        digitalWrite(pinGnd, LOW);
    }
};
