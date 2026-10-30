# Embedded Systems Learning Roadmap

This file tracks practical learning goals and project evidence. Update a topic to **Completed** only after the concept has been studied and a working exercise or project has been tested.

## Current Focus

### ESP32 & Arduino Development
- [ ] ESP32 board setup and Arduino IDE workflow
- [ ] GPIO input/output and digital logic
- [ ] Serial communication and Serial Monitor debugging
- [ ] PWM and motor speed control
- [ ] Digital sensor interfacing
- [ ] Ultrasonic distance measurement
- [ ] UART, I2C, and SPI communication
- [ ] Power supply, grounding, and safe interfacing
- [ ] Structured code, functions, and debugging

### Embedded C/C++
- [ ] Data types, operators, and control flow revision
- [ ] Functions and modular program structure
- [ ] Arrays, strings, and pointers
- [ ] Bitwise operations
- [ ] Timers, interrupts, and non-blocking logic
- [ ] State machines and error handling

## Project Tracker

| Project | Evidence received | Repository work | Remaining validation |
|---|---|---|---|
| 01 — ESP32 Serial Monitor Controlled Motor Car | Demo video received and reviewed in chat | Project README created | Add matching .ino source, verify F/B/L/R/S commands and pin mapping, upload video to media/ |
| 02 — ESP32 Autonomous Obstacle-Avoiding Robot | bot85.ino source received | Sketch and README added | Verify wiring against GPIO table, test sensor readings and motor directions, add its own demo |

## Definition of Done for Each Project
- [ ] Actual source code committed
- [ ] Hardware list and exact board/module models recorded
- [ ] GPIO/pin mapping checked against physical wiring
- [ ] Circuit or wiring diagram added
- [ ] Working demo video or stable external video link added
- [ ] Tested behavior and test conditions documented
- [ ] Known limitations and future improvements listed
- [ ] README reviewed for accuracy

## Portfolio Quality Rules
1. Do not claim a feature works unless it has been tested.
2. Keep source code, wiring, and demo evidence in the same project folder.
3. Never upload Wi-Fi passwords, API keys, tokens, or personal credentials.
4. Use meaningful commit messages describing the actual change.
5. Prefer small, understandable projects with clear evidence over empty repositories or inflated skill claims.

## Next Actions
1. Add and validate the Serial Monitor car sketch for Project 01.
2. Upload the Project 01 video to its media/ folder.
3. Verify Project 02 wiring and run a controlled hardware test.
4. Add wiring diagrams and test notes for both projects.