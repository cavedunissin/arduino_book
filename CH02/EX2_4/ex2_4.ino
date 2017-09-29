int led = 9;           // the pin that the LED is attached to
int brightness = 0;    // how bright the LED is

void setup()  { 
  pinMode(led, OUTPUT);
  randomSeed(analogRead(A0));   //stir the number
} 
brightness=random(255);
void loop()  { 
  analogWrite(led, brightness);    
  delay(random(100));                            
}

