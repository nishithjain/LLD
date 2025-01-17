#include "PhonePe.h"

PhonePe::PhonePe(std::unique_ptr<BankAPI> api)
	: bank_api_(std::move(api)) {}

double PhonePe::GetBalance(const std::string& account_number) {
	return bank_api_->CheckBalance(account_number);
}

bool PhonePe::TransferMoney(const std::string& from, const double amount,
	const std::string& to)  {
	return bank_api_->SendMoney(from, amount, to);
}

bool PhonePe::CreateAccount(const std::string& account_number) {
	return bank_api_->RegisterAccount(account_number);
}



