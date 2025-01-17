#include "Chocolate.h"

Chocolate::Chocolate(std::unique_ptr<IIceCream> ice_cream) :
	ice_cream_(std::move(ice_cream))
{
}

double Chocolate::GetCost()
{
	return ice_cream_->GetCost() + 30.0;
}

std::string Chocolate::GetDescription()
{
	return ice_cream_->GetDescription() + "," + std::string("Chocolate");
}
