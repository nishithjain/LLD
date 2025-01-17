#pragma once
#include "BotPlayingStrategy.h"

class BotHardMove final : public BotPlayingStrategy
{
public:
    BotHardMove() = default;
    ~BotHardMove() override = default;
    std::shared_ptr<Move> MakeMove(const Player& player, GameBoard& board) override;

private:
    int Minimax(GameBoard& board, int depth, bool is_maximizing, const Player& bot, const Player& opponent);
    static bool IsGameOver(GameBoard& board);
    static int EvaluateBoard(GameBoard& board, const Player& bot, const Player& opponent);
    static std::vector<Cell> GetAvailableMoves(GameBoard& board);
};
