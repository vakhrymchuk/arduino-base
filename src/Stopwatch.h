/*********************************************************************
 * Class that helps track time in milliseconds.
 *
 * Written by Valery Akhrymchuk
*********************************************************************/

#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <Arduino.h>
#include "TimeUnit.h"

/**
 * Stopwatch to track time in milliseconds.
 */
class Stopwatch {
public:

    Stopwatch(unsigned long startTime = millis()) : startTime(startTime) {}

    void start() {
        startTime = millis();
    }

    unsigned long time(const TimeUnit timeUnit = MS) const {
        return (millis() - startTime) / timeUnit;
    }

    bool isLessThan(const unsigned long value, const TimeUnit timeUnit = MS) const {
        return time(timeUnit) <= value;
    }

    bool isMoreThan(const unsigned long value, const TimeUnit timeUnit = MS) const {
        return time(timeUnit) >= value;
    }

private:
    unsigned long startTime;
};

#endif
