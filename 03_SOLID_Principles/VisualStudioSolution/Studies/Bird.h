#pragma once
#include <string>
using namespace std;

class Bird {
	string name;
	string type;
	string color;
	float weight;

public:
	Bird(string name, string type, 
		string color, float weight);

	string getName() const { return name; }
	string getType() const { return type; }
	string getColor() const { return color; }
	float getWeight() const { return weight; }

	virtual void eat() = 0;
};
