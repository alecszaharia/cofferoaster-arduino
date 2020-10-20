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
     * Rete of temperature raise
     */
    int rateOrRaise = 0;

    /**
     * Strting temperature
     */
    double starting_temperature = 0;

    /**
     * For how many milliseconds we should stay in this state.
     */
    unsigned long duration = 0;

    /**
     * set value for temperature
     */
    int temperature = 0;

    double internal_temperature_rate_of_raise = 0;

    //int internal_duration = 0;

    void recalculateInternals();

public:

    RoastingInterval();

    RoastingInterval(int fs, int ror, double start_temperature, unsigned long dtime);

    int getFanSpeed() const;

    void setFanSpeed(int fanSpeed);

    int getTemperatureSV() const;

    unsigned long getDuration() const;

    void setDuration(unsigned long duration);

    int getRateOrRaise() const;

    void setRateOrRaise(int rateOrRaise);

    bool isIntervalComplete(double _t);

    void raiseTemperature();
};

#endif //ROASTER_ROASTINGINTERVAL_H