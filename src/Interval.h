/*********************************************************************
 * Class helps to run code with specified period.
 *
 * Written by Valery Akhrymchuk
*********************************************************************/

#ifndef INTERVAL_H
#define INTERVAL_H

#include <Arduino.h>

/**
 * Create event that should be run periodically over interval.
 */
class Interval {
public:

    Interval(unsigned long interval) : interval(interval) { }

    bool isReady() {
        bool value = millis() >= msReady;
        if (value) {
            recalculate();
        }
        return value;
    }

    void recalculate() {
        while (msReady <= millis()) {
            msReady += interval;
        }
    }

    void startWithCurrentTime() {
        msReady = millis() + interval;
    }

    void startWithCurrentTimeEnabled() {
        msReady = millis();
    }

private:
    const unsigned long interval;
    unsigned long msReady = 0;
};

#endif
