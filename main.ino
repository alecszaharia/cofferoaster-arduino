

#include "Roaster.h"
#include "RoastingProfile.h"
#include "RoastingProfile.h"

Roaster *roaster = Roaster::instance();
RoastingProfile *profile =  RoastingProfile::instance(); 

void setup() {
    // put your setup code here, to run once:
  Serial.begin(9600); 

  RoastingInterval *intervals[10];

  for (int i = 0l; i < 10; i++) {
      intervals[i] = new RoastingInterval(i*10,i*10,i*10);
  }

  profile->setIntervals(intervals);
  
 
  Serial.println("Setup complete.");  
}

void loop() {
  roaster->run();
}
