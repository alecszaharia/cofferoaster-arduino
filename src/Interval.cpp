//
// Created by alex on 11/29/17.
//

#include "Interval.h"
#include "Constants.h"

Interval::Interval(): fanSpeed(0),duration(0),temperature(0) {}

Interval::Interval(int _fanSpeed,unsigned long _duration,double _temperature)
: fanSpeed(_fanSpeed), duration(_duration), temperature(_temperature) {

}

int Interval::getFanSpeed() const {
    return fanSpeed;
}

void Interval::setFanSpeed(int _fanSpeed) {
    fanSpeed = _fanSpeed;
}

unsigned long Interval::getDuration() const {
    return duration;
}

void Interval::setDuration(unsigned long _duration) {
    _duration = duration;
}

double Interval::getTemperature() const {
    return temperature;
}

void Interval::setTemperature(double _temperature) {
    temperature = _temperature;
}
