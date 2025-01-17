#pragma once
#include <memory>

#include "IIceCream.h"
class Vanilla final : public IIceCream
{
	std::unique_ptr<IIceCream> ice_cream_;
public:
	explicit Vanilla(std::unique_ptr<IIceCream> ice_cream);
	double GetCost() override;
	std::string GetDescription() override;
};

