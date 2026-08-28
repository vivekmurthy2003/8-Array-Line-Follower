# 5-Array Line Follower Robot

## Project Overview

This version uses an Arduino Nano, a 5-channel IR sensor array, TB6612FNG dual motor driver, and two N20 600 RPM geared motors to follow a black line on a white surface.

## Hardware

- Arduino Nano
- 5-channel IR sensor array
- TB6612FNG motor driver
- 2 × N20 600 RPM geared motors
- 2 × wheels
- Foam chassis
- Battery/motor power supply

## Sensor Connections

| Sensor | Nano |
|---|---|
| S1 | D2 |
| S2 | D3 |
| S3 | D4 |
| S4 | D5 |
| S5 | A0 |
| VCC | 5V |
| GND | GND |

Sensor logic: `0 = black`, `1 = white`.

## Motor Driver Connections

| TB6612FNG | Nano |
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

Motor supply positive goes to `VM`. Motor supply negative and Nano GND must share a common ground.

## Sensor Weighting

The five sensors are assigned positions from left to right:

```text
S1       S2       S3       S4       S5
-2000   -1000      0      +1000    +2000
```

The Arduino uses the weighted position to determine whether the robot needs to steer left or right. A PD controller adjusts the two motor speeds.

## Initial Tuning

```text
Base speed: 140
Kp: 0.060
Kd: 0.120
```

These values are starting points and can be adjusted for the track, sensor height, motor differences, and battery voltage.

## Test Procedure

1. Place the black line beneath the center sensor S3.
2. Verify that both motors move forward.
3. Move the line toward S1/S2 and verify a left correction.
4. Move the line toward S4/S5 and verify a right correction.
5. Test curves at low speed before increasing `baseSpeed`.
