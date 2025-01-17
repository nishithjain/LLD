#pragma once
#include <string>

class ICICIBankClient
{
public:
	double CheckBalance(const std::string& account_number);
	bool SendMoney(const std::string& from, double amount,
		const std::string& to);
	bool RegisterAccount(const std::string& account_number);
};

