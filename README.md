🚗 Drunk and Drive Detection System

A smart embedded system designed to detect alcohol consumption in drivers using an MQ2 sensor and automatically control vehicle entry using a servo motor and buzzer alert system.

---

📌 Project Overview

The Drunk and Drive Detection System is an Arduino-based safety project developed to prevent drunk driving accidents. The MQ2 alcohol sensor detects alcohol from the driver's breath and checks whether the alcohol level exceeds the predefined limit. If alcohol is detected, the system activates the buzzer and blocks the gate using a servo motor. Otherwise, the gate opens and allows entry.

---

✨ Features

- Alcohol detection using MQ2 sensor
- Automatic gate control using servo motor
- Buzzer alert for alcohol detection
- LCD display for status monitoring
- IR sensor for vehicle detection
- Real-time safety monitoring system

---

🛠 Components Used

- Arduino Uno
- MQ2 Alcohol Sensor
- IR Sensor
- Servo Motor
- LCD Display (I2C)
- Buzzer
- Fan
- Jumper Wires
- Power Supply

---

⚙ Technologies Used

- Embedded C
- Arduino IDE
- Arduino Uno

---

🔌 Circuit Connections

- MQ2 Sensor → A0
- IR Sensor → Pin 8
- Fan → Pin 9
- Buzzer → Pin 10
- Servo Motor → Pin 11
- LCD SDA → A4
- LCD SCL → A5

---

🚀 Working Principle

The IR sensor first detects the presence of a vehicle. The fan helps direct air towards the MQ2 alcohol sensor for accurate detection. The sensor measures the alcohol level and sends data to the Arduino. If the alcohol value exceeds the threshold, the buzzer turns ON and the gate remains closed. If no alcohol is detected, the servo motor opens the gate and allows entry.
