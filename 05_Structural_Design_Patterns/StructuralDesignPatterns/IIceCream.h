#pragma once
#include <string>

class IIceCream
{
public:
	virtual ~IIceCream() = default;
	virtual double GetCost() = 0;
	virtual std::string GetDescription() = 0;
};

