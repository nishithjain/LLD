#include "BotMediumMove.h"

#include "BotEasyMove.h"
#include "OrderOneGameWinningStrategy.h"
#include "OrderTwoGameWinningStrategy.h"

Player BotMediumMove::GetOpponentPlayer(GameBoard& board)
{
	const auto& game_board = board.GetBoard();
    for (size_t i = 0; i < game_board.size(); ++i)
    {
        for (size_t j = 0; j < game_board.size(); ++j)
        {
            const auto& cell = game_board[i][j];
            if (cell.GetCellState() == CellState::FILLED && cell.GetPlayer().GetPlayerType() == PlayerType::HUMAN)
            {
                return cell.GetPlayer();
            }
        }
    }
    return Player{};
}

std::shared_ptr<Move> BotMediumMove::MakeMove(const Player& player, GameBoard& board)
{
    size_t row, col;
    bool bot_can_win = false;
    bool opponent_can_win = false;
    const auto opponent_player = GetOpponentPlayer(board);

    // Check if bot can win
    if (CheckWinningMove(player, board, row, col))
    {
        bot_can_win = true;
    }
    else if (!opponent_player.GetName().empty() && // Check if opponent can win and block them
        CheckWinningMove(opponent_player, board, row, col))
    {
        opponent_can_win = true;
    }

    if (bot_can_win || opponent_can_win)
    {
        auto& cell = board.GetBoard()[row][col];
        cell.SetCellState(CellState::FILLED);
        cell.SetPlayer(player);
        return AssignBotToCell(cell, player);
    }

    BotEasyMove easy_move;
    return  easy_move.MakeMove(player, board);
}

bool BotMediumMove::CheckWinningMove(const Player& player, GameBoard& board, size_t& row, size_t& col) const
{
    auto& game_board = board.GetBoard();
    OrderTwoGameWinningStrategy winning_strategy;
    for (size_t i = 0; i < game_board.size(); ++i)
    {
        for (size_t j = 0; j < game_board.size(); ++j)
        {
            auto& bot_cell = game_board[i][j];
            if (bot_cell.GetCellState() == CellState::EMPTY)
            {
                bot_cell.SetCellState(CellState::FILLED);
                bot_cell.SetPlayer(player);

                const Move move(bot_cell, player);
                if (winning_strategy.CheckWinner(board, move))
                {
                    row = i;
                    col = j;
                    bot_cell.SetPlayer(empty_player_);
                    bot_cell.SetCellState(CellState::EMPTY);

                    return true;
                }
                bot_cell.SetPlayer(empty_player_);
                bot_cell.SetCellState(CellState::EMPTY);
            }
        }
    }
    return false;
}

std::shared_ptr<Move> BotMediumMove::AssignBotToCell(Cell& bot_cell, const Player& player)
{
    bot_cell.SetCellState(CellState::FILLED);
    bot_cell.SetPlayer(player);
    return std::make_shared<Move>(bot_cell, player);
}