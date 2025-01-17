#include "SMSUser.h"

#include <iostream>

SMSUser::SMSUser(std::string name) :user_name_(std::move(name))
{
}

void SMSUser::Notify(const std::string& product_name)
{
	std::cout << "SMS: " << product_name << " is back in stock!\n";
}

std::string SMSUser::GetName()
{
	return user_name_;
}
