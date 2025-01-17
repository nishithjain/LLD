#pragma once
#include "BotPlayingStrategy.h"
class BotMediumMove final : public BotPlayingStrategy
{
	Player empty_player_;
public:
	BotMediumMove() = default;
	~BotMediumMove() override = default;
	static Player GetOpponentPlayer(GameBoard& board);
	std::shared_ptr<Move> MakeMove(const Player& player, GameBoard& board) override;
	bool CheckWinningMove(const Player& player, GameBoard& board, size_t& row, size_t& col) const;
	static std::shared_ptr<Move> AssignBotToCell(Cell& bot_cell, const Player& player);
};

