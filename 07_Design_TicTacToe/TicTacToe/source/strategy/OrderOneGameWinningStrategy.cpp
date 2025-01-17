#include "OrderOneGameWinningStrategy.h"

OrderOneGameWinningStrategy::OrderOneGameWinningStrategy(const size_t dimension)
{
	row_symbol_count_.resize(dimension);
	col_symbol_count_.resize(dimension);
}

bool OrderOneGameWinningStrategy::IsCellOnTopLeftDiagonal(const size_t row, const size_t col)
{
	return row == col;
}

bool OrderOneGameWinningStrategy::IsCellOnTopRightDiagonal(const size_t row, const size_t col, const size_t dimension)
{
	return row + col == dimension - 1;
}

bool OrderOneGameWinningStrategy::CheckWinner(const GameBoard board, const Move move)
{
	const auto symbol = move.GetPlayer().GetSymbol();
	const auto row = move.GetCell().GetRow();
	const auto col = move.GetCell().GetCol();
	const auto dimension = board.GetDimension();

	row_symbol_count_[row][symbol] += 1;
	col_symbol_count_[col][symbol] += 1;

	if (IsCellOnTopLeftDiagonal(row, col))
	{
		top_left_diagonal_symbol_[symbol] += 1;
	}
	if (IsCellOnTopRightDiagonal(row, col, dimension))
	{
		top_right_diagonal_symbol_[symbol] += 1;
	}

	if (row_symbol_count_[row][symbol] == dimension ||
		col_symbol_count_[col][symbol] == dimension)
	{
		return true;
	}

	if (IsCellOnTopLeftDiagonal(row, col) &&
		top_left_diagonal_symbol_[symbol] == dimension)
	{
		return true;
	}

	if (IsCellOnTopRightDiagonal(row, col, dimension)
		&& top_right_diagonal_symbol_[symbol] == dimension)
	{
		return true;
	}
	return false;
}
