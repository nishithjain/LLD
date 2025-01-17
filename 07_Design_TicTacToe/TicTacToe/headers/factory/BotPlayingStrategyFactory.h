#pragma once
#include "BotDifficultyLevel.h"
#include "BotPlayingStrategy.h"

class BotPlayingStrategyFactory
{
public:
	static std::shared_ptr<BotPlayingStrategy> CreateBotStrategy(BotDifficultyLevel difficulty);
};

