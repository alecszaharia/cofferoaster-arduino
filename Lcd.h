//
// Created by alex on 12/1/17.
//

#ifndef ROASTER_DISPLAY_H
#define ROASTER_DISPLAY_H

#include "LcdPageInterface.h";
#include <LiquidCrystal_I2C.h>

const int LCD_ADDRESS = 0x3f;
const int LCD_COLS = 20;
const int LCD_ROWS = 4;

class Lcd {
private:
    LiquidCrystal_I2C *lcd_cristal = new LiquidCrystal_I2C(0x3f, 20, 4);
    LcdPageInterface *page;
public:

    Lcd();
    
    ~Lcd();

    LcdPageInterface *getPage() const;

    static Lcd* instance();

    void setPage(LcdPageInterface *page);

    void render();    
};


#endif //ROASTER_DISPLAY_H
