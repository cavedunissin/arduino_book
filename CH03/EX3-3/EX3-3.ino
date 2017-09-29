int input3 = 5; //Input3-motorA
int input4 = 6; //Input4-motorA
int enable2 = 7;

void setup() {
  pinMode(input3, OUTPUT);
  pinMode(input4, OUTPUT);
  pinMode(enable2, OUTPUT);
}

void loop() {
  digitalWrite(enable2, HIGH);
  digitalWrite(input3, HIGH);
  digitalWrite(input4, LOW);
  delay(1000);
  //馬達正轉
  digitalWrite(input3, LOW);
  digitalWrite(input4, HIGH);
  delay(1000);
  //馬達反轉
  digitalWrite(enable2, LOW);
  delay(1000);
  //馬達停止
}

