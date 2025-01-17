#pragma once
#include "TicTacToeGame.h"

// Controller is the interface through which clients will interact with system.
class GameController
{
public:
	// Instead of client creating the game, controller takes the responsibility.
	static std::shared_ptr<TicTacToeGame> CreateGame(size_t dimension, const ListOfPlayers& players);

	static void Undo(const std::shared_ptr<TicTacToeGame>& game);

	static void ExecuteNextMove(const std::shared_ptr<TicTacToeGame>& game, int row, int column);

	static Player GetWinner(const std::shared_ptr<TicTacToeGame>& game);

	static GameStatus GetGameStatus(const std::shared_ptr<TicTacToeGame>& game);

	static void DisplayBoard(const std::shared_ptr<TicTacToeGame>& game);
};



