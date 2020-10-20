//
// Created by alex on 11/29/17.
//

#ifndef ROASTER_INTERVAL_H
#define ROASTER_INTERVAL_H

#include "Arduino.h"

class Interval {

protected:
    /**
      * value: 1-100
      */
    int fanSpeed = 0;

    /**
     * For how many milliseconds we should stay in this state.
     */
    unsigned long duration = 0;

    /**
     * set value for temperature
     */
    double temperature = 0;

public:

    Interval();

    Interval(int _fanSpeed, unsigned long _duration, double _temperature);

    int getFanSpeed() const;

    void setFanSpeed(int _fanSpeed);    


    unsigned long getDuration() const;

    void setDuration(unsigned long _duration);


    double getTemperature() const;

    void setTemperature(double _temperature);

    virtual double getTemperatureSV() const = 0;
};

#endif //ROASTER_INTERVAL_H