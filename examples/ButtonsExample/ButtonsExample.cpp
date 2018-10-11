/*********************************************************************
 * An example what has two buttons: one default and one with built in
 * pull up resistor. It creates a serial connection and sends the
 * messages when buttons pressed.
 *
 * Written by Valery Akhrymchuk
*********************************************************************/

#include <Arduino.h>
#include "Button.h"

#define BUTTON_PIN 2
#define BUTTON_PULL_UP_PIN 3
#define BUTTON_PULL_UP_PIN2     4
#define BUTTON_PULL_UP_PIN2_GND 5

Button button = Button(BUTTON_PIN);                            // create a default button with INPUT pin mode
ButtonPullUp buttonPullUp = ButtonPullUp(BUTTON_PULL_UP_PIN);  // create the button with built in pull up resistor
ButtonPullUp buttonPullUpWithGnd = ButtonPullUpWithGnd(BUTTON_PULL_UP_PIN2, BUTTON_PULL_UP_PIN2_GND);

void setup() {
    Serial.begin(9600);
    Serial.println("Ready");
}

void loop() {
    if (button.read()) {                   // if button pressed (pin connected to 5 volts)
        Serial.println("Button pressed");  // send the message
    }

    if (buttonPullUp.read()) {                     // if button pressed (pin connected to ground)
        Serial.println("Button pull up pressed");  // send the message
    }

    if (buttonPullUpWithGnd.read()) {               // if button pressed (pin connected to ground)
        Serial.println("Button pull up 2 pressed"); // send the message
    }

    delay(100);
}
