#include "GameBoard.h"

#include <iostream>
#include <ostream>


GameBoard::GameBoard(const size_t dimension) : dimension_(dimension)
{
	// Resize the board to dimension x dimension
	board_.resize(dimension_);

	for (size_t row = 0; row < dimension_; ++row)
	{
		board_[row].resize(dimension_);

		for (size_t col = 0; col < dimension_; ++col)
		{
			// Initialize each cell with the correct row, col, and an empty player
			board_[row][col] = Cell(CellState::EMPTY, row, col,
				               Player("", '\0', PlayerType::HUMAN));
		}
	}
}

std::vector<std::vector<Cell>>& GameBoard::GetBoard()
{
	return board_;
}

void GameBoard::SetBoard(const std::vector<std::vector<Cell>>& board)
{
	board_ = board;
}

size_t GameBoard::GetDimension() const
{
	return dimension_;
}

void GameBoard::SetDimension(const size_t dimension)
{
	dimension_ = dimension;
}

void GameBoard::Display() const
{
	for (size_t i = 0; i < board_.size(); i++)
	{
		for (size_t j = 0; j < board_.size(); j++)
		{
			if (board_[j][j].GetCellState() == CellState::EMPTY)
			{
				std::cout << "|  |";
			}
			else
			{
				std::cout << "| " << board_[i][j].GetPlayer().GetSymbol() << " |";
			}
		}
		std::cout << "\n";
	}
}

