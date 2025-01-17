#include "BotEasyMove.h"


std::shared_ptr<Move> BotEasyMove::MakeMove(const Player& player, GameBoard& board)
{
    std::vector<std::pair<int, int>> empty_cells;
    for (int i = 0; i < 3; ++i) 
    {
        for (int j = 0; j < 3; ++j) 
        {
            if (board.GetBoard()[i][j].GetCellState() == CellState::EMPTY)
            { 
                empty_cells.emplace_back(i, j);
            }
        }
    }
    if (!empty_cells.empty())
    {
        // Randomly select one empty cell
        const auto random_index = rand() % empty_cells.size();
        auto& bot_cell = board.GetBoard()[empty_cells[random_index].first][empty_cells[random_index].second];
        bot_cell.SetCellState(CellState::FILLED);
        bot_cell.SetPlayer(player);
        return std::make_shared<Move>(bot_cell, player);
    }
    return nullptr;
}
