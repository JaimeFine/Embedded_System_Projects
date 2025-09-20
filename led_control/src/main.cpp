#include <Arduino.h>

#define LED_Pin 2

bool breathing = false;
bool flashing = false;

void setup() {
  Serial.begin(9600);
  pinMode(LED_Pin, OUTPUT);

  ledcAttachPin(LED_Pin, 0);
  ledcSetup(0, 5000, 8);
  ledcWrite(0, 0);

  Serial.println("Type 'on' to start breathing, 'off' to stop.");
}

void breath() {
  static int brightness = 0;
  static int fadeAmount = 5;

  ledcWrite(0, brightness);

  brightness += fadeAmount;
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }

  delay(25);
}

void flash() {
  while (true) {
    ledcWrite(0, 0);
    delay(5);
    ledcWrite(0, 255);
  }
}

void control() {
  if (Serial.available()) {
    String command = Serial.readStringUntil('\n');
    command.trim();

    if (command == "on") {
      breathing = false;
      flashing = false;
      ledcWrite(0, 255);
      Serial.println("LED is ON");
    } else if (command == "off") {
      breathing = false;
      flashing = false;
      ledcWrite(0, 0);
      Serial.println("LED is OFF");
    } else if (command == "flash") {
      breathing = false;
      flashing = true;
      Serial.println("LED is flashing");
    } else if (command == "breath") {
      breathing = true;
      flashing = false;
      Serial.println("LED is breathing");
    } else {
      Serial.println("Unknown command. Try 'on' or 'off'.");
    }
  }
}

void loop() {
  control();
  if (breathing) {
    breath();
  } else if (flashing) {
    static bool state = false;
    ledcWrite(0, state ? 255 : 0);
    state = !state;
    delay(100);
  }
}

