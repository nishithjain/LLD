#pragma once
#include "ElectricMeter.h"
#include "ParkingSpot.h"
class ElectricVehicleParkingSpot :public ParkingSpot
{
	ElectricMeter electric_meter_;
};

