/*********************************************************************
 * Class helps to run code after specified amount of time.
 *
 * Written by Valery Akhrymchuk
*********************************************************************/

#pragma once

#include <Arduino.h>
#include "TimeUnit.h"

/**
 * Create a single event that will be ready after timeout milliseconds.
 */
class Timeout {
public:

    explicit Timeout(unsigned long timeout = 0, const TimeUnit timeUnit = MS) {
        start(timeout, MS);
    }

    bool isReady() const {
        return millis() >= msReady;
    }

    void start(unsigned long timeout, const TimeUnit timeUnit = MS) {
        msReady = millis() + timeout * timeUnit;
    }

protected:
    unsigned long msReady;
};
