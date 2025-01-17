#pragma once
#include "Bird.h"
class Peacock final : public Bird
{
public:
	~Peacock() override = default;
	void MakeSound() override;
};

