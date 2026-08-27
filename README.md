# 8-Array Line Follower Robot

An Arduino UNO based autonomous line follower robot using an 8-channel IR sensor array, TB6612FNG motor driver, and two N20 600 RPM geared motors.

## Overview

The robot detects and follows a black track on a white surface. Eight infrared sensors provide the line-position information, while the Arduino UNO processes the sensor readings and controls the two motors through the TB6612FNG driver.

The chassis is made from lightweight foam with approximate dimensions of **15 cm × 10 cm**.

## Hardware

- Arduino UNO
- 8-channel digital IR line sensor array
- TB6612FNG dual motor driver
- 2 × N20 600 RPM DC geared motors
- 2 × wheels
- Foam chassis (15 cm × 10 cm)
- Battery / motor power supply
- Jumper wires and mounting materials

## Sensor Logic

The tested sensor uses:

- `0` = black track detected
- `1` = white surface detected

The `IR` pin on the sensor board is left disconnected; the eight outputs D1–D8 are used for line tracking.

## Pin Connections

### IR Sensor → Arduino UNO

| Sensor | Arduino |
|---|---|
| D1 | D2 |
| D2 | D3 |
| D3 | D4 |
| D4 | D5 |
| D5 | A0 |
| D6 | A1 |
| D7 | A2 |
| D8 | A3 |
| VCC | 5V |
| GND | GND |
| IR | Not connected |

### TB6612FNG → Arduino UNO

| TB6612FNG | Arduino |
|---|---|
| PWMA | D6 |
| AIN1 | D7 |
| AIN2 | D8 |
| PWMB | D9 |
| BIN1 | D10 |
| BIN2 | D11 |
| STBY | D12 |
| VCC | 5V |
| GND | GND |

### Motors

- Left motor → A01 / A02
- Right motor → B01 / B02

### Power

- Motor supply positive → TB6612FNG `VM`
- Motor supply negative → TB6612FNG `GND`
- Arduino GND, sensor GND, TB6612FNG GND, and motor-supply negative must share a common ground.

The Arduino can be powered over USB during development. The motors should have an appropriate motor supply connected to `VM` rather than relying on the Arduino 5 V rail.

## Software

The project is programmed using the Arduino IDE. The control code reads all eight sensors, calculates the position of the black line using weighted sensor positions, and applies proportional/derivative correction to the two motor speeds.

## Project Structure

```text
8-Array-Line-Follower/
├── README.md
├── code/
│   ├── line_follower.ino
│   └── motor_test.ino
├── docs/
│   └── project-report.md
└── wiring/
    └── connections.md
```

## Testing

The sensor array was verified using the Arduino Serial Monitor. Example readings included patterns such as:

```text
1 1 1 1 0 0 0 0
0 1 0 0 0 0 1 1
0 1 0 0 0 0 1 0
```

These tests confirmed that individual sensors respond when the black track is moved beneath the array. Both N20 motors were also tested through the TB6612FNG and confirmed to rotate forward.

## Future Improvements

- Better PID tuning for higher speed
- Automatic sensor calibration
- Improved power system
- Stronger/lighter chassis
- Junction and intersection handling
- Competition-oriented optimization

## License

This project is shared for educational and personal robotics use.
