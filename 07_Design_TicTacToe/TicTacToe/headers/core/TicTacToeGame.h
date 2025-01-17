	#pragma once
#include <memory>
#include <vector>

#include "GameBoard.h"
#include "GameStatus.h"
#include "GameWinningStrategy.h"
#include "Move.h"
#include "Player.h"


using ListOfPlayers = std::vector<std::shared_ptr<Player>>;
class TicTacToeGame
{
public:
	GameBoard GetGameBoard() const;
	void SetGameBoard(const GameBoard& board);

private:
	GameBoard board_;
	ListOfPlayers players_;
	std::vector<Move> moves_;
	size_t next_player_index_ = 0;
	GameStatus game_status_ = GameStatus::ENDED;
	Player winner_;
	std::shared_ptr<GameWinningStrategy> game_winning_strategy_ = nullptr;
public:
	std::shared_ptr<GameWinningStrategy> GetGameWinningStrategy() const;
	void SetGameWinningStrategy(const std::shared_ptr<GameWinningStrategy>& game_winning_strategy);
	Player GetWinner() const;
	void SetWinner(const Player& winner);
	ListOfPlayers GetPlayers() const;
	void SetPlayers(const ListOfPlayers& players);
	std::vector<Move> GetMoves() const;
	void SetMoves(const std::vector<Move>& moves);
	size_t GetNextPlayerIndex() const;
	void SetNextPlayerIndex(size_t next_player_index);
	GameStatus GetGameStatus() const;
	void SetGameStatus(GameStatus game_status);
	void DisplayBoard() const;
	bool CheckDraw();
	void ExecuteNextMove(int row, int column);

	explicit TicTacToeGame(size_t dimension, ListOfPlayers players);

	class GameBuilder
	{
		// GameBoard board_; To build the game, we just need the dimension.
		size_t dimension_ = 3;
		ListOfPlayers players_;
		// std::vector<Move> moves_; Initially no moves will be there.
		// int next_player_index_; We start with 0th index
		// GameStatus game_status_; This is also not required. 
		// Player winner_;

	public:
		size_t GetDimension() const;
		GameBuilder SetDimension(size_t dimension);
		ListOfPlayers GetPlayers() const;
		GameBuilder SetPlayers(const ListOfPlayers& players);
		std::shared_ptr<TicTacToeGame> Build() const;
		bool IsValid() const;
		bool HasDuplicatePlayerSymbols() const;
	};

	static GameBuilder GetBuilder();
};

	

