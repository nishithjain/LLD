#pragma once
#include "Bird.h"
class Sparrow : public Bird
{
public:
	~Sparrow() override = default;
	void MakeSound() override;
};

