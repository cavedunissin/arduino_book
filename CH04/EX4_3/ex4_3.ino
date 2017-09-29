void setup(){
  Serial.begin(9600);
}

void loop() {
  int sensor = analogRead(A0);
  if(sensor > 0 && sensor < 500) 
  {  
    tone(6, 220, 200);
    delay(200);
    noTone(6);
    Serial.println(sensor);
  }
  else if (sensor > 500 && sensor < 800){
    tone(6, 440, 200);
    delay(200);
    noTone(6);
    Serial.println(sensor);
  }
  else{
    tone(6, 880, 200);
    delay(200);
    noTone(6);
    Serial.println(sensor); 
  }
}//end loop


