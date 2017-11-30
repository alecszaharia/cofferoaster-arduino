//
// Created by alex on 11/29/17.
//

#include "RoastingProfile.h"
#include "RoastingInterval.h"

RoastingProfile::RoastingProfile() {
  
}

RoastingProfile* RoastingProfile::instance() {
    static RoastingProfile profile_instance;
    return &profile_instance;
}

RoastingInterval *RoastingProfile::getIntervals() const {
    return *intervals;
}

void RoastingProfile::setIntervals(RoastingInterval *intervals[MAX_INTERVALS]) {
    for (int i = 0l; i < MAX_INTERVALS; i++) {
        RoastingProfile::intervals[i] = intervals[i];
    }
}

RoastingProfile::~RoastingProfile() {
  
}

