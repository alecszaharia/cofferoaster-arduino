
#ifndef LCD_AWARE_H
#define LCD_AWARE_H

#include <LiquidCrystal_I2C.h>

class LcdAware {

protected:
  LiquidCrystal_I2C *lcd;    
  
public:
  LiquidCrystal_I2C *getLcd() const {
    return lcd;
  }

  void setLcd(LiquidCrystal_I2C *_lcd) {
    lcd = _lcd;
  }

};


#endif //LCD_AWARE_H
