#pragma once
#include "Bird.h"
#include "IFlyable.h"

class Parrot : public Bird, public IFlyable {
public:
	Parrot(string name, string type, string color, float weight);
	void fly() override;
	void eat() override;
};