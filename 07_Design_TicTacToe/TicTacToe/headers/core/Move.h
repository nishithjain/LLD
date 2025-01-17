#pragma once
#include "Cell.h"

class Move
{
	Cell cell_;
	Player player_; // Let's see, if this is required or not.

public:
	Move(const Cell& cell, const Player& player);
	Cell GetCell() const;
	void SetCell(const Cell& cell);
	Player GetPlayer() const;
	void SetPlayer(const Player& player);
};

