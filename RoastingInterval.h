//
// Created by alex on 11/29/17.
//

#ifndef ROASTER_ROASTINGINTERVAL_H
#define ROASTER_ROASTINGINTERVAL_H


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
    long duration = 0;

public:

    RoastingInterval();

    RoastingInterval(int fs, int tsv, int dtime);

    int getFanSpeed() const;

    void setFanSpeed(int fanSpeed);

    int getTemperatureSV() const;

    void setTemperatureSV(int temperatureSV);

    long getDuration() const;

    void setDuration(long duration);
};

#endif //ROASTER_ROASTINGINTERVAL_H