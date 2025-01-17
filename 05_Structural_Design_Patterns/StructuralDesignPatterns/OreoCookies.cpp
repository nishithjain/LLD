#include "OreoCookies.h"

OreoCookies::OreoCookies(std::unique_ptr<IIceCream> ice_cream)
	:ice_cream_(std::move(ice_cream))
{
}

double OreoCookies::GetCost()
{
	return ice_cream_->GetCost() + 12.0;
}

std::string OreoCookies::GetDescription()
{
	return ice_cream_->GetDescription() + "," + std::string("Oreo Cookies");
}
