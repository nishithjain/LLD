#pragma once
#include "IIceCream.h"
class ChocolateCone final : public IIceCream
{
public:
	double GetCost() override;
	std::string GetDescription() override;
};

