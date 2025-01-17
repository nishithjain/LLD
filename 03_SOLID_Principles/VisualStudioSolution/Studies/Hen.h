#pragma once
#include "Bird.h"
#include "IFlyable.h"

class Hen : public Bird, public IFlyable {
public:
	Hen(string name, string type,
		string color, float weight);
	void fly() override;
	void eat() override;
};
