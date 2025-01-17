#pragma once
#include "CellState.h"
#include "Player.h"

class Cell
{
	CellState cell_state_ = CellState::EMPTY;
	size_t row_;
	size_t col_;
	Player player_;

public:
	size_t GetRow() const;
	void SetRow(size_t row);
	size_t GetCol() const;
	void SetCol(size_t col);
	Player GetPlayer() const;
	void SetPlayer(const Player& player);
	CellState GetCellState() const;
	void SetCellState(CellState cell_state);
	Cell();
	Cell(CellState cell_state, size_t row, size_t col, const Player& player);
};

