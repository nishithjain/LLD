#pragma once
#include "BotDifficultyLevel.h"
#include "BotPlayingStrategy.h"
#include "Player.h"

class Bot final : public Player
{
	BotDifficultyLevel bot_difficulty_level_ = BotDifficultyLevel::EASY;
	std::shared_ptr<BotPlayingStrategy> bot_playing_strategy_ = nullptr;

public:

	std::shared_ptr<BotPlayingStrategy> GetBotPlayingStrategy() const;
	void SetBotPlayingStrategy(const std::shared_ptr<BotPlayingStrategy>& bot_playing_strategy);

	Bot(const std::string& name, char symbol,
	    BotDifficultyLevel bot_difficulty_level);

	BotDifficultyLevel GetBotDifficultyLevel() const;
	void SetBotDifficultyLevel(BotDifficultyLevel bot_difficulty_level);

	std::shared_ptr<Move> MakeMove(const Player& player, GameBoard& board) const;
	~Bot() override = default;
};

