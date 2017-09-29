int input1 = 8; //Vin1-A
int input2 = 9; //Vin2-A

void setup() {
  pinMode(input1, OUTPUT);
  pinMode(input2, OUTPUT);
}

void loop() {
  digitalWrite(input1, HIGH);
  digitalWrite(input2, LOW); // 以上兩個指令會讓馬達開始正轉
  delay(1000); // 等候一秒
  digitalWrite(input1, LOW);
  digitalWrite(input2, HIGH); // 馬達反轉
  delay(1000);
}

