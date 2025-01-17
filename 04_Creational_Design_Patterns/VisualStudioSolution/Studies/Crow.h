#pragma once
#include "Bird.h"
class Crow final : public Bird
{
public:
	~Crow() override = default;
	void MakeSound() override;
};

