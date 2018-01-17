//
// Created by alex on 12/10/17.
//

#include "Thermocouple.h"

Thermocouple::Thermocouple(int8_t SCLK, int8_t CS, int8_t MISO) : MAX6675(SCLK, CS, MISO) {

}

double Thermocouple::readFahrenheit(void) {
    return Thermocouple::readCelsius() * 9.0/5.0 + 32;
}

double Thermocouple::readCelsius(void) {

    if (targetTime < millis()) {
        targetTime = millis() + cacheTime;

        return temperatureCache = MAX6675::readCelsius();
    }

    return temperatureCache;
}