//
// Created by alex on 11/29/17.
//


#ifndef ROASTER_ROASTINGPROFILE_H
#define ROASTER_ROASTINGPROFILE_H

#include "RoastingInterval.h"
#include "TimerAware.h"
#include "Constants.h"
#include "Thermocouple.h"
#include "Interval.h"


class RoastingProfile : public TimerAware {

    Thermocouple thermocouple;
    Interval **intervals;
    int size=0;
    int count=0;
    int current;

public:

    RoastingProfile(int _size, Thermocouple _thermocouple);

    ~RoastingProfile();

    void addInterval(Interval *interval);

    Interval *getCurrentInterval();

    Interval *getNextInterval();

    int getCount() const;

    int getCurrent() const;

    void startProfile();

    void startProfileFrom(int index);

    void stopProfile();

    void run();

    void handle() override;

    void beforeHandle() override;

    void runLastInterval();
};


#endif //ROASTER_ROASTINGPROFILE_H
