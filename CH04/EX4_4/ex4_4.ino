void setup(){
  Serial.begin(9600);
}

void loop() {
  int sensor = analogRead(A0);
  if(sensor > 500 && sensor < 800) 
  {  
    play(440);
    Serial.println(sensor);
  }
  else if (sensor > 0 && sensor < 500){
    play(220);
    Serial.println(sensor);
  }
  else{
    play(880);
    Serial.println(sensor); 
  }
}//end loop

void play(int freq) {
  tone(6, freq, 200);
  delay(200);
  noTone(6);
}


