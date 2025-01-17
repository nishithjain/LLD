#include "BotPlayingStrategyFactory.h"

#include <stdexcept>

#include "BotEasyMove.h"
#include "BotHardMove.h"
#include "BotMediumMove.h"

std::shared_ptr<BotPlayingStrategy> BotPlayingStrategyFactory::CreateBotStrategy(
	const BotDifficultyLevel difficulty)
{
	switch (difficulty)
	{
	case BotDifficultyLevel::EASY:
		return std::make_shared<BotEasyMove>();
	case BotDifficultyLevel::MEDIUM:
		return std::make_shared<BotMediumMove>();
	case BotDifficultyLevel::HARD:
		return std::make_shared<BotHardMove>();
	default:
		throw std::invalid_argument("Unknown difficulty level");
	}
}
