#pragma once
#include "IIceCream.h"
class WaffleCone final: public IIceCream
{
public:
	double GetCost() override;
	std::string GetDescription() override;
};

