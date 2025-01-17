#pragma once
#include <memory>

#include "GameBoard.h"
#include "Move.h"

class BotPlayingStrategy
{
public:
	virtual ~BotPlayingStrategy() = default;
	virtual std::shared_ptr<Move>  MakeMove(const Player& player, GameBoard& board) = 0;
};

