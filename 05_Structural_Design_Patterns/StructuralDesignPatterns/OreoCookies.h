#pragma once
#include <memory>

#include "IIceCream.h"
class OreoCookies final : public IIceCream
{
	std::unique_ptr<IIceCream> ice_cream_;
public:
	explicit OreoCookies(std::unique_ptr<IIceCream> ice_cream);
	double GetCost() override;
	std::string GetDescription() override;
};

