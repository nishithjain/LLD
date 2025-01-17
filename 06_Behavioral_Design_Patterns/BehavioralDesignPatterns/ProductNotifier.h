#pragma once
#include <memory>
#include <vector>

#include "IUser.h"

class ProductNotifier
{
	std::vector<std::shared_ptr<IUser>> users_;
	std::string product_name_;
	bool in_stock_;
public:
	explicit ProductNotifier(std::string product_name);
	void Subscribe(const std::shared_ptr<IUser>& user);
	void NotifyUsers() const;
	void Unsubscribe(const std::shared_ptr<IUser>& user);
	void SetInStock(bool is_in_stock);
};

