#pragma once
#include "Player.h"
class BotPlayer : public Player
{
	int difficulty_level_ = 0;
public:
	BotPlayer(const std::string& name, const int difficulty);
	~BotPlayer() override;
	std::unique_ptr<Player> clone() const override;
	BotPlayer(const BotPlayer& other);
	void DisplayStatus() const override;
};

