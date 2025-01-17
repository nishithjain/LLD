#include "Hen.h"
#include <iostream>

Hen::Hen(string name, string type, string color, float weight)
	: Bird(name, type, color, weight) {
}

void Hen::fly() {
	std::cout << getName() << " is Flying low.\n";
}

void Hen::eat() {
	std::cout << getName() << " is Eating insects.\n";
}
