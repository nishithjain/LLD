#include "RealPlayer.h"

RealPlayer::RealPlayer(const std::string& name, const int exp_points)
	: experience_points_(exp_points)
{
	this->name_ = name;
}

RealPlayer::~RealPlayer() = default;

std::unique_ptr<Player> RealPlayer::clone() const
{
	return std::make_unique<RealPlayer>(*this);
}

RealPlayer::RealPlayer(const RealPlayer& other) : Player(other),
	experience_points_(other.experience_points_)
{
	this->name_ = "Cloned Real Player";
	std::cout << "Deep copy is made!!!\n";
}

void RealPlayer::DisplayStatus() const
{
	Player::DisplayStatus();
	std::cout << "Experience Points: " << experience_points_ << '\n';
}
