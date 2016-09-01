/*********************************************************************
 * An example what switch on/off a led depending on a button state.
 *
 * Written by Valery Akhrymchuk
*********************************************************************/

#include <Arduino.h>
#include "Led.h"
#include "Button.h"

#define LED_PIN 13
#define BUTTON_PIN 3

Led led = Led(LED_PIN);                    // create a led object
Button button = ButtonPullUp(BUTTON_PIN);  // create a button with built in pull up resistor

void setup() {
    // do nothing
}

void loop() {
    led.set(button.read());  // switch on led when button pressed
    delay(50);               // safe delay
}
