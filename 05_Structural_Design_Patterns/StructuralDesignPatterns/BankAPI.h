#pragma once
#include <string>

class BankAPI {
public:
	virtual ~BankAPI() = default;
	virtual double CheckBalance(const std::string& account_number) = 0;
    virtual bool SendMoney(const std::string& from, double amount, 
		const std::string& to) = 0;
    virtual bool RegisterAccount(const std::string& account_number) = 0;
};