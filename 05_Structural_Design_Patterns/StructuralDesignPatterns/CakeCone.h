#pragma once
#include "IIceCream.h"

class CakeCone final : public IIceCream
{
public:
	double GetCost() override;
	std::string GetDescription() override;
};

