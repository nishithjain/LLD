#pragma once
#include <vector>

#include "Cell.h"

class GameBoard
{
public:
	explicit GameBoard(size_t dimension);

	// 2D Matrix which represents Tic-Tac-Toe Board.
	std::vector<std::vector<Cell>>& GetBoard();
	void SetBoard(const std::vector<std::vector<Cell>>& board);
	size_t GetDimension() const;
	void SetDimension(size_t dimension);
	void Display() const;
private:
	std::vector<std::vector<Cell>> board_;
	size_t dimension_; // Size of the Board.
};

