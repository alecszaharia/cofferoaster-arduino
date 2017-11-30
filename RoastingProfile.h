//
// Created by alex on 11/29/17.
//

#include "RoastingInterval.h"

#ifndef ROASTER_ROASTINGPROFILE_H
#define ROASTER_ROASTINGPROFILE_H

const int MAX_INTERVALS = 30;

class RoastingProfile {

    RoastingInterval *intervals[MAX_INTERVALS];

public:

    static RoastingProfile* instance();

    RoastingProfile();

    RoastingInterval *getIntervals() const;

    void setIntervals(RoastingInterval *intervals[MAX_INTERVALS]);

    ~RoastingProfile();
};


#endif //ROASTER_ROASTINGPROFILE_H
