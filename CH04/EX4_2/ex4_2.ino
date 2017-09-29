void setup(){
 Serial.begin(9600);
 }

void loop() {
  int sensor = analogRead(A0);
  int x = map(analogRead(A0), 0, 1023, 100, 4000);
  tone(6, x , 200); 
  Serial.println(x);
}//end loop

