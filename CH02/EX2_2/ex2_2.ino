// 根據接線圖定義控制R、G、B的腳位
#define LEDR 9
#define LEDG 10
#define LEDB 11

// 關閉LED
void turnoff(){
  digitalWrite(LEDR, LOW);
  digitalWrite(LEDG, LOW);
  digitalWrite(LEDB, LOW);
}

void setup() {                
  pinMode(LEDR, OUTPUT);
  pinMode(LEDG, OUTPUT);
  pinMode(LEDB, OUTPUT);
  turnoff();
}


// 每隔一秒改變LED的顏色，紅、綠、藍、黃、青、洋紅
void loop() {
  turnoff();
  digitalWrite(LEDR, HIGH);
  delay(1000);

  turnoff();
  digitalWrite(LEDG, HIGH);
  delay(1000);

  turnoff();
  digitalWrite(LEDB, HIGH);
  delay(1000);

  turnoff();
  digitalWrite(LEDR, HIGH);
  digitalWrite(LEDG, HIGH);
  delay(1000);

  turnoff();
  digitalWrite(LEDG, HIGH);
  digitalWrite(LEDB, HIGH);
  delay(1000);

  turnoff();
  digitalWrite(LEDB, HIGH);
  digitalWrite(LEDR, HIGH);
  delay(1000);
}


