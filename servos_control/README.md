# Raspberry Pi Controlled Servos Project

This project controls two servo motors connected to a Raspberry Pi using the `pigpio` library. It simulates expressive head movements like nodding, shaking, and teasing—perfect for robotics, interactive installations, or embedded AI companions.

---

## 🛠️ Features

- Dual servo control (up/down and left/right)
- Predefined gestures: Nod, Shake, Tease
- Command-line interface for interaction
- Threaded teasing animation (simultaneous nod and shake)
- Safety bounds for servo pulse widths

---

## 🧰 Hardware Requirements

- Raspberry Pi (any model with GPIO support)
- 2x Servo motors
- External power supply for servos (recommended)
- Jumper wires and breadboard (optional)
- Camera module (optional, not yet integrated)

---

## 📦 Dependencies

- C++17 or later
- [pigpio library](http://abyz.me.uk/rpi/pigpio/) (must be installed and daemon running)

Install pigpio:

```bash
sudo apt update
sudo apt install pigpio
sudo systemctl start pigpiod
```

---

## 🚀 Build & Run

Compile the code:

```bash
g++ -std=c++17 -lpigpio -lpthread -o sp4 main.cpp
```

Run the program:

```bash
./sp4
```

---

## 🎮 Usage

Once launched, SP4 greets you and awaits commands:

```text
Hello, I am SP4, what's up!
Try input Nod, Shake and Tease! For leaving, enter Exit!
```

Available commands:

| Command | Description                     |
|---------|---------------------------------|
| Nod     | Performs a nodding gesture      |
| Shake   | Performs a head-shaking gesture |
| Tease   | Simultaneous nod and shake      |
| Exit    | Terminates the program          |

Example:

```bash
> Nod
Agreed!
Nodding...
```

---

## 🧠 Code Overview

### `BasicSetups` class

- Initializes GPIO and sets servo modes
- Provides movement functions with pulse bounds
- Defines gesture sequences (NodUp200, ShakeRight400, etc.)

### Gesture Functions

- `Nodding(bool Words)` – Simulates agreement
- `Shaking(bool Words)` – Simulates disagreement
- `Teasing()` – Runs nod and shake in parallel threads

### Command Handling

- `handleCommands()` parses user input and triggers gestures
- Invalid inputs are gracefully handled

---

## 🧪 Safety Notes

- Servo pulse widths are clamped between 500 and 2500 µs
- Always reset servos to neutral (1500 µs) before shutdown
- Ensure servos are powered appropriately to avoid GPIO damage

---

## 📸 Future Enhancements

- Integrate camera module for vision-based interaction
- Add voice recognition or speech synthesis
- Expand gesture vocabulary
- Web interface or mobile control

---

## 📄 License

This project is open-source under the MIT License.  
Feel free to modify, distribute, and build upon it.

---

Let me know if you'd like help integrating the camera module or expanding the gesture set!
