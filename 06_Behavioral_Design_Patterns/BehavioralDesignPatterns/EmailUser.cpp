#include "EmailUser.h"

#include <iostream>

EmailUser::EmailUser(std::string name): user_name_(std::move(name))
{
}

void EmailUser::Notify(const std::string& product_name)
{
	std::cout << "Email: " << product_name << " is back in stock!\n";
}

std::string EmailUser::GetName()
{
	return user_name_;
}
