#include "ChocoChips.h"

ChocoChips::ChocoChips(std::unique_ptr<IIceCream> ice_cream):
ice_cream_(std::move(ice_cream))
{
}

double ChocoChips::GetCost()
{
	return ice_cream_->GetCost() + 7.0;
}

std::string ChocoChips::GetDescription()
{
	return ice_cream_->GetDescription() + "," + std::string("Choco Chips");
}
