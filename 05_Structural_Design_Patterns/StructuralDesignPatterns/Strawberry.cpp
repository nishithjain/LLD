#include "Strawberry.h"

Strawberry::Strawberry(std::unique_ptr<IIceCream> ice_cream)
	:ice_cream_(std::move(ice_cream))
{
}

double Strawberry::GetCost()
{
	return ice_cream_->GetCost() + 22.0;
}

std::string Strawberry::GetDescription()
{
	return ice_cream_->GetDescription() + "," + std::string("Strawberry");
}

