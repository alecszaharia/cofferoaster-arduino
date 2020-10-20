//
// Created by alex on 11/29/17.
//

#include "SVRoastingInterval.h"
#include "Constants.h"

SVRoastingInterval::SVRoastingInterval(int _fanSpeed, unsigned long _duration, double _temperature) 
    : Interval(_fanSpeed,_duration,_temperature) {
    
}

double SVRoastingInterval::getTemperatureSV() const {
    return temperature;
}