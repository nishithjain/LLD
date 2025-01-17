#pragma once
#include <memory>

#include "BotPlayingStrategy.h"
class BotEasyMove final : public BotPlayingStrategy
{
public:
	BotEasyMove() = default;
	~BotEasyMove() override = default;
	std::shared_ptr<Move> MakeMove(const Player& player, GameBoard& board) override;
};

