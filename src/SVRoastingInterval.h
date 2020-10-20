//
// Created by alex on 11/29/17.
//

#ifndef ROASTER_SVROASTINGINTERVAL_H
#define ROASTER_SVROASTINGINTERVAL_H

#include "Arduino.h"
#include "Interval.h"

class SVRoastingInterval: public Interval {

public:

    SVRoastingInterval(int _fanSpeed, unsigned long _duration, double _temperature);

    double getTemperatureSV() const;   
};

#endif //ROASTER_SVROASTINGINTERVAL_H