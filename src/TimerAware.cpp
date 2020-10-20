//
// Created by alex on 12/5/17.
//

#include "TimerAware.h"

TimerAware::TimerAware() {
    setInterval(0);
    TimerAware::ta_targetTime = 0;
    TimerAware::stop();
}


TimerAware::TimerAware(unsigned long _interval) {

    setInterval(_interval);
    TimerAware::stop();
}

void TimerAware::setInterval(unsigned long _interval) {
    TimerAware::ta_interval = _interval;
    TimerAware::ta_targetTime = millis() + _interval;
}

void TimerAware::tick() {
    if (ta_state == STOPPED) {
        Serial.println("Timeaware Stopped.");
        return;
    }

    if (millis() >= ta_targetTime) {
        ta_targetTime = millis() + ta_interval;

        beforeHandle();

        if (ta_state == STOPPED) {
            Serial.println("Timeaware Stopped on before handle.");
            return;
        }

        handle();

        afterHandle();
    }
}

void TimerAware::start() {
    TimerAware::ta_state = RUNNING;
}

void TimerAware::stop() {
    TimerAware::ta_state = STOPPED;
}

void TimerAware::handle() {
    //Serial.println("Dummy handle");
}

void TimerAware::beforeHandle() {
    //Serial.println("Dummy before handle");
}

void TimerAware::afterHandle() {
    //Serial.println("Dummy after handle");
}

State TimerAware::getState() const {
    return ta_state;
}
