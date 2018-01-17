//
// Created by alex on 12/6/17.
//

#include "StopWatch.h"


void StopWatch::handle() {
    setSeconds(getSeconds() + 1);
}

int StopWatch::getSeconds() const {
    return seconds;
}

int StopWatch::getMinutes() const {
    return minutes;
}

void StopWatch::reset(){
    stop();
    setSeconds(0);
    setMinutes(0);
}

void StopWatch::setSeconds(int seconds) {
    if (seconds >= 60) {
        seconds = 0;
        setMinutes(getMinutes() + 1);
    }

    StopWatch::seconds = seconds;
}

void StopWatch::setMinutes(int minutes) {
    StopWatch::minutes = minutes;
}

String StopWatch::getDisplayString() const {
    String seconds =  String(getSeconds());
    String minutes =  String(getMinutes());

    if(seconds.length()==1)
        seconds = "0"+seconds;

    if(minutes.length()==1)
        minutes = "0"+minutes;

    return minutes+":"+seconds;
}