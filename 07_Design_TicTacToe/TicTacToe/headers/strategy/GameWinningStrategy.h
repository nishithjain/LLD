#pragma once
#include "GameBoard.h"
#include "Move.h"

class GameWinningStrategy
{
public:
	virtual ~GameWinningStrategy() = default;
	virtual bool CheckWinner(GameBoard board, Move move) = 0;
};

