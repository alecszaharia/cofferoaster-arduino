//
// Created by alex on 12/1/17.
//


#ifndef ROASTER_DISPLAY_H
#define ROASTER_DISPLAY_H

#include "LcdPageInterface.h"
#include <LiquidCrystal_I2C.h>
#include "TimerAware.h"

const int LCD_ADDRESS = 0x3f;
const int LCD_COLS = 20;
const int LCD_ROWS = 4;

class Lcd: public TimerAware {
private:
    LiquidCrystal_I2C *lcd_cristal = new LiquidCrystal_I2C(0x3f, 20, 4);
    LcdPageInterface *page;
public:

    Lcd();
    
    ~Lcd();

    LcdPageInterface *getPage() const;

    static Lcd* instance();

    void setPage(LcdPageInterface *page);

    LcdPageInterface *setPage();

    void render();

    void clear();

    void handle() override; // this method will be called once in a second
};


#endif //ROASTER_DISPLAY_H
