# 🚗 CAN-Based Reverse Parking Assistance System

> A dual-node embedded system using **ARM7 (LPC2129)** and **CAN protocol** to implement a real-time reverse parking alert mechanism with sensor-based feedback and buzzer control.

---
## 🧠 Overview

This project simulates a **reverse parking assistance system** using two independent embedded nodes communicating over CAN:

- **Node A (Controller Node)**  
  Sends request frames and controls the buzzer based on received distance data.

- **Node B (Sensor Node)**  
  Measures distance using an ultrasonic sensor and responds via CAN.

The system is designed using an **interrupt-driven approach** for efficient communication and responsiveness.

---

## 📸 Project Preview

### 🧠 System Architecture
<img width="1710" height="747" alt="Screenshot 2026-05-02 032608" src="https://github.com/user-attachments/assets/5b53f2a3-8005-43b7-ae4d-64d7b9497156" />

### 🔧 Hardware Setup
<img width="848" height="480" alt="IMG_20260502_19234362" src="https://github.com/user-attachments/assets/0c7cc642-ab0d-4950-abad-8d1c8a23bf3b" />



---



---

## ⚙️ Key Features

-  CAN-based multi-node communication  
-  Interrupt-driven CAN reception (Node B)  
-  Real-time distance measurement using ultrasonic sensor  
-  Distance-based buzzer control  
-  Sensor fault detection using invalid readings (`999`)  
-  Modular embedded drivers (CAN, UART, Timer)

---

## 📡 CAN Communication
<img width="1732" height="789" alt="image" src="https://github.com/user-attachments/assets/3a751c12-d01a-4e2d-8207-aef3f4370ead" />

---
### 🔔 Buzzer Behavior

| Condition | Buzzer Behavior |
|----------|----------------|
| Distance < 50 cm | Continuous ON |
| 50 cm < Distance < 200 cm | Fast Beep |
| 200 cm < Distance < 400 cm | Slow Beep |
| Distance > 400 cm | OFF |
| Sensor Failure (`999`) | OFF |

---

### 🛠️ Tech Stack
- Microcontroller: LPC2129 (ARM7)
- Language: Embedded C
- Protocols: CAN, UART
- Peripherals: Timer, GPIO
- Sensor: Ultrasonic (HC-SR04)

---

### 🧠 What I Learned
- Practical implementation of CAN protocol (RTR, DLC, filtering)
- Difference between polling and interrupt-driven design
- Handling real-world sensor failures
- Designing modular embedded drivers
- Building a multi-node embedded system

---

### 🤝 Let’s Connect

If you’re working on embedded systems or interested in CAN-based applications, Feel free to raise issues or fork this project!

### ⭐ If you found this interesting, consider giving it a star!


