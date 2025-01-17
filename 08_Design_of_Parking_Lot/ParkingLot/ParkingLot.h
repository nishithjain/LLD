#pragma once
#include <vector>
#include <string>

#include "Gate.h"
#include "ParkingFloor.h"

class ParkingLot
{
	int parking_lot_id_ = -1;
	std::vector<ParkingFloor> parking_floors_;
	std::vector<Gate> gates_;
	std::vector<GateOperator> operators_;
	std::string address_;

};

