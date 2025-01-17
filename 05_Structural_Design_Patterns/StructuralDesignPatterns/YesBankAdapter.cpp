#include "YesBankAdapter.h"

YesBankAdapter::YesBankAdapter(std::unique_ptr<YesBankClient> client)
	: yes_bank_client_(std::move(client)) {
}

double YesBankAdapter::CheckBalance(const std::string& account_number) {
	return yes_bank_client_->CheckBalance(account_number);
}

bool YesBankAdapter::SendMoney(const std::string& from, const double amount,
	const std::string& to) {
	return yes_bank_client_->SendMoney(from, amount, to);
}

bool YesBankAdapter::RegisterAccount(const std::string& account_number) {
	return yes_bank_client_->RegisterAccount(account_number);
}
