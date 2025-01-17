#include "Bot.h"

std::shared_ptr<BotPlayingStrategy> Bot::GetBotPlayingStrategy() const
{
	return bot_playing_strategy_;
}

void Bot::SetBotPlayingStrategy(const std::shared_ptr<BotPlayingStrategy>& bot_playing_strategy)
{
	bot_playing_strategy_ = bot_playing_strategy;
}

Bot::Bot(const std::string& name, const char symbol,
         const BotDifficultyLevel bot_difficulty_level)
	: Player(name, symbol, PlayerType::BOT),
	bot_difficulty_level_(bot_difficulty_level)
{
	
}

BotDifficultyLevel Bot::GetBotDifficultyLevel() const
{
	return bot_difficulty_level_;
}

void Bot::SetBotDifficultyLevel(const BotDifficultyLevel bot_difficulty_level)
{
	bot_difficulty_level_ = bot_difficulty_level;
}

std::shared_ptr<Move> Bot::MakeMove(const Player& player, GameBoard& board) const
{
	return bot_playing_strategy_->MakeMove(player, board);
}
