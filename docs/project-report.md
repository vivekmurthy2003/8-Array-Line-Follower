# Project Report — 8-Array Line Follower Robot

## 1. Title

**Design and Development of an 8-Sensor Line Follower Robot Using Arduino UNO and TB6612FNG**

## 2. Abstract

This project presents a two-wheel autonomous line follower robot using an Arduino UNO, an 8-channel infrared sensor array, a TB6612FNG dual motor driver, and two N20 600 RPM geared motors. The robot detects a black track on a white surface and continuously adjusts the two motor speeds to remain on the track. A lightweight 15 cm × 10 cm foam chassis was used to reduce overall weight.

## 3. Objectives

- Build an autonomous black-line following robot.
- Interface an 8-channel IR sensor array with Arduino UNO.
- Control two N20 geared motors using TB6612FNG.
- Process sensor readings to estimate line position.
- Apply proportional/derivative correction for steering.
- Develop and test a lightweight mechanical platform.

## 4. Components

- Arduino UNO
- 8-channel digital IR sensor array
- TB6612FNG motor driver
- 2 × N20 600 RPM geared motors
- 2 × wheels
- 15 cm × 10 cm foam chassis
- Motor power supply
- Jumper/connecting wires

## 5. Working Principle

The IR array detects the contrast between the black track and white background. In the tested sensor module, black produces digital `0` and white produces digital `1`. The Arduino reads all eight sensors, assigns position weights from left to right, calculates the line-position error, and changes the left and right motor speeds accordingly.

The control relation is:

`Correction = Kp × Error + Kd × Change in Error`

The motor commands are based on the correction around a selected base speed.

## 6. Mechanical Design

The robot uses a lightweight foam chassis approximately 15 cm × 10 cm. The two N20 motors are mounted on opposite sides to provide differential drive. The 8-sensor array is positioned at the front underside of the chassis, close enough to the track for reliable detection.

## 7. Sensor Testing

The sensors were tested using the Arduino Serial Monitor. Example successful readings were:

```text
1 1 1 1 0 0 0 0
0 1 0 0 0 0 1 1
0 1 0 0 0 0 1 0
```

These tests confirmed that the array responds to changes in the black-line position.

## 8. Motor Testing

Both N20 motors were independently tested through the TB6612FNG motor driver. The final motor test confirmed that both motors rotate forward with the selected wiring.

## 9. Results

After integrating the sensor array, Arduino UNO, TB6612FNG and two motors, the robot successfully detected and followed a black line. The control parameters can be tuned further for higher speed and smoother tracking on different tracks.

## 10. Limitations

- Performance depends on the contrast between the track and background.
- Sensor height affects detection quality.
- Motor battery voltage affects speed and torque.
- PID/PD parameters need adjustment for different track shapes and speeds.

## 11. Future Improvements

- Automatic sensor calibration
- More precise PID tuning
- Higher-speed operation
- Junction and intersection detection
- Improved rechargeable battery system
- Stronger optimized 3D-printed chassis

## 12. Conclusion

The project demonstrates a functional autonomous line follower using an Arduino UNO, an 8-channel IR sensor array, TB6612FNG motor driver and N20 geared motors. The robot successfully detects a black track and adjusts its differential motor speeds to follow the path. The project combines embedded programming, sensor interfacing, motor control and lightweight mechanical construction in a practical robotics application.
