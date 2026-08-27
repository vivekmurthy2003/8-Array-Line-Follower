// TB6612FNG motor test for Arduino UNO
// PWMA=D6, AIN1=D7, AIN2=D8
// PWMB=D9, BIN1=D10, BIN2=D11
// STBY=D12

const byte PWMA = 6;
const byte AIN1 = 7;
const byte AIN2 = 8;
const byte PWMB = 9;
const byte BIN1 = 10;
const byte BIN2 = 11;
const byte STBY = 12;

void setup() {
  pinMode(PWMA, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(PWMB, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(STBY, OUTPUT);

  digitalWrite(STBY, HIGH);
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);
  digitalWrite(BIN1, HIGH);
  digitalWrite(BIN2, LOW);
  analogWrite(PWMA, 180);
  analogWrite(PWMB, 180);
}

void loop() {
  // Both motors run forward continuously.
}
