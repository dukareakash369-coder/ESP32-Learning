# ESP32 Learning | Akash Arun Dukare

A hands-on portfolio documenting my journey in **Embedded Systems, ESP32, IoT, Electronics, and Robotics**. This repository contains practical projects, Arduino sketches, hardware notes, wiring information, and demonstrations as they are built and verified.

> **Learning approach:** Build → Test → Debug → Document → Improve.

## About Me

I am an ENTC engineering student developing practical skills in microcontrollers, embedded C/C++, sensor interfacing, motor control, and hardware–software integration. I use this repository to document what I build and what I learn.

## Project Portfolio

| # | Project | Main technologies | Current status |
|---|---|---|---|
| 01 | [ESP32 Serial Monitor Controlled Motor Car](Projects/01-ESP32-Serial-Controlled-Motor-Car/README.md) | ESP32, motor driver, Arduino Serial Monitor | Demo reviewed; matching source code and wiring details pending |
| 02 | [ESP32 Autonomous Obstacle-Avoiding Robot](Projects/02-ESP32-Autonomous-Obstacle-Avoiding-Robot/README.md) | ESP32, 2 × L298N, 3 × HC-SR04 | Source and documentation added; physical wiring and live test pending |

### Project 01 — Serial Monitor Controlled Motor Car
A motorized car demonstrated with an ESP32 and Arduino IDE workflow. The intended command mapping (F/B/L/R/S) must be checked against the actual sketch before it is documented as confirmed.

### Project 02 — Autonomous Obstacle-Avoiding Robot
An ESP32 robot sketch reads front, left, and right ultrasonic sensors. It drives forward when the front path is clear, then checks the sides and prefers a left turn when an alternate path is clear. See the project README for the GPIO table and electrical safety notes.

## Skills Practiced

- **Microcontrollers:** ESP32 development and Arduino IDE
- **Programming:** Embedded C/C++ (Arduino framework)
- **Interfacing:** GPIO, UART/Serial, ultrasonic sensors
- **Actuation:** DC motors and L298N H-bridge motor drivers
- **Engineering workflow:** wiring checks, debugging, testing, and technical documentation

Skills listed here reflect work represented in this repository; project-specific validation status is shown separately.

## Repository Structure

```text
ESP32-Learning/
├── Projects/
│   ├── 01-ESP32-Serial-Controlled-Motor-Car/
│   │   ├── README.md
│   │   ├── src/
│   │   └── media/
│   └── 02-ESP32-Autonomous-Obstacle-Avoiding-Robot/
│       ├── README.md
│       ├── src/
│       └── media/
├── LEARNING-ROADMAP.md
└── README.md
```

## Engineering & Safety Notes

- Verify every GPIO connection against the actual board and driver before powering the circuit.
- ESP32 GPIO pins are **not 5 V tolerant**. Use a suitable voltage divider or level shifter for 5 V sensor outputs such as the HC-SR04 ECHO pin.
- Use an appropriate external motor supply; never drive motors directly from ESP32 GPIO pins.
- Connect grounds appropriately and test motor direction with the wheels lifted before floor testing.
- Code in this repository is documented from submitted sketches. A written pin table is not proof that the physical wiring has been independently tested.

## Current Priorities

1. Add the exact source code for Project 01 and verify its command mapping.
2. Upload project demo videos and circuit photographs to the matching `media/` folders, or link externally hosted videos.
3. Add clear wiring diagrams for each project.
4. Record test results, known limitations, and improvements.
5. Continue learning communication protocols and additional microcontroller platforms.

## Connect

- GitHub: [@dukareakash369-coder](https://github.com/dukareakash369-coder)

---

*This is a living engineering portfolio. Project status will be updated as hardware, code, and demonstrations are verified.*
