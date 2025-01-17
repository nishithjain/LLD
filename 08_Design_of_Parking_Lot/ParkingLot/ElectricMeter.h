#pragma once
#include <string>

class ElectricMeter
{
	int id_ = -1;
	int meter_number_ = -1;
	std::string start_time_;
	std::string end_time_;
	double base_unit_price_ = 0.0;
};

