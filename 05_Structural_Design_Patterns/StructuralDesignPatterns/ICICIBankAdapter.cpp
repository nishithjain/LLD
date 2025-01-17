#include "ICICIBankAdapter.h"

ICICIBankAdapter::ICICIBankAdapter(std::unique_ptr<ICICIBankClient> client) :
	icici_bank_client_(std::move(client))
{
}

double ICICIBankAdapter::CheckBalance(const std::string& account_number)
{
	return 0.0;
}

bool ICICIBankAdapter::SendMoney(const std::string& from, double amount, const std::string& to)
{
	return true;
}

bool ICICIBankAdapter::RegisterAccount(const std::string& account_number)
{
	return true;
}

