#include "BotHardMove.h"

#include "BotMediumMove.h"


std::shared_ptr<Move> BotHardMove::MakeMove(const Player& player, GameBoard& board)
{
	const auto opponent = BotMediumMove::GetOpponentPlayer(board);

	int best_score = -1000; // Initialize to a low score.
	size_t best_row = 0, best_col = 0;

	// Simulate every possible move for the bot.
	for (auto& cell : GetAvailableMoves(board))
	{
		board.GetBoard()[cell.GetRow()][cell.GetCol()].SetCellState(CellState::FILLED);
		board.GetBoard()[cell.GetRow()][cell.GetCol()].SetPlayer(player);

		// Call Minimax to simulate opponent's response and calculate move score.
		const int move_score = Minimax(board, 0, false, player, opponent);

		// Undo move after simulation.
		board.GetBoard()[cell.GetRow()][cell.GetCol()].SetCellState(CellState::EMPTY);
		board.GetBoard()[cell.GetRow()][cell.GetCol()].SetPlayer(Player{});

		// Maximize bot's score.
		if (move_score > best_score)
		{
			best_score = move_score;
			best_row = cell.GetRow();
			best_col = cell.GetCol();
		}
	}

	// Make the best move found.
	auto& best_cell = board.GetBoard()[best_row][best_col];
	best_cell.SetCellState(CellState::FILLED);
	best_cell.SetPlayer(player);
	return std::make_shared<Move>(best_cell, player);
}

int BotHardMove::Minimax(GameBoard& board, const int depth, const bool is_maximizing,
	const Player& bot, const Player& opponent)
{
	if (IsGameOver(board))
	{
		return EvaluateBoard(board, bot, opponent);
	}

	if (is_maximizing)
	{
		int best_score = -1000;
		for (auto& cell : GetAvailableMoves(board))
		{
			// Simulate bot's move.
			board.GetBoard()[cell.GetRow()][cell.GetCol()].SetCellState(CellState::FILLED);
			board.GetBoard()[cell.GetRow()][cell.GetCol()].SetPlayer(bot);

			// Recursively calculate the score for this move.
			int score = Minimax(board, depth + 1, false, bot, opponent);

			// Undo move after simulation.
			board.GetBoard()[cell.GetRow()][cell.GetCol()].SetCellState(CellState::EMPTY);
			board.GetBoard()[cell.GetRow()][cell.GetCol()].SetPlayer(Player{});

			best_score = std::max(best_score, score);
		}
		return best_score;
	}
	int best_score = 1000;
	for (auto& cell : GetAvailableMoves(board))
	{
		// Simulate opponent's move.
		board.GetBoard()[cell.GetRow()][cell.GetCol()].SetCellState(CellState::FILLED);
		board.GetBoard()[cell.GetRow()][cell.GetCol()].SetPlayer(opponent);

		// Recursively calculate the score for this move.
		int score = Minimax(board, depth + 1, true, bot, opponent);

		// Undo move after simulation.
		board.GetBoard()[cell.GetRow()][cell.GetCol()].SetCellState(CellState::EMPTY);
		board.GetBoard()[cell.GetRow()][cell.GetCol()].SetPlayer(Player{});

		best_score = std::min(best_score, score);
	}
	return best_score;
}

bool BotHardMove::IsGameOver(GameBoard& board)
{
	// Retrieve the game board
	const auto& game_board = board.GetBoard();

	// Check if any player has won by checking rows, columns, and diagonals.
	for (int row = 0; row < 3; ++row) 
	{
		if (game_board[row][0].GetCellState() != CellState::EMPTY &&
			game_board[row][0].GetPlayer().GetSymbol() == game_board[row][1].GetPlayer().GetSymbol() &&
			game_board[row][1].GetPlayer().GetSymbol() == game_board[row][2].GetPlayer().GetSymbol())
		{
			return true;  // A player has won
		}
	}

	for (int col = 0; col < 3; ++col) 
	{
		if (game_board[0][col].GetCellState() != CellState::EMPTY &&
			game_board[0][col].GetPlayer().GetSymbol() == game_board[1][col].GetPlayer().GetSymbol() &&
			game_board[1][col].GetPlayer().GetSymbol() == game_board[2][col].GetPlayer().GetSymbol())
		{
			return true;  // A player has won
		}
	}

	// Check diagonals
	if (game_board[0][0].GetCellState() != CellState::EMPTY &&
		game_board[0][0].GetPlayer().GetSymbol() == game_board[1][1].GetPlayer().GetSymbol() &&
		game_board[1][1].GetPlayer().GetSymbol() == game_board[2][2].GetPlayer().GetSymbol())
	{
		return true;  // A player has won
	}

	if (game_board[0][2].GetCellState() != CellState::EMPTY &&
		game_board[0][2].GetPlayer().GetSymbol() == game_board[1][1].GetPlayer().GetSymbol() &&
		game_board[1][1].GetPlayer().GetSymbol() == game_board[2][0].GetPlayer().GetSymbol())
	{
		return true;  // A player has won
	}

	// Check if there are any empty cells left; if no, it's a draw
	for (const auto& row : game_board)
	{
		for (const auto& cell : row) 
		{
			if (cell.GetCellState() == CellState::EMPTY)
			{
				return false;  // Game is not over; there are still moves to be made
			}
		}
	}

	// If no player has won and there are no empty cells, it's a draw
	return true;
}


int BotHardMove::EvaluateBoard(GameBoard& board, const Player& bot, const Player& opponent)
{
	const auto& game_board = board.GetBoard();

	// Check rows for a win
	for (int row = 0; row < 3; ++row) 
	{
		if (game_board[row][0].GetPlayer().GetSymbol() == game_board[row][1].GetPlayer().GetSymbol() &&
			game_board[row][1].GetPlayer().GetSymbol() == game_board[row][2].GetPlayer().GetSymbol() &&
			game_board[row][0].GetCellState() != CellState::EMPTY)
		{
			if (game_board[row][0].GetPlayer().GetSymbol() == bot.GetSymbol()) 
			{
				return 1;  // Bot wins
			}
			if (game_board[row][0].GetPlayer().GetSymbol() == opponent.GetSymbol()) {
				return -1;  // Opponent wins
			}
		}
	}

	// Check columns for a win
	for (int col = 0; col < 3; ++col) 
	{
		if (game_board[0][col].GetPlayer().GetSymbol() == game_board[1][col].GetPlayer().GetSymbol() &&
			game_board[1][col].GetPlayer().GetSymbol() == game_board[2][col].GetPlayer().GetSymbol() &&
			game_board[0][col].GetCellState() != CellState::EMPTY)
		{
			if (game_board[0][col].GetPlayer().GetSymbol() == bot.GetSymbol()) 
			{
				return 1;  // Bot wins
			}
			if (game_board[0][col].GetPlayer().GetSymbol() == opponent.GetSymbol()) 
			{
				return -1;  // Opponent wins
			}
		}
	}

	// Check diagonals for a win
	if (game_board[0][0].GetPlayer().GetSymbol() == game_board[1][1].GetPlayer().GetSymbol() &&
		game_board[1][1].GetPlayer().GetSymbol() == game_board[2][2].GetPlayer().GetSymbol() &&
		game_board[0][0].GetCellState() != CellState::EMPTY)
	{
		if (game_board[0][0].GetPlayer().GetSymbol() == bot.GetSymbol()) 
		{
			return 1;  // Bot wins
		}
		if (game_board[0][0].GetPlayer().GetSymbol() == opponent.GetSymbol()) 
		{
			return -1;  // Opponent wins
		}
	}

	if (game_board[0][2].GetPlayer().GetSymbol() == game_board[1][1].GetPlayer().GetSymbol() &&
		game_board[1][1].GetPlayer().GetSymbol() == game_board[2][0].GetPlayer().GetSymbol() &&
		game_board[0][2].GetCellState() != CellState::EMPTY)
	{
		if (game_board[0][2].GetPlayer().GetSymbol() == bot.GetSymbol()) 
		{
			return 1;  // Bot wins
		}
		if (game_board[0][2].GetPlayer().GetSymbol() == opponent.GetSymbol()) 
		{
			return -1;  // Opponent wins
		}
	}

	// If no one has won, return 0 for draw or ongoing game
	return 0;
}


std::vector<Cell> BotHardMove::GetAvailableMoves(GameBoard& board)
{
	std::vector<Cell> available_moves;
	for (size_t i = 0; i < board.GetBoard().size(); ++i)
	{
		for (size_t j = 0; j < board.GetBoard().size(); ++j)
		{
			if (board.GetBoard()[i][j].GetCellState() == CellState::EMPTY)
			{
				available_moves.push_back(board.GetBoard()[i][j]);
			}
		}
	}
	return available_moves;
}
