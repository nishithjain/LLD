#include "Vanilla.h"

Vanilla::Vanilla(std::unique_ptr<IIceCream> ice_cream):
	ice_cream_(std::move(ice_cream))
{
}

double Vanilla::GetCost()
{
	return ice_cream_->GetCost() + 18.0;
}

std::string Vanilla::GetDescription()
{
	return ice_cream_->GetDescription() + "," + std::string("Vanilla");
}
