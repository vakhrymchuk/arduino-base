/*********************************************************************
 * Class helps to run code with specified period.
 *
 * Written by Valery Akhrymchuk
*********************************************************************/

#pragma once

#include <Arduino.h>
#include "TimeUnit.h"

/**
 * Create event that should be run periodically over interval.
 */
class Interval {
public:

    explicit Interval(unsigned long interval, TimeUnit timeUnit = MS) : intervalMs(interval * timeUnit) {}

    bool isReady() {
        bool value = millis() >= msReady;
        if (value) {
            recalculate();
        }
        return value;
    }

    void recalculate() {
        while (msReady <= millis()) {
            msReady += intervalMs;
        }
    }

    void startWithCurrentTime() {
        msReady = millis() + intervalMs;
    }

    void startWithCurrentTimeEnabled() {
        msReady = millis();
    }

    unsigned long getInterval(TimeUnit timeUnit = MS) const {
        return intervalMs / timeUnit;
    }

    void setInterval(unsigned long interval, TimeUnit timeUnit = MS) {
        this->intervalMs = interval * timeUnit;
    }

private:
    unsigned long intervalMs;
    unsigned long msReady = 0;
};
