//
// Created by alex on 11/29/17.
//

#include "RoastingInterval.h"

RoastingInterval::RoastingInterval(): fanSpeed(0), temperatureSV(0), duration(0) {}

RoastingInterval::RoastingInterval(int fs, int tsv, unsigned long dtime): fanSpeed(fs), temperatureSV(tsv), duration(dtime) { }

int RoastingInterval::getFanSpeed() const {
    return fanSpeed;
}

void RoastingInterval::setFanSpeed(int fanSpeed) {
    RoastingInterval::fanSpeed = fanSpeed;
}

int RoastingInterval::getTemperatureSV() const {
    return temperatureSV;
}

void RoastingInterval::setTemperatureSV(int temperatureSV) {
    RoastingInterval::temperatureSV = temperatureSV;
}

unsigned long RoastingInterval::getDuration() const {
    return duration;
}

void RoastingInterval::setDuration(unsigned long duration) {
    RoastingInterval::duration = duration;
}