//
// Created by alex on 11/29/17.
//

#include "RoastingProfile.h"
#include "Heater.h"


RoastingProfile::RoastingProfile(int _size) {
    count = 0;
    current = -1;
    intervals = new RoastingInterval *[_size];
}

void RoastingProfile::addInterval(RoastingInterval *interval) {
    intervals[count++] = interval;
}

RoastingInterval *RoastingProfile::getCurrentInterval() {
    return intervals[current];
}

RoastingProfile::~RoastingProfile() {
    delete[] intervals;
    count = 0;
}

int RoastingProfile::getCount() const {
    return count;
}

int RoastingProfile::getCurrent() const {
    return current;
}


void RoastingProfile::startProfile() {

    startProfileFrom(0);
}

void RoastingProfile::startProfileFrom(int index) {

    if (index > count || index < 0)
        return;

    current = index;

    Serial.println("start: Change interval: 0");
    Serial.println("Duration: " + String(getCurrentInterval()->getDuration()));
    Serial.println("Count: " + String(getCount()));


    // set the next roast interval change
    TimerAware::setInterval(getCurrentInterval()->getDuration());
    TimerAware::start();

    Heater::instance()->setSetValue(getCurrentInterval()->getTemperatureSV());
    Heater::instance()->on();
}

void RoastingProfile::stopProfile() {
    TimerAware::stop();
    Heater::instance()->off();
}

void RoastingProfile::run() {
    RoastingProfile::tick();
    Heater::instance()->run();
}

void RoastingProfile::runLastInterval() {

    stopProfile();
    startProfileFrom(count-1);
}

void RoastingProfile::handle() {

    if ((current + 1) >= count) {
        Serial.println("Stop");
        RoastingProfile::stopProfile();
        return;
    }

    current++;

    Serial.println("handle: Change interval: " + String(current));
    Serial.println("Duration: " + String(getCurrentInterval()->getDuration()));
    // set the next roast interval change
    Heater::instance()->setSetValue(getCurrentInterval()->getTemperatureSV());
    setInterval(getCurrentInterval()->getDuration());
}
