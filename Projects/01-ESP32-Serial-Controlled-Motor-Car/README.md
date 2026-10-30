# Project 01 — ESP32 Serial Monitor Controlled Motor Car

## Overview
A beginner embedded-systems project using an ESP32 to control a motor-driven car through commands sent from the Arduino IDE Serial Monitor.

The submitted demo video (54 seconds) shows the hardware setup and the Arduino IDE/Serial Monitor workflow. The exact command mapping and wiring are pending verification against the source code.

## Project goals
- Read commands over serial communication.
- Process movement commands on the ESP32.
- Control DC motors through a motor-driver interface.
- Practice embedded C/C++, GPIO control, serial debugging, and hardware/software integration.

## Expected command interface
Confirm these against the final .ino code before treating them as verified:

| Command | Intended action |
|---|---|
| F | Forward |
| B | Backward |
| L | Left |
| R | Right |
| S | Stop |

## Hardware
- ESP32 development board
- DC motors and motor-driven car chassis
- Motor driver module
- Battery/power supply
- USB cable and computer running Arduino IDE

> Exact motor-driver model, GPIO pin mapping, power wiring, and motor count must be added after reviewing the source code and circuit photo. Do not copy pin numbers from another project.

## Repository contents
- README.md — project notes and setup documentation
- src/ — add the verified Arduino .ino source here
- media/ — add the demo video and project photos here

## Demo
The original 54-second demo video has been reviewed in this conversation. It is not yet stored in this repository; upload it to media/esp32-serial-controlled-motor-car-demo.mp4 or add a shareable video URL here.

## Current status
**Documentation started — awaiting source code and verified wiring details.**

## Skills practiced
ESP32, Arduino IDE, Embedded C/C++, UART/Serial communication, GPIO, motor-driver interfacing, debugging, and hardware/software integration.

## Next steps
1. Add the actual .ino source code.
2. Verify command characters and motor behavior.
3. Document the exact motor-driver model and GPIO pin mapping.
4. Add circuit photos and the demo video.
5. Test the instructions with the actual hardware.