#include <iostream>
#include <vector>
#include <string>

#include "Bot.h"
#include "GameController.h"
#include "Player.h"
#include "TicTacToeGame.h"
using namespace std;

//int main()
//{
//	constexpr int dimension = 3;
//
//	ListOfPlayers players;
//	players.push_back(make_shared<Player>("Nishith", '0', PlayerType::HUMAN));
//	players.push_back(make_shared<Bot>("Bot", 'X', BotDifficultyLevel::EASY));
//
//	const auto game = GameController::CreateGame(dimension, players);
//
//	while(GameController::GetGameStatus(game) == GameStatus::IN_PROGRESS)
//	{
//		std::cout << "This is the Current Board\n";
//		GameController::DisplayBoard(game);
//		GameController::ExecuteNextMove(game);
//
//	}
//
//	if(GameController::GetGameStatus(game) == GameStatus::DRAW)
//	{
//		
//	}
//	else if(GameController::GetGameStatus(game) == GameStatus::ENDED)
//	{
//		// game->GetWinner();
//	}
//
//	return 0;
//}