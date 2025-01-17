#include "GameController.h"

#include <iostream>

std::shared_ptr<TicTacToeGame> GameController::CreateGame(const size_t dimension, const ListOfPlayers& players)
{
	return TicTacToeGame::GetBuilder()
		.SetDimension(dimension)
		.SetPlayers(players)
		.Build();
}

void GameController::Undo(const std::shared_ptr<TicTacToeGame>& game)
{
}

void GameController:: ExecuteNextMove(const std::shared_ptr<TicTacToeGame>& game, const int row, const int column)
{
	game->ExecuteNextMove(row, column);
}

Player GameController::GetWinner(const std::shared_ptr<TicTacToeGame>& game)
{
	return game->GetWinner();
}

GameStatus GameController::GetGameStatus(const std::shared_ptr<TicTacToeGame>& game)
{
	return game->GetGameStatus();
}

void GameController::DisplayBoard(const std::shared_ptr<TicTacToeGame>& game)
{
	game->DisplayBoard();
}
