#pragma once
#include "PaymentMode.h"
#include "PaymentStatus.h"

class Payments
{
	int id_;
	PaymentMode payment_mode_;
	double amount_ = 0.0;
	PaymentStatus payment_status_ = PaymentStatus::SUCCESSFUL;

};

