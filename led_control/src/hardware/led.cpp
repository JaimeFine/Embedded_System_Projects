/*
#include "led.h"
#include <Arduino.h>
#include "global/GData.h"

void setup() {
  Serial.begin(9600);
  pinMode(LED_Pin, OUTPUT);
}

void control() {
  if (Serial.available()) {
    String command = Serial.readStringUntil('\n');
    command.trim();

    if (command == "on") {
      digitalWrite(LED_Pin, HIGH);
      Serial.println("LED is ON");
    } else if (command == "off") {
      digitalWrite(LED_Pin, LOW);
      Serial.println("LED is OFF");
    } else {
      Serial.println("Unknown command. Try 'on' or 'off'.");
    }
  }
}

/*
void breath() {
  static int brightness = 0;
  static int fadeAmount = 5;

  ledcWrite(0, brightness);  // Set PWM duty cycle

  brightness += fadeAmount;
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;  // Reverse direction
  }

  delay(15);  // Controls breathing speed
}
*/
