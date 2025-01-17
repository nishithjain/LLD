#include "Move.h"

Move::Move(const Cell& cell, const Player& player)
	: cell_(cell),
	player_(player)
{
}

Cell Move::GetCell() const
{
	return cell_;
}

void Move::SetCell(const Cell& cell)
{
	cell_ = cell;
}

Player Move::GetPlayer() const
{
	return player_;
}

void Move::SetPlayer(const Player& player)
{
	player_ = player;
}
