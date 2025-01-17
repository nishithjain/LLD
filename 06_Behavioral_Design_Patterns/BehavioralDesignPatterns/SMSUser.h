#pragma once
#include "IUser.h"
class SMSUser final : public IUser
{
	std::string user_name_;
public:
	explicit SMSUser(std::string name);
	~SMSUser() override = default;
	void Notify(const std::string& product_name) override;
	std::string GetName();
};

