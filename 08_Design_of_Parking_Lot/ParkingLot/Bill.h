#pragma once
#include <vector>

#include "BillStatus.h"
#include "Payments.h"
#include "Ticket.h"

class Bill
{
	int id_ = -1;
	Ticket ticket_; 
	double amount_ = 0.0;
	std::string exit_time_;
	Gate gate_;
	std::vector<Payments> payments_;
	BillStatus bill_status_;
};

