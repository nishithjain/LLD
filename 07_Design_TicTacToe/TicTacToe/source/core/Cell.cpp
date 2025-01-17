#include "Cell.h"

size_t Cell::GetRow() const
{
	return row_;
}

void Cell::SetRow(const size_t row)
{
	row_ = row;
}

size_t Cell::GetCol() const
{
	return col_;
}

void Cell::SetCol(const size_t col)
{
	col_ = col;
}

Player Cell::GetPlayer() const
{
	return player_;
}

void Cell::SetPlayer(const Player& player)
{
	player_ = player;
}

CellState Cell::GetCellState() const
{
	return cell_state_;
}

void Cell::SetCellState(const CellState cell_state)
{
	cell_state_ = cell_state;
}

Cell::Cell() : cell_state_(CellState::EMPTY), row_(0), col_(0),
player_("", '\0', PlayerType::HUMAN)
{
	
}

Cell::Cell(const CellState cell_state, const size_t row, const size_t col,
           const Player& player) :
	cell_state_(cell_state),
	row_(row),
	col_(col),
	player_(player)
{
}
