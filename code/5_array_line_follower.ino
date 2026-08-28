// =====================================================
// 5 ARRAY LINE FOLLOWER ROBOT
// Arduino Nano + TB6612FNG + 2 x N20 600 RPM Motors
// BLACK TRACK = 0
// WHITE SURFACE = 1
// =====================================================

// ---------- 5 IR SENSOR PINS ----------
const byte S1 = 2;
const byte S2 = 3;
const byte S3 = 4;
const byte S4 = 5;
const byte S5 = A0;

// ---------- TB6612FNG PINS ----------
const byte PWMA = 6;
const byte AIN1 = 7;
const byte AIN2 = 8;

const byte PWMB = 9;
const byte BIN1 = 10;
const byte BIN2 = 11;

const byte STBY = 12;

// ---------- SPEED ----------
int baseSpeed = 140;
int maxSpeed = 255;

// ---------- PD CONTROL ----------
float Kp = 0.060;
float Kd = 0.120;
int lastError = 0;

void setup() {
  pinMode(S1, INPUT);
  pinMode(S2, INPUT);
  pinMode(S3, INPUT);
  pinMode(S4, INPUT);
  pinMode(S5, INPUT);

  pinMode(PWMA, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);

  pinMode(PWMB, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);

  pinMode(STBY, OUTPUT);
  digitalWrite(STBY, HIGH);

  stopMotors();
  delay(1000);
}

void loop() {
  int s1 = digitalRead(S1);
  int s2 = digitalRead(S2);
  int s3 = digitalRead(S3);
  int s4 = digitalRead(S4);
  int s5 = digitalRead(S5);

  // BLACK = 0. Calculate line position from left to right.
  int position = 0;
  int count = 0;

  if (s1 == 0) { position += -2000; count++; }
  if (s2 == 0) { position += -1000; count++; }
  if (s3 == 0) { position += 0;     count++; }
  if (s4 == 0) { position += 1000;  count++; }
  if (s5 == 0) { position += 2000;  count++; }

  // Line lost: search in the direction of the last detected error.
  if (count == 0) {
    if (lastError < 0) {
      leftMotor(-70);
      rightMotor(150);
    } else {
      leftMotor(150);
      rightMotor(-70);
    }
    return;
  }

  int error = position / count;
  int derivative = error - lastError;
  int correction = (Kp * error) + (Kd * derivative);
  lastError = error;

  int leftSpeed = constrain(baseSpeed + correction, -maxSpeed, maxSpeed);
  int rightSpeed = constrain(baseSpeed - correction, -maxSpeed, maxSpeed);

  leftMotor(leftSpeed);
  rightMotor(rightSpeed);
}

void leftMotor(int speed) {
  speed = constrain(speed, -255, 255);

  if (speed > 0) {
    digitalWrite(AIN1, HIGH);
    digitalWrite(AIN2, LOW);
    analogWrite(PWMA, speed);
  } else if (speed < 0) {
    digitalWrite(AIN1, LOW);
    digitalWrite(AIN2, HIGH);
    analogWrite(PWMA, -speed);
  } else {
    digitalWrite(AIN1, LOW);
    digitalWrite(AIN2, LOW);
    analogWrite(PWMA, 0);
  }
}

void rightMotor(int speed) {
  speed = constrain(speed, -255, 255);

  if (speed > 0) {
    digitalWrite(BIN1, HIGH);
    digitalWrite(BIN2, LOW);
    analogWrite(PWMB, speed);
  } else if (speed < 0) {
    digitalWrite(BIN1, LOW);
    digitalWrite(BIN2, HIGH);
    analogWrite(PWMB, -speed);
  } else {
    digitalWrite(BIN1, LOW);
    digitalWrite(BIN2, LOW);
    analogWrite(PWMB, 0);
  }
}

void stopMotors() {
  analogWrite(PWMA, 0);
  analogWrite(PWMB, 0);

  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, LOW);
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, LOW);
}
