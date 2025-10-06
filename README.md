# 🧾 Report  
## Three Wheel Omni Drive using PS4 Controller  

---

### ⚙️ Overview  
This project demonstrates **wireless control of a three-wheel omni-directional robot** using a **PS4 controller** and a **Teensy 4.1 microcontroller**.  
The Teensy communicates with the PS4 controller via **Bluetooth**, reads the joystick inputs, and translates them into wheel speeds for **smooth omnidirectional movement** — forward, backward, sideways, and rotation.

---

## 🧩 Components Used  

| Component | Specification / Model |
|------------|------------------------|
| **Microcontroller** | Teensy 4.1 |
| **Motors** | 3 × RS775 Planetary Gearbox DC Motors |
| **Motor Drivers** | 2 × Cytron MDD20A Dual Channel 20A Motor Drivers |
| **Power Source** | 6S LiPo Battery (22.2V nominal) |
| **Controller** | PS4 DualShock (connected via Bluetooth) |

---

## 🔩 Hardware Configuration  

The robot uses a **three-wheel omni-drive configuration**, with wheels spaced **120° apart**.  
This setup allows the robot to move in any direction without needing to rotate first.

| Wheel | PWM Pin | Direction Pin |
|--------|----------|----------------|
| Wheel 1 | 23 | 21 |
| Wheel 2 | 3 | 5 |
| Wheel 3 | 2 | 4 |

> Each motor driver channel controls one motor. Two Cytron MDD20A boards are used to handle the three DC motors.

---

## 📡 Control System  

- **Left joystick (LX, LY)** → controls **translational motion (Vx, Vy)**  
- **Right joystick (RX)** → controls **rotational speed (ω)**  

The kinematic model converts these joystick values into individual wheel angular velocities (`w1`, `w2`, `w3`):


