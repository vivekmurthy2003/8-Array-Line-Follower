// =====================================================
// 8 SENSOR LINE FOLLOWER ROBOT
// Arduino UNO + TB6612FNG + 2 x N20 600 RPM Motors
// BLACK TRACK = 0, WHITE = 1
// =====================================================

const byte sensors[8] = {2, 3, 4, 5, A0, A1, A2, A3};

const byte PWMA = 6;
const byte AIN1 = 7;
const byte AIN2 = 8;
const byte PWMB = 9;
const byte BIN1 = 10;
const byte BIN2 = 11;
const byte STBY = 12;

// Tune these values for your track and battery.
int baseSpeed = 145;
int maxSpeed = 255;
float Kp = 0.055;
float Kd = 0.120;

int lastError = 0;

void setup() {
  for (byte i = 0; i < 8; i++) pinMode(sensors[i], INPUT);

  pinMode(PWMA, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(PWMB, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(STBY, OUTPUT);

  digitalWrite(STBY, HIGH);
  stopMotors();
  delay(500);
}

void loop() {
  int sensor[8];
  for (byte i = 0; i < 8; i++) sensor[i] = digitalRead(sensors[i]);

  const int weights[8] = {-3500, -2500, -1500, -500, 500, 1500, 2500, 3500};
  long sum = 0;
  int count = 0;

  for (byte i = 0; i < 8; i++) {
    if (sensor[i] == 0) {
      sum += weights[i];
      count++;
    }
  }

  // If the line is lost, search in the direction of the last error.
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

  int error = sum / count;
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
