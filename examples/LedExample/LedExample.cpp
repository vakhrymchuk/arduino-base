/*********************************************************************
 * A blink example what switch on/off a led with interval of 1 second.
 *
 * Written by Valery Akhrymchuk
*********************************************************************/

#include <Arduino.h>
#include "Led.h"

#define LED_PIN 13

Led led = Led(LED_PIN);  // create a led object

void setup() {
    // do nothing, led pin already in OUTPUT pin mode
}

void loop() {
    led.high();   // enable led
    delay(1000);  // wait 1 second

    led.low();    // switch off led
    delay(1000);  // wait 1 second
}
