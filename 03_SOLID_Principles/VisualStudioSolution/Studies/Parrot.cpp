#include "Parrot.h"
#include <iostream>
using namespace std;

Parrot::Parrot(string name, string type, string color, float weight)
	: Bird(name, type, color, weight) {}

void Parrot::fly() {
	cout << getName() << " is flying with colorful wings.\n";
}

void Parrot::eat() {
	cout << getName() << " is eating fruits and seeds.\n";
}
