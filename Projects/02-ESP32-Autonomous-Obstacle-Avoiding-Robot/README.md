# Project 02 — ESP32 Autonomous Obstacle-Avoiding Robot

## Overview
An ESP32-based autonomous robot using two L298N motor-driver modules and three HC-SR04 ultrasonic sensors. The robot checks the front path and, when an obstacle is detected within the configured safe distance, checks the left and right paths. It prefers turning left when clear; otherwise it turns right. If neither side is confirmed clear, it stays stopped.

## Hardware identified from the submitted source code
- ESP32 development board
- 2 × L298N dual H-bridge motor-driver modules
- 3 × HC-SR04 ultrasonic distance sensors
- DC motors and robot chassis (motor count and physical wiring to be confirmed)
- Motor power supply suitable for the motors
- Common ground between ESP32, motor drivers, and sensor supply

## GPIO pin mapping

### L298N driver 1 — left side
| L298N signal | ESP32 GPIO |
|---|---:|
| ENA | 26 |
| IN1 | 27 |
| IN2 | 14 |
| ENB | 32 |
| IN3 | 25 |
| IN4 | 33 |

### L298N driver 2 — right side
| L298N signal | ESP32 GPIO |
|---|---:|
| ENA | 18 |
| IN1 | 19 |
| IN2 | 21 |
| ENB | 13 |
| IN3 | 22 |
| IN4 | 23 |

### HC-SR04 sensors
| Sensor | TRIG | ECHO |
|---|---:|---:|
| Front | 4 | 34 |
| Left | 16 | 35 |
| Right | 17 | 36 |

## How the program works
1. Read the front ultrasonic sensor.
2. If the front distance is at least 30 cm, drive forward.
3. If the front is closer than 30 cm, or the reading is invalid, stop.
4. Read the left and right sensors one at a time to reduce ultrasonic cross-talk.
5. Turn left for 400 ms if the left path is at least 30 cm clear.
6. Otherwise, turn right for 400 ms if the right path is at least 30 cm clear.
7. If neither side is confirmed clear, remain stopped.

The code does not automatically reverse because no rear-facing sensor is defined. Invalid ultrasonic readings are treated as unsafe.

## Configuration
- Safe distance: 30 cm
- Echo timeout: 25,000 microseconds
- Turn duration: 400 ms
- Serial monitor baud rate: 115200

The enable pins are driven HIGH/LOW as digital outputs, so this sketch uses fixed full-enable operation rather than PWM speed control.

## Important wiring and safety notes
- **HC-SR04 ECHO outputs are typically 5 V. ESP32 GPIOs are not 5 V tolerant.** Use a suitable voltage divider or logic-level shifter on every ECHO-to-ESP32 connection.
- Connect all grounds together (ESP32 GND, both L298N GNDs, and sensor GND).
- Power the motors from a suitable motor supply; do not power motors directly from ESP32 GPIO pins.
- Check the actual L298N board labels and motor polarity before powering the chassis.
- Test with wheels lifted and a current-limited/safe supply first. Keep hands clear of moving wheels.
- GPIO mapping is transcribed from the submitted sketch; verify it against the physical wiring before use.

## Repository files
- `src/esp32_obstacle_avoidance.ino` — submitted Arduino sketch
- `README.md` — project documentation
- `media/` — reserved for demo video and project photos

## Validation status
- Source code received and added to the repository.
- Pin mapping and behavior documented from the source.
- Hardware wiring and live operation have not been independently verified.
- Demo video for this autonomous obstacle-avoidance sketch is not yet linked.

## Future improvements
- Add PWM-based motor speed control.
- Add a rear sensor if automatic reversing is required.
- Add calibration for left/right turn duration.
- Add a wiring diagram and a verified demo video.
