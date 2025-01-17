#pragma once
#include "IIceCream.h"
class SugarCone final : public IIceCream
{
public:
	double GetCost() override;
	std::string GetDescription() override;
};

