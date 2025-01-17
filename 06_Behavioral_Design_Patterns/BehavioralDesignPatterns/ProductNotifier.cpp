#include "ProductNotifier.h"

#include <iostream>

ProductNotifier::ProductNotifier(std::string product_name)
	: product_name_(std::move(product_name)), in_stock_(false)
{
}

void ProductNotifier::Subscribe(const std::shared_ptr<IUser>& user)
{
	const auto userName = user->GetName();
	users_.push_back(user);
	std::cout << "User " << userName << " is subscribed for notification on: "
		<< product_name_ << "\n";
}

void ProductNotifier::NotifyUsers() const
{
	for (const auto& user : users_)
	{
		user->Notify(product_name_);
	}
}

void ProductNotifier::Unsubscribe(const std::shared_ptr<IUser>& user)
{
	const auto userName = user->GetName();
	users_.erase(remove(users_.begin(), users_.end(), user),
		users_.end());
	std::cout << "User " << userName << " is unsubscribed from notifications on: "
		<< product_name_ << "\n";
}

void ProductNotifier::SetInStock(const bool is_in_stock)
{
	in_stock_ = is_in_stock;

	if (in_stock_)
	{
		std::cout << product_name_ << " is now in stock!\n";
		NotifyUsers();
	}
}
