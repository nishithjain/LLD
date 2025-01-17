#include "ChocolateSauce.h"

ChocolateSauce::ChocolateSauce(std::unique_ptr<IIceCream> ice_cream)
	:ice_cream_(std::move(ice_cream))
{
}

double ChocolateSauce::GetCost()
{
	return ice_cream_->GetCost() + 7.0;
}

std::string ChocolateSauce::GetDescription()
{
	return ice_cream_->GetDescription() + "," + std::string("Chocolate Sauce");
}