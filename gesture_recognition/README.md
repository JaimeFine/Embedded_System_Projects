# 🤖 SP4: Raspberry Pi Servo & Camera Control

This project controls two servo motors connected to a Raspberry Pi using the `pigpio` library. It simulates expressive head movements like nodding, shaking, and teasing—ideal for embedded robotics, interactive installations, or AI companions.

---

## 📦 Requirements

- Raspberry Pi (any model with GPIO support)
- 2x Servo motors
- External power supply for servos (recommended)
- `pigpio` library installed and daemon running
- C++17 or later

---

## 🛠️ Setup Instructions

### 1. Install Dependencies

```bash
sudo apt update
sudo apt install pigpio
sudo systemctl start pigpiod
```

### 2. Build the Project

```bash
g++ -std=c++17 -lpigpio -lpthread -o sp4 main.cpp
```

### 3. Run the Program

```bash
./sp4
```

---

## 📁 Project Structure

```
.
├── main.cpp          # Core logic and command interface
├── README.md         # Project documentation
```

---

## 🧠 Code Overview

### `BasicSetups` Class

Handles GPIO initialization and servo movement:

- `setup()` — Initializes pigpio and sets servo pins
- `moveServo(pin, pulse)` — Sends pulse width to servo with bounds checking
- Gesture methods:
  - `NodUp200`, `NodDown400`, etc.
  - `ShakeLeft200`, `ShakeRight400`, etc.

### Gesture Functions

- `Nodding(bool Words)` — Simulates agreement
- `Shaking(bool Words)` — Simulates disagreement
- `Teasing()` — Runs nod and shake in parallel threads

### Command Handling

- `handleCommands(std::string)` — Parses user input and triggers gestures
- Supported commands: `Nod`, `Shake`, `Tease`, `Exit`

---

## 🎮 Usage

After launching, SP4 greets you and awaits input:

```text
Hello, I am SP4, what's up!
Try input Nod, Shake and Tease! For leaving, enter Exit!
```

Example interaction:

```bash
> Nod
Agreed!
Nodding...
```

---

## 🧪 Servo Safety

- Pulse widths are clamped between 500 and 2500 µs
- Neutral position is 1300 µs (reset after each gesture)
- Final shutdown resets both servos to 1500 µs

---

## 🧩 Future Enhancements

- Integrate PiCamera for vision-based gestures
- Add voice recognition or speech synthesis
- Expand gesture vocabulary
- Web or mobile interface

---

## 📄 License

This project is licensed under the MIT License.  
Feel free to modify, distribute, and build upon it.
