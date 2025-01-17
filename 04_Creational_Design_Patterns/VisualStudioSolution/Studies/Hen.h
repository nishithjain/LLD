#pragma once
#include "Bird.h"
class Hen final : public Bird
{
public:
	~Hen() override = default;
	void MakeSound() override;
};

