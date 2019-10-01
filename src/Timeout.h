/*********************************************************************
 * Class helps to run code after specified amount of time.
 *
 * Written by Valery Akhrymchuk
*********************************************************************/

#ifndef TIMEOUT_H
#define TIMEOUT_H

#include <Arduino.h>
#include "TimeUnit.h"

/**
 * Create a single event that will be ready after timeout milliseconds.
 */
class Timeout {
public:

    explicit Timeout(unsigned long msReady = 0) : msReady(msReady) {}

    bool isReady() const {
        return millis() >= msReady;
    }

    void start(unsigned int timeout, const TimeUnit timeUnit = MS) {
        msReady = millis() + timeout * MS;
    }

protected:
    unsigned long msReady;
};

#endif
