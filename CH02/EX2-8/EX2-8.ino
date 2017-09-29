const int buttonPin = 2;     //按鈕連接之腳位編號
const int ledPin =  13;     //LED連接之腳位編號

int buttonState = 0;        //讀取按鈕狀態的變數

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  buttonState = digitalRead(buttonPin); //讀取按鈕狀態
  Serial.println(buttonState); //顯示按鈕狀態
  //檢查按鈕是否被壓下，被壓下時buttonState值為HIGH
  if (buttonState == HIGH) {
    digitalWrite(ledPin, HIGH);
    Serial.println("LED on");
  } else {
    digitalWrite(ledPin, LOW);
    Serial.println("LED off");
  }
  delay(100);
}

