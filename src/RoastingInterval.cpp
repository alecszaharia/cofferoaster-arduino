//
// Created by alex on 11/29/17.
//

#include "RoastingInterval.h"
#include "Constants.h"


RoastingInterval::RoastingInterval() : fanSpeed(0),
                                       rateOrRaise(0),
                                       starting_temperature(0),
                                       duration(0) {

}

RoastingInterval::RoastingInterval(int fs,
                                   int ror,
                                   double start_temperature,
                                   unsigned long dtime) : fanSpeed(fs),
                                                          rateOrRaise(ror),
                                                          starting_temperature(start_temperature),
                                                          duration(dtime) {
    recalculateInternals();
}

void RoastingInterval::recalculateInternals() {

    double rate_per_second = rateOrRaise / 60; // rete of reice in one second.

    internal_temperature_rate_of_raise = INTERNAL_ROASTING_TICK * rate_per_second;
}

int RoastingInterval::getFanSpeed() const {
    return fanSpeed;
}

void RoastingInterval::setFanSpeed(int fanSpeed) {
    RoastingInterval::fanSpeed = fanSpeed;
}

int RoastingInterval::getTemperatureSV() const {
    return temperature;
}

unsigned long RoastingInterval::getDuration() const {
    return duration;
}

void RoastingInterval::setDuration(unsigned long duration) {
    RoastingInterval::duration = duration;

    recalculateInternals();
}

int RoastingInterval::getRateOrRaise() const {
    return rateOrRaise;
}

void RoastingInterval::setRateOrRaise(int rateOrRaise) {
    RoastingInterval::rateOrRaise = rateOrRaise;

    recalculateInternals();
}

bool RoastingInterval::isIntervalComplete(double _t) {
    return temperature - starting_temperature < rateOrRaise;
}

void RoastingInterval::raiseTemperature() {
    //internal_duration += +INTERNAL_ROASTING_TICK;
    temperature += internal_temperature_rate_of_raise;
}