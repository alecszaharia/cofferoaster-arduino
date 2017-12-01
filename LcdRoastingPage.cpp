//
// Created by alex on 12/1/17.
//

#include "LcdRoastingPage.h"
#include <LiquidCrystal_I2C.h>

LcdRoastingPage::LcdRoastingPage() {
    
}

void LcdRoastingPage::build() {
  getLcd()->setCursor(0,0);  
  getLcd()->print("Roasting    ");
}
