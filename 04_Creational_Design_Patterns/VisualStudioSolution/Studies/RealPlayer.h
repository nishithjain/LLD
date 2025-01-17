#pragma once
#include <iostream>

#include "Player.h"
class RealPlayer : public Player
{
	int experience_points_ = 0;
public:
	RealPlayer(const std::string& name, int exp_points);
	~RealPlayer() override;
	std::unique_ptr<Player> clone() const override;
	RealPlayer(const RealPlayer& other);
	void DisplayStatus() const override;
};

