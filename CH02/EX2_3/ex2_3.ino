int led = 9;           // the pin that the LED is attached to
int brightness = 0;    // how bright the LED is
int fadeAmount = 5;    // how many points to fade the LED by

void setup() {
  pinMode(led, OUTPUT);     // initialize the pin13 as an output.
} 
void loop() { 
  analogWrite(led, brightness);  
  brightness = brightness + fadeAmount;
  if (brightness == 0 || brightness == 255) {
    fadeAmount = -fadeAmount ; 
  }

  delay(50);

}


