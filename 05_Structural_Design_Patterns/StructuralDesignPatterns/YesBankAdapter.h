#pragma once
#include <memory>

#include "BankAPI.h"
#include "YesBankClient.h"

class YesBankAdapter final : public BankAPI
{
	std::unique_ptr<YesBankClient> yes_bank_client_;
public:
	explicit YesBankAdapter(std::unique_ptr<YesBankClient> client);
	double CheckBalance(const std::string& account_number) override;
	bool SendMoney(const std::string& from, double amount,
		const std::string& to) override;
	bool RegisterAccount(const std::string& account_number) override;
};

