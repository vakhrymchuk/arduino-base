/*********************************************************************
 * Class that helps track time in milliseconds.
 *
 * Written by Valery Akhrymchuk
*********************************************************************/

#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <Arduino.h>

/**
 * Stopwatch to track time in milliseconds.
 */
class Stopwatch {
public:

    void start() {
        startTime = millis();
    }

    unsigned long time() const {
        return millis() - startTime;
    }

    bool isLessThan(const unsigned long ms) const {
        return time() <= ms;
    }

    bool isMoreThan(const unsigned long ms) const {
        return time() >= ms;
    }

    bool isMoreThanSec(const unsigned long sec) const {
        return isMoreThan(sec * 1000);
    }

private:
    unsigned long startTime = 0;
};

#endif
