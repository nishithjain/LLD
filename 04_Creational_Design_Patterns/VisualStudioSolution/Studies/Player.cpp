#include "Player.h"
#include <iostream>

void Player::DisplayStatus() const
{
	std::cout << "Name: " << name_ << ", Health: " << health_ << ", Team: " << team_id_
		<< ", Position: (" << pos_x_ << ", " << pos_y_ << ", " << pos_z_ << ")"
		<< ", Weapon: " << weapon_ << ", Damage: " << damage_output_  << std::endl;
}
