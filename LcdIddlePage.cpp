//
// Created by alex on 12/1/17.
//

#include "LcdIddlePage.h"
#include <LiquidCrystal_I2C.h>

LcdIddlePage::LcdIddlePage() {
    
}

void LcdIddlePage::build() { 
    getLcd()->setCursor(0,0);   
    getLcd()->print("Iddle         ");    
}
