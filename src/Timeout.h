/*********************************************************************
 * Class helps to run code after specified amount of time.
 *
 * Written by Valery Akhrymchuk
*********************************************************************/

#ifndef TIMEOUT_H
#define TIMEOUT_H

#include <Arduino.h>

/**
 * Create a single event that will be ready after timeout milliseconds.
 */
class Timeout {
public:

    Timeout(unsigned long msReady = 0) : msReady(msReady) {}

    bool isReady() const {
        return millis() >= msReady;
    }

    void start(unsigned int timeout) {
        msReady = millis() + timeout;
    }

    void startSec(unsigned int timeout) {
        start(timeout * 1000);
    }

protected:
    unsigned long msReady = 0;
};

#endif
