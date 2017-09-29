void setup() {
  pinMode(2, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int x = analogRead(A0);
  if ( (x > 0) && (x <= 200)) {
    digitalWrite(2, LOW);
    digitalWrite(9, LOW);
    digitalWrite(11, LOW);
    digitalWrite(13, LOW);
  }
  else if ( (x > 200) && (x <= 400)) {
    digitalWrite(2, LOW);
    digitalWrite(9, LOW);
    digitalWrite(11, LOW);
    digitalWrite(13, HIGH);
  }
  else if ( (x > 400) && (x <= 600)) {
    digitalWrite(2, LOW);
    digitalWrite(9, LOW);
    digitalWrite(11, HIGH);
    digitalWrite(13, HIGH);
  }
  else if ( (x > 600) && (x <= 800)) {
    digitalWrite(2, LOW);
    digitalWrite(9, HIGH);
    digitalWrite(11, HIGH);
    digitalWrite(13, HIGH);
  }
  else { //x>800
    digitalWrite(2, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(11, HIGH);
    digitalWrite(13, HIGH);
  }
  Serial.print("light value: ");
  Serial.println(x);
  delay(200);
}
