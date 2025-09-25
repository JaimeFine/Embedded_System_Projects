/*
This is the code for the Raspberry pi project,
servo & camera...
*/

#include <iostream>
#include <string>
#include <thread>
#include <pigpio.h>	// Included on the Raspberry pi.

const int SERVO_UP_DOWN = 22;
const int SERVO_LEFT_RIGHT = 17;
const int MAX_SERVO_MOVEMENTS = 2500;
const int MIN_SERVO_MOVEMENTS = 500;

class BasicSetups {
public:
	void setup() {
		if (gpioInitialise() < 0) {
			std::cerr << "pigpio init failed" << std::endl;
			exit(1);
		}
		gpioSetMode(SERVO_UP_DOWN, PI_OUTPUT);
		gpioSetMode(SERVO_LEFT_RIGHT, PI_OUTPUT);
		moveServo(SERVO_UP_DOWN, 1300);
	}

	void moveServo(int pin, int pulse) {
		if (pulse < MIN_SERVO_MOVEMENTS) {
			pulse = MIN_SERVO_MOVEMENTS;
		} else if (pulse > MAX_SERVO_MOVEMENTS) {
			pulse = MAX_SERVO_MOVEMENTS;
		}
		gpioServo(pin, pulse);
		time_sleep(0.01);
	}

	void NodUp200() {
		for (int pos = 1500; pos <= 1700; pos += 200) {
			moveServo(SERVO_UP_DOWN, pos);
			time_sleep(0.1);
		}
	}

	void NodDown400() {
		for (int pos = 1700; pos >= 1300; pos -= 400) {
			moveServo(SERVO_UP_DOWN, pos);
			time_sleep(0.1);
		}
	}

	void NodUp400() {
		for (int pos = 1300; pos <= 1700; pos += 400) {
			moveServo(SERVO_UP_DOWN, pos);
			time_sleep(0.1);
		}
	}

	void NodDown200() {
		for (int pos = 1700; pos >= 1500; pos-= 200) {
			moveServo(SERVO_UP_DOWN, pos);
			time_sleep(0.1);
		}
	}

	void ShakeLeft200() {
		for (int pos = 1500; pos <= 1700; pos += 200) {
			moveServo(SERVO_LEFT_RIGHT, pos);
			time_sleep(0.1);
		}
	}

	void ShakeRight400() {
		for (int pos = 1700; pos >= 1300; pos -= 400) {
			moveServo(SERVO_LEFT_RIGHT, pos);
			time_sleep(0.1);
		}
	}

	void ShakeLeft400() {
		for (int pos = 1300; pos <= 1700; pos += 400) {
			moveServo(SERVO_LEFT_RIGHT, pos);
			time_sleep(0.1);
		}
	}

	void ShakeRight200() {
		for (int pos = 1700; pos >= 1500; pos-= 200) {
			moveServo(SERVO_LEFT_RIGHT, pos);
			time_sleep(0.1);
		}
	}
};

void Nodding(bool Words) {
	BasicSetups basicmov;
	if (Words) {
		std::cout << "Agreed!" << std::endl;
	}
	basicmov.NodUp200();
	for (int i = 0; i < 2; i++) {
		basicmov.NodDown400();
		basicmov.NodUp400();
	}
	basicmov.NodDown200();
	time_sleep(0.3);
	basicmov.moveServo(SERVO_UP_DOWN, 1300);
}

void Shaking(bool Words) {
	BasicSetups basicmov;
	if (Words) {
		std::cout << "No!" << std::endl;
	}
	basicmov.ShakeLeft200();
	for (int i = 0; i < 2; i++) {
		basicmov.ShakeRight400();
		basicmov.ShakeLeft400();
	}
	basicmov.ShakeRight200();
	basicmov.moveServo(SERVO_UP_DOWN, 1300);
}

void Teasing() {
	BasicSetups basicmov;
	std::cout << "Teasing!" << std::endl;
	std::thread thread1([](){Nodding(false);});
	std::thread thread2([](){Shaking(false);});

	thread1.join();
	thread2.join();
	time_sleep(0.5);
	basicmov.moveServo(SERVO_UP_DOWN, 1300);
}

enum Commands {
	Nod,
	Shake,
	Tease,
	Exit,
	Invalid
};

Commands DataTransfer(const std::string &data) {
	if(data == "Nod")
		return Nod;
	if(data == "Shake")
		return Shake;
	if(data == "Tease")
		return Tease;
	if(data == "Exit")
		return Exit;
	else
		return Invalid;
}

void handleCommands(std::string command) {	
	Commands Command = DataTransfer(command);
	switch(Command) {
		case Nod:
			std::cout << "Nodding..." << std::endl;
			Nodding(1);
			break;
		case Shake:
			std::cout << "Shaking..." << std::endl;
			Shaking(1);
			break;
		case Tease:
			std::cout << "Teasing..." << std::endl;
			Teasing();
			break;
		case Exit:
			std::cout << "Exited..." << std::endl;
			break;
		default:
			std::cout << "Input invalid, " << command << " is not a standard input, try Nod, Shake, Tease instead" << std::endl;
			break;
	}
}

int main() {
	BasicSetups basicset;
	basicset.setup();
	std::cout << "Hello, I am SP4, what's up!" << std::endl;
	std::cout << "Try input Nod, Shake and Tease! For leaving, enter Exit!" << std::endl;
	std::string command;
	command = {0};
	while (command != "Exit") {
		std::cin >> command;
		handleCommands(command);
	}
	gpioServo(SERVO_UP_DOWN, 1500);
	gpioServo(SERVO_LEFT_RIGHT, 1500);
	gpioTerminate();
	return 0;
}
