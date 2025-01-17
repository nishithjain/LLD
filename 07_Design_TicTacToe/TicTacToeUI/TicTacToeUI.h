#pragma once

#include <QPushButton>
#include <QtWidgets/QMainWindow>
#include "ui_TicTacToeUI.h"
#include <tuple>

#include "BotDifficultyLevel.h"
#include "TicTacToeGame.h"

class TicTacToeUi final : public QMainWindow
{
    Q_OBJECT

public:
    explicit TicTacToeUi(QWidget *parent = nullptr);
    void OnDifficultyLevelChanged() const;
    void OnBotRadioToggled() const;
    ~TicTacToeUi() override = default;

private:
    Ui::TicTacToeUIClass ui_;
    QString prev_p1_symbol_;
    QString prev_p2_symbol_;

    struct PlayersInfo
    {
        std::tuple<QString, QString> player1_info;
        std::tuple<QString, QString> player2_info;
        std::tuple<QString, QString> current_player_info;
    };
    PlayersInfo player_info_;

    struct UiState
	{
        QString p1_name;
        bool p1_line_enabled;
        QString p1_symbol;
        bool p1_symbol_enabled;

        bool bot_selected;
        bool bot_enabled;
        QString bot_difficulty_level;
        bool bot_difficulty_level_enabled;
    	bool player_selected;
        bool player_enabled;

        QString p2_name;
        bool p2_line_enabled;
        QString p2_symbol;
        bool p2_symbol_enabled;
    };
    UiState current_state_;
    void CaptureState();
    void RestoreState() const;
    void SwitchPlayer();
    void InitializePlayers();
    [[nodiscard]] std::tuple<QString, QString> GetCurrentPlayerInfo() const;
    [[nodiscard]] std::tuple<QString, QString> GetPlayer1NameAndSymbol() const;
    [[nodiscard]] std::tuple<QString, QString> GetPlayer2NameAndSymbol() const;
    void InformationLine(const QString& text) const;
    BotDifficultyLevel GetBotDifficultyLevel() const;
    void Play();
    static QString FormatPlayerInfo(const std::tuple<QString, QString>& player_info);
    void OnP1NameChanged(const QString& text) const;
    void OnPlayerRadioToggled(bool checked) const;
    void SetGameState(bool is_active) const;
    void OnPlayButtonClicked();
    static void OnUndoButtonClicked();
    void OnResetButtonClicked();
    void ResetUi();
    static void UpdateCellIcon(QPushButton* clicked_button, const QString& symbol);
    void OnP1SymbolChanged();
    void OnP2SymbolChanged();
    [[nodiscard]] QPushButton* GetCell(size_t row, size_t col) const;

    std::shared_ptr<TicTacToeGame> game_;
    int next_player_index_ = 0;
private slots:
    void OnCellClicked(int row, int col);
    void UpdateBoard() const;
};
