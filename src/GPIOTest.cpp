#include "world_interface/world_interface.h"

#include <iostream>
#include <string>

int prompt(std::string_view message) {
	std::string str;
	int val;
	bool valid_input = false;
	do {
		std::cout << message << " > ";
		std::getline(std::cin, str);
		try {
			val = std::stoi(str, nullptr, 0);
			valid_input = true;
		} catch (const std::invalid_argument&) {
			std::cerr << "Input must be a number (any base), try again" << std::endl;
		} catch (const std::out_of_range&) {
			std::cerr << "Input too big for int type" << std::endl;
		}
	} while (!valid_input);
	return val;
}

int main() {
	robot::world_interface_init(true);

	int pin = prompt("Enter module pin number");
	bool output = prompt("Enter 1 to set pin as ouptut, 0 to set pin as input");

	robot::initGPIOPin(pin, output);

	if (output) {
		while (true) {
			bool high = 0 != prompt("Enter 1 to set pin high, 0 to set pin low");
			robot::writeGPIOPin(pin, high);
		}
	} else {
		int sleepMillis = prompt("Enter loop period in milliseconds");
		while (true) {
			bool high = robot::readGPIOPin(pin);
			std::cout << "\33[2K\rPin " << pin << " is " << (high ? "high" : "low")
					  << std::endl;
			std::this_thread::sleep_for(std::chrono::milliseconds(sleepMillis));
		}
	}
}
