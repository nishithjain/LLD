#include "ConcreteVehicles.h"

#include <iostream>

void Car::Drive() const {
	std::cout << "Driving a Car!\n";
}

void Buggy::Drive() const {
	std::cout << "Driving a Monster Truck!\n";
}

void MonsterTruck::Drive() const {
	std::cout << "Driving a Monster Truck!\n";
}

void Dacia::Drive() const {
	std::cout << "Driving a Dacia!\n";
}

void Motorcycle::Drive() const {
	std::cout << "Riding a Motorcycle!\n";
}
