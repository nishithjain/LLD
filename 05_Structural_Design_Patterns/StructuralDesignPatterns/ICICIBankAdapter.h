#pragma once
#include <memory>

#include "BankAPI.h"
#include "ICICIBankClient.h"

class ICICIBankAdapter : public BankAPI
{
	std::unique_ptr<ICICIBankClient> icici_bank_client_;
public:
	ICICIBankAdapter(std::unique_ptr<ICICIBankClient> client);
	double CheckBalance(const std::string& account_number) override;
	bool SendMoney(const std::string& from, double amount, const std::string& to) override;
	bool RegisterAccount(const std::string& account_number) override;
};

