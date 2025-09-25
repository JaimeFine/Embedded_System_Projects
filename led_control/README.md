Arduino Serial LED Controller
This project provides a simple way to control the behavior of an LED using the Arduino Serial Monitor. By sending simple commands from your computer, you can turn the LED on or off, make it "breathe" (fade in and out), or make it flash.

Features
Serial Communication: Control is handled entirely through a serial connection.

On/Off Control: Easily turn the LED fully on or off.

Breathing Effect: Creates a smooth, pulsating fade-in and fade-out animation.

Flashing Effect: A simple, quick blinking effect.

Hardware Requirements
An Arduino board (e.g., Uno, Nano, etc.)

An LED

A 220-ohm resistor

A breadboard and jumper wires (optional but recommended)

A USB cable to connect the Arduino to your computer

Wiring
Connect your components to the Arduino as shown in the diagram below:

Connect the long leg (anode) of the LED to Pin 2 on your Arduino.

Connect the short leg (cathode) of the LED to one end of the 220-ohm resistor.

Connect the other end of the resistor to a GND (ground) pin on the Arduino.

Usage
Upload the provided Arduino sketch to your board using the Arduino IDE.

Open the Serial Monitor in the Arduino IDE and ensure the baud rate is set to 9600.

Type one of the following commands in the input field and press Enter to control the LED:

Command

Description

on

Turns the LED on at full brightness.

off

Turns the LED off.

breath

Starts the breathing (fading) effect.

flash

Starts the flashing (blinking) effect.

Code Notes
The code uses the ledc peripheral for Pulse Width Modulation (PWM) to control the LED's brightness, which is essential for the breathing effect. While the code includes a flash() function, the actual flashing logic is handled directly in the loop() function, a more non-blocking and effective approach.

Credits
This project was inspired by standard Arduino tutorials and serves as a great starting point for beginners learning about serial communication and PWM.
