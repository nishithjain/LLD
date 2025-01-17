#include "OrderTwoGameWinningStrategy.h"

bool OrderTwoGameWinningStrategy::CheckWinner(GameBoard board, const Move move)
{
    const auto& game_board = board.GetBoard();
    const auto symbol = move.GetPlayer().GetSymbol();

    // Check rows
    for (int row = 0; row < 3; ++row) 
    {
        if (game_board[row][0].GetPlayer().GetSymbol() == symbol && 
            game_board[row][1].GetPlayer().GetSymbol() == symbol && 
            game_board[row][2].GetPlayer().GetSymbol() == symbol)
        {
            return true;
        }
    }

    // Check columns
    for (int col = 0; col < 3; ++col) 
    {
        if (game_board[0][col].GetPlayer().GetSymbol() == symbol && 
            game_board[1][col].GetPlayer().GetSymbol() == symbol && 
            game_board[2][col].GetPlayer().GetSymbol() == symbol)
        {
            return true;
        }
    }

    // Check diagonals
    if (game_board[0][0].GetPlayer().GetSymbol() == symbol && 
        game_board[1][1].GetPlayer().GetSymbol() == symbol && 
        game_board[2][2].GetPlayer().GetSymbol() == symbol)
    {
        return true;
    }
    if (game_board[0][2].GetPlayer().GetSymbol() == symbol && 
        game_board[1][1].GetPlayer().GetSymbol() == symbol && 
        game_board[2][0].GetPlayer().GetSymbol() == symbol)
    {
        return true;
    }

    return false;  // No winning condition met
}
