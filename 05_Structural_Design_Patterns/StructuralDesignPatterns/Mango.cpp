#include "Mango.h"

Mango::Mango(std::unique_ptr<IIceCream> ice_cream) :
	ice_cream_(std::move(ice_cream))
{
}

double Mango::GetCost()
{
	return ice_cream_->GetCost() + 25.0;
}

std::string Mango::GetDescription()
{
	return ice_cream_->GetDescription() + "," + std::string("Mango");
}
