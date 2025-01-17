#pragma once
#include "IUser.h"
class EmailUser final : public IUser
{
	std::string user_name_;
public:
	explicit EmailUser(std::string name);
	~EmailUser() override = default;
	void Notify(const std::string& product_name) override;
	std::string GetName() override;
};

