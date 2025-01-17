#pragma once
#include <string>

#include "PlayerType.h"

class Player
{
public:
	std::string GetName() const;
	void SetName(const std::string& name);
	char GetSymbol() const;
	void SetSymbol(char symbol);
	PlayerType GetPlayerType() const;
	void SetPlayerType(PlayerType player_type);
	bool IsInitialized() const;

	Player(std::string name, char symbol, PlayerType player_type);
	Player();
	virtual ~Player() = default;
private:
	std::string name_;
	char symbol_ = '\0';
	PlayerType player_type_ = PlayerType::HUMAN;
};

