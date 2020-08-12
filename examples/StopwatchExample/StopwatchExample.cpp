/*********************************************************************
 * A blink example without delay function. It stores milliseconds to
 * process blink routine.
 *
 * Written by Valery Akhrymchuk
*********************************************************************/

#include <Arduino.h>
#include "Stopwatch.h"
#include "Led.h"

#define LED_PIN 13

Stopwatch stopwatch;
Led led = Led(LED_PIN);  // create a led object

void setup() {
    stopwatch.start();  // start track time
    led.low();          // switch
}

void loop() {

    if (stopwatch.time(SECOND) >= 2) {     // time more than 2 seconds
        stopwatch.start();                         // reset stopwatch
    } else if (stopwatch.isMoreThan(1, SECOND)) {  // time more than 1 second
        led.high();                                // enable led
    } else {
        led.low();                                 // switch off led
    }

}
