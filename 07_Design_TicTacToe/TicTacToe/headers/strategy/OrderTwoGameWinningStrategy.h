#pragma once
#include "GameWinningStrategy.h"
class OrderTwoGameWinningStrategy final : public GameWinningStrategy
{
public:
	OrderTwoGameWinningStrategy() = default;
	~OrderTwoGameWinningStrategy() override = default;
	bool CheckWinner(GameBoard board, Move move) override;
};

