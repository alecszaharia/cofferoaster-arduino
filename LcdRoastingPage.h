//
// Created by alex on 12/1/17.
//

#ifndef ROASTER_LCDROASTINGPAGE_H
#define ROASTER_LCDROASTINGPAGE_H

#include <LiquidCrystal_I2C.h>
#include "LcdPageInterface.h"

class LcdRoastingPage: public LcdPageInterface {
   
public:
    LcdRoastingPage();  
    
    void build() override;
};


#endif //ROASTER_LCDROASTINGPAGE_H
