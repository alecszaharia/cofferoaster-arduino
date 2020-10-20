//
// Created by alex on 12/5/17.
//

#ifndef COFFEROASTER_TIMER_H
#define COFFEROASTER_TIMER_H

#include <Arduino.h>

typedef enum {
    RUNNING, STOPPED
} State;

class TimerAware {
public:
    TimerAware();

    virtual ~TimerAware() = default;

    explicit TimerAware(unsigned long interval);

    void tick();

    void start();

    void stop();

    void setInterval(unsigned long _interval);

    State getState() const;

    virtual void handle() = 0;

    virtual void beforeHandle();

    virtual void afterHandle();

protected:
    unsigned long ta_interval;
    unsigned long ta_targetTime;
    State ta_state;
};


#endif //COFFEROASTER_TIMER_H
