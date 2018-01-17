//
// Created by alex on 11/29/17.
//


#ifndef ROASTER_ROASTINGPROFILE_H
#define ROASTER_ROASTINGPROFILE_H

#include "RoastingInterval.h"
#include "TimerAware.h"


const int MAX_INTERVALS = 30;

class RoastingProfile : public TimerAware {

    RoastingInterval **intervals;
    int count=0;
    int current;

public:

    RoastingProfile(int _count);

    ~RoastingProfile();

    void addInterval(RoastingInterval *interval);

    RoastingInterval *getCurrentInterval();

    int getCount() const;

    int getCurrent() const;

    void startProfile();

    void startProfileFrom(int index);

    void stopProfile();

    void run();

    void handle() override;

    void runLastInterval();

};


#endif //ROASTER_ROASTINGPROFILE_H
