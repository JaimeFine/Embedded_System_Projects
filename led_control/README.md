# Platformio & ESP32 Serial LED Controller

This project provides a simple way to control the behavior of an LED using the Arduino Serial Monitor. By sending simple commands from your computer, you can turn the LED on or off, make it "breathe" (fade in and out), or make it flash.

-----

## ✨ Features

- Serial Communication: Control is handled entirely through a serial connection.
- On/Off Control: Easily turn the LED fully on or off.
- Breathing Effect: Creates a smooth, pulsating fade-in and fade-out animation.
- Flashing Effect: A simple, quick blinking effect.

-----

## 📂 Project structure

```text
.
├── src
│   └── main.cpp
├── include
├── lib
├── test
└── platformio.ini
```

-----

## 🚀 Getting started

### Hardware Requirements

1. ESP32 with an extension board
    I am using a Seeed Studio XIAO ESP32C3

2. An LED

3. A USB cable to connect the ESP32 to your computer

4. An extension for the LED

### Usage

You can ask AI for how to make the project work on your system!

### Commands

| Command | Description |
| ------- | ----------- |
| on | Turns the LED on at full brightness. |
| off | Turns the LED off. |
| breath | Starts the breathing (fading) effect. |
| flash | Starts the flashing (blinking) effect. |

-----

## ✒️ Code Notes

The code uses the ledc peripheral for Pulse Width Modulation (PWM) to control the LED's brightness, which is essential for the breathing effect. While the code includes a flash() function, the actual flashing logic is handled directly in the loop() function, a more non-blocking and effective approach.
