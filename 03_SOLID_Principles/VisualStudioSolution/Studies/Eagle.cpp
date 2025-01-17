#include "Eagle.h"
#include <iostream>

Eagle::Eagle(string name, string type, string color, float weight)
	: Bird(name, type, color, weight) {
}

void Eagle::fly() {
	std::cout << getName() << " is Flying high.\n";
}

void Eagle::eat() {
	std::cout << getName() << " is Eating fish.\n";
}
