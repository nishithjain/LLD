#pragma once
#include <memory>

#include "BankAPI.h"

class PhonePe
{
	std::unique_ptr<BankAPI> bank_api_;
public:
	explicit PhonePe(std::unique_ptr<BankAPI> api);
	double GetBalance(const std::string& account_number);
	bool TransferMoney(const std::string& from, double amount, const std::string& to);
	bool CreateAccount(const std::string& account_number);
};

