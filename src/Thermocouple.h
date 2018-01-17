//
// Created by alex on 12/10/17.
//

#ifndef COFFEROASTER_THERMOCOUPLE_H
#define COFFEROASTER_THERMOCOUPLE_H


#include <max6675.h>

class Thermocouple: public MAX6675 {
    MAX6675 *thermocouple;
    double temperatureCache;
    unsigned int cacheTime = 500;
    unsigned long targetTime = 0;
public:
    Thermocouple(int8_t SCLK, int8_t CS, int8_t MISO);
    double readCelsius(void);
    double readFahrenheit(void);
};


#endif //COFFEROASTER_THERMOCOUPLE_H
