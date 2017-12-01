//
// Created by alex on 12/1/17.
//

#ifndef ROASTER_DISPLAYPAGEINTERFACE_H
#define ROASTER_DISPLAYPAGEINTERFACE_H

#include "LcdAware.h";

class LcdPageInterface: public LcdAware {    
public:   
    virtual void build() = 0;
};


#endif //ROASTER_DISPLAYPAGEINTERFACE_H
