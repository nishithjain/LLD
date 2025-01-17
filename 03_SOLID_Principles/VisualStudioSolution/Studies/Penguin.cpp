#include "Penguin.h"
#include <iostream>
using namespace std;

Penguin::Penguin(string name, string type, string color, float weight)
	: Bird(name, type, color, weight) {}

void Penguin::eat() {
	cout << getName() << " is eating fish.\n";
}