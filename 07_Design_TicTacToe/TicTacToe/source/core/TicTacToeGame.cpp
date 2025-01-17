#include "TicTacToeGame.h"

#include <iostream>
#include <set>
#include <stdexcept>

#include "BoardDimensionException.h"
#include "Bot.h"
#include "BotEasyMove.h"
#include "BotPlayingStrategyFactory.h"
#include "DuplicatePlayerSymbolException.h"
#include "PlayerCountException.h"
#include "OrderOneGameWinningStrategy.h"

GameBoard TicTacToeGame::GetGameBoard() const
{
	return board_;
}

void TicTacToeGame::SetGameBoard(const GameBoard& board)
{
	board_ = board;
}

std::shared_ptr<GameWinningStrategy> TicTacToeGame::GetGameWinningStrategy() const
{
	return game_winning_strategy_;
}

void TicTacToeGame::SetGameWinningStrategy(const std::shared_ptr<GameWinningStrategy>& game_winning_strategy)
{
	game_winning_strategy_ = game_winning_strategy;
}

Player TicTacToeGame::GetWinner() const
{
	return winner_;
}

void TicTacToeGame::SetWinner(const Player& winner)
{
	winner_ = winner;
}

ListOfPlayers TicTacToeGame::GetPlayers() const
{
	return players_;
}

void TicTacToeGame::SetPlayers(const ListOfPlayers& players)
{
	players_ = players;
}

std::vector<Move> TicTacToeGame::GetMoves() const
{
	return moves_;
}

void TicTacToeGame::SetMoves(const std::vector<Move>& moves)
{
	moves_ = moves;
}

size_t TicTacToeGame::GetNextPlayerIndex() const
{
	return next_player_index_;
}

void TicTacToeGame::SetNextPlayerIndex(const size_t next_player_index)
{
	next_player_index_ = next_player_index;
}

GameStatus TicTacToeGame::GetGameStatus() const
{
	return game_status_;
}

void TicTacToeGame::SetGameStatus(const GameStatus game_status)
{
	game_status_ = game_status;
}

void TicTacToeGame::DisplayBoard() const
{
	board_.Display();
}

bool TicTacToeGame::CheckDraw()
{
	const auto& board = board_.GetBoard();
	for (const auto& row : board)
	{
		for (const auto& cell : row)
		{
			if (cell.GetCellState() == CellState::EMPTY)
			{
				return false;
			}
		}
	}

	game_status_ = GameStatus::DRAW;
	return true;
}

void TicTacToeGame::ExecuteNextMove(const int row, const int column)
{
	const bool human_and_bot = players_.size() == 2 &&
		players_[0]->GetPlayerType() == PlayerType::HUMAN &&
		players_[1]->GetPlayerType() == PlayerType::BOT;


	auto& current_cell = board_.GetBoard()[row][column];
	const auto player_to_move = *players_[next_player_index_++];

	current_cell.SetCellState(CellState::FILLED);
	current_cell.SetPlayer(player_to_move);
	const Move current_move(current_cell, player_to_move);
	moves_.push_back(current_move);

	if (game_winning_strategy_->CheckWinner(board_, current_move))
	{
		game_status_ = GameStatus::ENDED;
		winner_ = player_to_move;
		return;
	}

	if (game_status_ != GameStatus::ENDED && CheckDraw())
		return;

	if (human_and_bot)
	{
		auto* bot_player = dynamic_cast<Bot*>(players_[next_player_index_++].get());
		bot_player->SetBotPlayingStrategy(
			BotPlayingStrategyFactory::CreateBotStrategy(bot_player->GetBotDifficultyLevel()));
		const auto move = bot_player->MakeMove(*bot_player, board_);
		if (game_winning_strategy_->CheckWinner(board_, *move))
		{
			game_status_ = GameStatus::ENDED;
			winner_ = static_cast<Player>(*bot_player);
		}
		if (CheckDraw())
			return;
	}

	next_player_index_ %= players_.size();
}

TicTacToeGame::TicTacToeGame(const size_t dimension, ListOfPlayers players) :
	board_(dimension), players_(std::move(players))
{

}

size_t TicTacToeGame::GameBuilder::GetDimension() const
{
	return dimension_;
}

TicTacToeGame::GameBuilder TicTacToeGame::GameBuilder::SetDimension(const size_t dimension)
{
	dimension_ = dimension;
	return *this;
}

ListOfPlayers TicTacToeGame::GameBuilder::GetPlayers() const
{
	return players_;
}

TicTacToeGame::GameBuilder TicTacToeGame::GameBuilder::SetPlayers(const ListOfPlayers& players)
{
	players_ = players;
	return *this;
}

bool TicTacToeGame::GameBuilder::HasDuplicatePlayerSymbols() const
{
	std::set<char> symbols;

	for (const auto& player : players_)
	{
		char symbol = player->GetSymbol();
		if (symbol != '\0') // Ignore uninitialized players
		{
			if (symbols.find(symbol) != symbols.end())
			{
				return true; // Duplicate symbol found
			}
			symbols.insert(symbol);  // Add symbol to the set
		}
	}

	return false; // No duplicates
}

TicTacToeGame::GameBuilder TicTacToeGame::GetBuilder()
{
	static GameBuilder game_builder;
	return game_builder;
}

bool TicTacToeGame::GameBuilder::IsValid() const
{
	if (players_.size() != dimension_ - 1)
		throw PlayerCountException("Number of players should be " +
			std::to_string(dimension_ - 1));
	if (dimension_ < 3)
		throw BoardDimensionException("Size of the board cannot be less than 3");
	if (HasDuplicatePlayerSymbols())
		throw DuplicatePlayerSymbolException("2 or more players has same symbol");

	return true;
}

std::shared_ptr<TicTacToeGame> TicTacToeGame::GameBuilder::Build() const
{
	try
	{
		if (IsValid())
		{
			auto game = std::make_shared<TicTacToeGame>(dimension_, players_);
			game->game_status_ = GameStatus::IN_PROGRESS;
			game->next_player_index_ = 0;
			game->SetGameWinningStrategy(std::make_shared<OrderOneGameWinningStrategy>(dimension_));
			return game;
		}
	}
	catch (BoardDimensionException& e)
	{
		std::cout << e.what();
		return nullptr;
	}
	catch (PlayerCountException& e)
	{
		std::cout << e.what();
		return nullptr;
	}
	catch (DuplicatePlayerSymbolException& e)
	{
		std::cout << e.what();
		return nullptr;
	}
	return nullptr;
}