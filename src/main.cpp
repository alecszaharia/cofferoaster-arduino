#include "Roaster.h"
#include "PINDefinitions.h"



void setup() {
 // put your setup code here, to run once:
    Serial.begin(9600);
    pinMode(PID_RELAY,OUTPUT);
    digitalWrite(PID_RELAY,LOW);   
}

void loop() {
   Roaster::instance()->run();
}
