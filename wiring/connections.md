# Wiring / Connections

## 8-Channel IR Sensor Array → Arduino UNO

| Sensor | Arduino UNO |
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

Sensor logic used in testing: `0 = black`, `1 = white`.

## TB6612FNG → Arduino UNO

| TB6612FNG | Arduino UNO |
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

## Motors

- Left N20 motor → A01 / A02
- Right N20 motor → B01 / B02

## Power

- Motor supply positive → VM
- Motor supply negative → TB6612 GND
- Arduino GND, sensor GND, TB6612 GND and motor-supply negative must be common.

For reliable motor operation, use an appropriate motor power source connected to VM. USB can power the Arduino during development, but the Arduino 5 V rail should not be treated as the preferred supply for the motors.
