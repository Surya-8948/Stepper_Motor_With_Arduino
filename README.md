#  Stepper Motor With Arduino

A beginner to advanced Arduino project for learning and controlling **Stepper Motors** using different drivers such as **A4988**, **L298N**, and Arduino libraries like **AccelStepper** and **Stepper**.

This repository is designed for students, hobbyists, robotics enthusiasts, and embedded engineers who want to understand the complete working of stepper motors from scratch.

---

# 📌 Features

* ✅ Stepper Motor Basics
* ✅ NEMA 17 Stepper Motor
* ✅ A4988 Stepper Driver
* ✅ L298N Driver
* ✅ STEP & DIR Control
* ✅ Clockwise / Counter Clockwise Rotation
* ✅ One Revolution
* ✅ Relative & Absolute Movement
* ✅ Speed Control
* ✅ Acceleration & Deceleration
* ✅ Position Control
* ✅ Enable / Disable Driver
* ✅ Microstepping (Full, 1/2, 1/4, 1/8, 1/16)
* ✅ Beginner Friendly Examples
* ✅ Well Commented Arduino Code

---

# 📂 Repository Contents

```
📁 Stepper_Motor_With_Arduino
│
├── Basic Movement
├── NEMA17 + A4988
├── L298N Examples
├── AccelStepper Examples
├── Stepper Library Examples
├── Microstepping Examples
├── Speed Control
├── Direction Control
├── Position Control
├── Wiring Diagrams
└── Documentation
```

---

# 🛠 Hardware Required

* Arduino UNO / Nano / Mega
* NEMA 17 Stepper Motor
* A4988 Driver
* L298N Driver
* External Power Supply (12V Recommended)
* 100µF Capacitor
* Breadboard
* Jumper Wires

---

# 🔌 Pin Connection (A4988)

| A4988  | Arduino     |
| ------ | ----------- |
| STEP   | D2          |
| DIR    | D3          |
| ENABLE | D8          |
| MS1    | D4          |
| MS2    | D5          |
| MS3    | D6          |
| RESET  | 5V          |
| SLEEP  | 5V          |
| VDD    | 5V          |
| GND    | GND         |
| VMOT   | 12V         |
| Motor  | 1A 1B 2A 2B |

> **Note:** Connect a **100µF capacitor** across **VMOT** and **GND** to protect the A4988 driver from voltage spikes.

---

# ⚙ Supported Drivers

* A4988
* L298N
* DRV8825
* TB6600
* ULN2003 (Examples can be added)

---

# 📚 Libraries Used

### AccelStepper

```cpp
#include <AccelStepper.h>
```

Features

* Acceleration
* Deceleration
* Position Control
* Smooth Motion
* Multiple Motors

---

### Stepper

```cpp
#include <Stepper.h>
```

Features

* Basic Stepper Control
* Beginner Friendly
* Fixed Speed Control

---

# 🎯 Microstepping Modes

| MS1  | MS2  | MS3  | Mode         | Steps / Revolution |
| ---- | ---- | ---- | ------------ | -----------------: |
| LOW  | LOW  | LOW  | Full Step    |                200 |
| HIGH | LOW  | LOW  | Half Step    |                400 |
| LOW  | HIGH | LOW  | Quarter Step |                800 |
| HIGH | HIGH | LOW  | 1/8 Step     |               1600 |
| HIGH | HIGH | HIGH | 1/16 Step    |               3200 |

---

# 📖 Topics Covered

* What is Stepper Motor?
* NEMA Standards
* Working Principle
* Coil Sequence
* Rotor & Stator
* STEP Pin
* DIR Pin
* ENABLE Pin
* RESET Pin
* SLEEP Pin
* Current Limiting
* Microstepping
* Speed Control
* RPM Calculation
* Position Control
* Common Mistakes
* Troubleshooting

---

# 💻 Example Functions

```cpp
stepper.move()

stepper.moveTo()

stepper.run()

stepper.runSpeed()

stepper.stop()

stepper.setSpeed()

stepper.setMaxSpeed()

stepper.setAcceleration()

stepper.currentPosition()

stepper.targetPosition()

stepper.distanceToGo()

stepper.isRunning()
```

---

# 📸 Applications

* CNC Machine
* 3D Printer
* Robotic Arm
* Camera Slider
* XY Plotter
* Conveyor System
* Pick and Place Robot
* Automation Projects

---

# 🎓 Who is this Repository For?

* Beginners
* Diploma Students
* B.Tech Students
* Electronics Engineers
* Robotics Engineers
* Embedded Developers
* IoT Enthusiasts

---

# ⭐ Future Updates

* Limit Switch Homing
* Joystick Control
* Bluetooth Control
* WiFi Control
* ESP32 Support
* TB6600 Driver
* Closed Loop Stepper
* CNC G-Code Examples
* Multi-Stepper Synchronization

---

# 🤝 Contributing

Contributions are welcome.

1. Fork the repository.
2. Create a new branch.
3. Commit your changes.
4. Submit a Pull Request.

---

# 👨‍💻 Author

**Surya Mani Bajpai**

Electronics Engineer | Embedded Systems | IoT | Robotics | PCB Design | Arduino | ESP32

---

# 📜 License

This project is released under the **MIT License**. Feel free to use, modify, and distribute it with proper attribution.

---

⭐ If you found this repository useful, don't forget to **Star** the repository and share it with others.
