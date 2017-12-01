//
// Created by alex on 12/1/17.
//

#ifndef ROASTER_LCDIDDLEPAGE_H
#define ROASTER_LCDIDDLEPAGE_H

#include <LiquidCrystal_I2C.h>
#include "LcdPageInterface.h"

class LcdIddlePage: public LcdPageInterface {
   
public:
    LcdIddlePage();  
    
    void build() override;
};


#endif //ROASTER_LCDIDDLEPAGE_H
