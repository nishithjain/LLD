#pragma once
#include <map>

#include "GameWinningStrategy.h"
class OrderOneGameWinningStrategy : public GameWinningStrategy
{
	std::vector<std::map<char, int>> row_symbol_count_;
	std::vector<std::map<char, int>> col_symbol_count_;

	std::map<char, int> top_left_diagonal_symbol_;
	std::map<char, int> top_right_diagonal_symbol_;
public:
	explicit OrderOneGameWinningStrategy(size_t dimension);
	static bool IsCellOnTopLeftDiagonal(size_t row, size_t col);
	static bool IsCellOnTopRightDiagonal(size_t row, size_t col, size_t dimension);
	~OrderOneGameWinningStrategy() override = default;
	bool CheckWinner(GameBoard board, Move move) override;
};

