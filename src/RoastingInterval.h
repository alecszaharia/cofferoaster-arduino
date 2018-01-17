//
// Created by alex on 11/29/17.
//

#ifndef ROASTER_ROASTINGINTERVAL_H
#define ROASTER_ROASTINGINTERVAL_H

#include "Arduino.h"

class RoastingInterval {

private:
    /**
      * value: 1-100
      */
    int fanSpeed = 0;

    /**
     * set value for temperature
     */
    int temperatureSV = 0;

    /**
     * For how many milliseconds we should stay in this state.
     */
    unsigned long duration = 0;

public:

    RoastingInterval();

    RoastingInterval(int fs, int tsv, unsigned long dtime);

    int getFanSpeed() const;

    void setFanSpeed(int fanSpeed);

    int getTemperatureSV() const;

    void setTemperatureSV(int temperatureSV);

    unsigned long getDuration() const;

    void setDuration(unsigned long duration);
};

#endif //ROASTER_ROASTINGINTERVAL_H