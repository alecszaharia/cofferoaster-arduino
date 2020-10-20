//
// Created by alex on 11/29/17.
//

#include "RoastingProfile.h"
#include "Heater.h"



RoastingProfile::RoastingProfile(int _size, Thermocouple _thermocouple): thermocouple(_thermocouple) {
    size=_size;
    count = 0;
    current = -1;
    intervals = new Interval *[_size];
    thermocouple = _thermocouple;
}

void RoastingProfile::addInterval(Interval *interval) {
    if(count+1>size) return;
    intervals[count++] = interval;
}

Interval *RoastingProfile::getCurrentInterval() {
    return intervals[current];
}

Interval *RoastingProfile::getNextInterval() {

    if(current+1>=size) return NULL;

    return intervals[++current];
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

    Serial.println("--------------------------------------------------");
    Serial.println("Start: Change interval: 0");
    Serial.println("Duration: " + String(getCurrentInterval()->getDuration()));
    Serial.println("Count: " + String(getCount()));

    // set the next roast interval change
    //TimerAware::setInterval(getCurrentInterval()->getDuration());
    TimerAware::setInterval(INTERNAL_ROASTING_TICK);
    TimerAware::start();

    Heater::instance()->setSetValue(getCurrentInterval()->getTemperatureSV());
    Heater::instance()->on();
}

void RoastingProfile::stopProfile() {
    Serial.println("Stopping profile");
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

void RoastingProfile::beforeHandle() {
    if ((current + 1) >= count) {
        RoastingProfile::stopProfile();
        return;
    }
}

void RoastingProfile::handle() {

    
    Serial.println("---------------------------------------------");
    Serial.println("Handle: Change interval: " + String(current));
    Serial.println("Duration: " + String(getCurrentInterval()->getDuration()/1000)+"s");
    Serial.println("Desired Temperature: " + String(getCurrentInterval()->getTemperatureSV()));
    
    
    // set the next roast interval change

    double temperature = thermocouple.readCelsius();
    double svTemperature = getCurrentInterval()->getTemperatureSV();

    if(temperature >= svTemperature)
    {
        Serial.println("\n\nSet the next roast interval change...");
        
        // obtain the svn temperature from new interval
        svTemperature = getNextInterval()->getTemperatureSV();
    }
   

    Heater::instance()->setSetValue(svTemperature);
}

