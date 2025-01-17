#pragma once
#include <string>

class IUser
{
public:
	virtual ~IUser() = default;
	virtual void Notify(const std::string& product_name) = 0;
	virtual std::string GetName() = 0;
};
