/*********************************************************************
 * Will return true for the first part of period.
 *
 * Written by Valery Akhrymchuk
*********************************************************************/

#pragma once

class EnabledInterval {
public:

    EnabledInterval(unsigned long periodMs, unsigned long enabledMs) :
            periodMs(periodMs), enabledMs(enabledMs) {}

    bool isEnabled() const {
        auto passedTime = millis() - msStart;
        return (passedTime % periodMs) < enabledMs;
    }

    void start() {
        msStart = millis();
    }


private:
    unsigned long periodMs;
    unsigned long enabledMs;
    unsigned long msStart = 0;
};
