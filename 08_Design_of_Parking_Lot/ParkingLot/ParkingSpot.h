#pragma once
#include "ParkingSpotStatus.h"
#include "VehicleType.h"

class ParkingSpot
{
	int parking_spot_id_ = -1;
	int parking_number_ = -1;
	VehicleType vechicle_type_;
	ParkingSpotStatus status_;
};

