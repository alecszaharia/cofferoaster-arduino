//
// Created by alex on 12/6/17.
//

#ifndef COFFEROASTER_STOPWATCH_H
#define COFFEROASTER_STOPWATCH_H

#include "TimerAware.h"

class StopWatch : public TimerAware {
    int seconds = 0;
    int minutes = 0;
public:

    StopWatch():TimerAware(1000) {}

    ~StopWatch() {}

    void setSeconds(int seconds);

    void setMinutes(int minutes);

    void reset();

    void handle() override;

    int getSeconds() const;

    int getMinutes() const;

    String getDisplayString() const;
};


#endif //COFFEROASTER_STOPWATCH_H
