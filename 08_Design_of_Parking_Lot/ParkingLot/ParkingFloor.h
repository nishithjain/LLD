#pragma once
#include <vector>

#include "ParkingSpot.h"

class ParkingFloor
{
	int floor_id_ = -1;
	int floor_number_ = -1;
	std::vector<ParkingSpot> parking_spots_;
};

