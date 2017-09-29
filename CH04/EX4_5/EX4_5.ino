#include <SimpleSDAudio.h>

void setup()
{ 
  Serial.begin(9600);
  //SdPlay.setSDCSPin(10); // Enable if your SD card CS-Pin is not at Pin 4... 
  SdPlay.init(SSDA_MODE_FULLRATE | SSDA_MODE_STEREO | SSDA_MODE_AUTOWORKER);
  if(!SdPlay.setFile("MIKU.AFM")) 
  {
    Serial.println(F(" not found on card! Error code: "));
    Serial.println(SdPlay.getLastError());
    while(1);
  } 
  
  
}
void loop() {
  Serial.println(F("found."));
   SdPlay.worker();
   SdPlay.play();
   //delay(104*1000); 
   while(1);
}
