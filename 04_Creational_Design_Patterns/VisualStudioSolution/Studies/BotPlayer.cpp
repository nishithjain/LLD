#include "BotPlayer.h"

#include <iostream>

BotPlayer::BotPlayer(const std::string& name, const int difficulty)
	: difficulty_level_(difficulty)
{
	this->name_ = name;
}

BotPlayer::~BotPlayer() = default;

std::unique_ptr<Player> BotPlayer::clone() const
{
	return std::make_unique<BotPlayer>(*this);
}

BotPlayer::BotPlayer(const BotPlayer& other) : Player(other),
	difficulty_level_(other.difficulty_level_)
{
	this->name_ = "Cloned Bot";
	std::cout << "Deep copy is made!!!\n";
}

void BotPlayer::DisplayStatus() const
{
	Player::DisplayStatus();
	std::cout << "Difficulty Level: " << difficulty_level_ << std::endl;
}
