#pragma once
#include <string>

#include "Gate.h"
#include "GateOperator.h"
#include "ParkingSpot.h"
#include "Vehicle.h"

class Ticket
{
	int id_;
	std::string entry_time_;
	std::string exit_time_;
	GateOperator gate_operator_;
	ParkingSpot parking_spot_;
	Vehicle vehicle_;
	Gate gate_;

};

