#include "Player.h"

std::string Player::GetName() const
{
	return name_;
}

void Player::SetName(const std::string& name)
{
	name_ = name;
}

char Player::GetSymbol() const
{
	return symbol_;
}

void Player::SetSymbol(const char symbol)
{
	symbol_ = symbol;
}

PlayerType Player::GetPlayerType() const
{
	return player_type_;
}

void Player::SetPlayerType(const PlayerType player_type)
{
	player_type_ = player_type;
}

bool Player::IsInitialized() const
{
	return !name_.empty() && symbol_ != '\0';
}

Player::Player(std::string name, const char symbol, const PlayerType player_type) :
	name_(std::move(name)), symbol_(symbol),
	player_type_(player_type)
{
}

Player::Player()
	: name_("Unknown"), symbol_(' ')
{

}
