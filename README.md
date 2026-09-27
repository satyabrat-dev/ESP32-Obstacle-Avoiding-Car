# 🚀 ESP32 AutoRover: Autonomous Obstacle Avoidance System

Welcome to the **ESP32 AutoRover** project! This is an advanced, self-driving robotic vehicle engineered using the powerful dual-core ESP32 microcontroller. 

Unlike basic RC cars, this rover possesses real-time spatial awareness. It utilizes **Ultrasonic Echolocation (HC-SR04)** to continuously scan its environment, calculate object proximity in real-time, and dynamically alter its trajectory to avoid collisions. The drivetrain is powered by an L298N Motor Driver, fully programmed in C++ with optimized PWM (Pulse Width Modulation) signals to ensure smooth, precise, and jitter-free navigation.

**Key Highlights:**
* 🧠 **Edge Computing:** Real-time distance calculation handled directly on the ESP32.
* 🦇 **Echolocation Navigation:** HC-SR04 sensor acting as the "eyes" of the rover.
* ⚙️ **Smooth Drivetrain:** Optimized PWM logic for variable speed and precise turning.
* 🔋 **Power Efficient:** Smart delay routing prevents motor stalling and battery drain on impact.


## 📌 Pin Connections

| Component | ESP32 Pin |
| :--- | :--- |
| Motor Right (IN1) | GPIO 5 |
| Motor Right (IN2) | GPIO 26 |
| Motor Left (IN3) | GPIO 25 |
| Motor Left (IN4) | GPIO 19 |
| Motor Right Speed (ENA) | GPIO 23 |
| Motor Left Speed (ENB) | GPIO 18 |
| HC-SR04 TRIG | GPIO 13 |
| HC-SR04 ECHO | GPIO 14 |

## ⚙️ How it Works
1. The ESP32 moves the car forward using PWM for smooth speed control.
2. The Ultrasonic Sensor constantly measures the distance in front of it.
3. If an obstacle is detected within **25 cm**, the car triggers the `stopCar()` function.
4. It reverses slightly, turns Right to find a clear path, and continues its journey.

## 💻 How to Install
1. Open the `ESP32_AutoRover.ino` file in **Arduino IDE**.
2. Select your ESP32 board and COM port from the Tools menu.
3. Hit Upload!

---
*Created as a fun robotics project! Feel free to star ⭐ the repository if you like it.*
