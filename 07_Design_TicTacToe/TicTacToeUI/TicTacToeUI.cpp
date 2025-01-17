#include "TicTacToeUI.h"
#include <QWidget>
#include <QPushButton>
#include <QFrame>
#include <QMessageBox>
#include <QGroupBox>
#include <Player.h>

#include "Bot.h"
#include "TicTacToeGame.h"
#include "../TicTacToe/headers/controller/GameController.h"


QPushButton* TicTacToeUi::GetCell(const size_t row, const size_t col) const
{
	QPushButton* cells[3][3] =
	{
		{ui_.cell00, ui_.cell01, ui_.cell02},
		{ui_.cell10, ui_.cell11, ui_.cell12},
		{ui_.cell20, ui_.cell21, ui_.cell22}
	};
	return cells[row][col];
}

TicTacToeUi::TicTacToeUi(QWidget* parent) : QMainWindow(parent)
{
	ui_.setupUi(this);
	setWindowTitle("Tic-Tac-Toe");
	OnP1SymbolChanged();

	ui_.frame->setFrameStyle(QFrame::StyledPanel);
	ui_.frame->setFrameShadow(QFrame::Raised);
	ui_.frame->setStyleSheet("QFrame { background-color: rgb(135, 206, 235); }");

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			connect(GetCell(i, j), &QPushButton::clicked, this,
				[this, i, j]() { OnCellClicked(i, j); });
		}
	}

	// Connect other UI elements
	connect(ui_.p1NameLineEdit, &QLineEdit::textChanged, this, &TicTacToeUi::OnP1NameChanged);
	connect(ui_.playerRadioBtn, &QRadioButton::toggled, this, &TicTacToeUi::OnPlayerRadioToggled);
	connect(ui_.botRadioBtn, &QRadioButton::toggled, this, &TicTacToeUi::OnBotRadioToggled);
	connect(ui_.playButton, &QPushButton::clicked, this, &TicTacToeUi::OnPlayButtonClicked);
	connect(ui_.undoButton, &QPushButton::clicked, this, &TicTacToeUi::OnUndoButtonClicked);
	connect(ui_.gameResetButton, &QPushButton::clicked, this, &TicTacToeUi::OnResetButtonClicked);
	connect(ui_.p1SymbolCombo, &QComboBox::currentTextChanged, this, &TicTacToeUi::OnP1SymbolChanged);
	connect(ui_.p2SymbolCombo, &QComboBox::currentTextChanged, this, &TicTacToeUi::OnP2SymbolChanged);
	connect(ui_.botDifficultyLevelCombo, &QComboBox::currentTextChanged, this, &TicTacToeUi::OnDifficultyLevelChanged);

	// Initialize the UI to the starting state
	ResetUi();
}

void TicTacToeUi::OnDifficultyLevelChanged() const
{
	const QString difficulty_level = ui_.botDifficultyLevelCombo->currentText();
}

void TicTacToeUi::OnBotRadioToggled() const
{
	ui_.botDifficultyLevelCombo->setEnabled(true);
}

void TicTacToeUi::OnP1SymbolChanged()
{
	const QString p1_symbol = ui_.p1SymbolCombo->currentText();

	// Re-add the previously selected symbol for Player 1 in Player 2's combo box
	if (!prev_p1_symbol_.isEmpty())
	{
		ui_.p2SymbolCombo->addItem(prev_p1_symbol_);
	}

	// Remove the newly selected symbol from Player 2's combo box
	if (const int index_to_remove = ui_.p2SymbolCombo->findText(p1_symbol); index_to_remove != -1)
	{
		ui_.p2SymbolCombo->removeItem(index_to_remove);
	}

	// Update the stored previous symbol
	prev_p1_symbol_ = p1_symbol;
}

void TicTacToeUi::OnP2SymbolChanged()
{
	const QString p2_symbol = ui_.p2SymbolCombo->currentText();

	// Re-add the previously selected symbol for Player 2 in Player 1's combo box
	if (!prev_p2_symbol_.isEmpty())
	{
		ui_.p1SymbolCombo->addItem(prev_p2_symbol_);
	}

	// Remove the newly selected symbol from Player 1's combo box
	if (const int index_to_remove = ui_.p1SymbolCombo->findText(p2_symbol); index_to_remove != -1)
	{
		ui_.p1SymbolCombo->removeItem(index_to_remove);
	}

	// Update the stored previous symbol
	prev_p2_symbol_ = p2_symbol;
}

void TicTacToeUi::OnP1NameChanged(const QString& text) const
{
	const bool is_not_empty = !text.isEmpty();

	ui_.p1SymbolCombo->setEnabled(is_not_empty);
	ui_.botRadioBtn->setEnabled(is_not_empty);
	ui_.botRadioBtn->setChecked(is_not_empty);
	ui_.botDifficultyLevelCombo->setEnabled(is_not_empty);
	ui_.playerRadioBtn->setEnabled(is_not_empty);
	ui_.playButton->setEnabled(is_not_empty);
}

void TicTacToeUi::OnPlayerRadioToggled(const bool checked) const
{
	// Enable the second player elements if playerRadioBtn is checked
	ui_.p2NameLabel->setEnabled(checked);
	ui_.p2NameLineEdit->setEnabled(checked);
	ui_.p2SymbolLabel->setEnabled(checked);
	ui_.p2SymbolCombo->setEnabled(checked);
	ui_.botDifficultyLevelCombo->setEnabled(!checked);
}

void TicTacToeUi::SetGameState(const bool is_active) const
{
	for (int row = 0; row < 3; ++row)
	{
		for (int col = 0; col < 3; ++col)
		{
			QPushButton* cell = GetCell(row, col);
			cell->setEnabled(is_active);
			if (!is_active)
			{
				cell->setIcon(QIcon());
			}
		}
	}

	// Enable/Disable game buttons based on state
	ui_.undoButton->setEnabled(is_active);
	ui_.gameResetButton->setEnabled(is_active);
	ui_.playButton->setEnabled(!is_active);  // Play button is disabled when the game is active
}

void TicTacToeUi::OnUndoButtonClicked() {}

void TicTacToeUi::OnResetButtonClicked()
{
	RestoreState();
	ResetUi();
}

void TicTacToeUi::ResetUi()
{
	SetGameState(false);  // Disable all the cells at the start
	ui_.InformationLineEdit->clear();
	game_ = nullptr;
	next_player_index_ = 0;
}

void TicTacToeUi::UpdateCellIcon(QPushButton* clicked_button, const QString& symbol)
{
	// Set the icon based on the player's symbol
	if (symbol == "#")
	{
		const QIcon icon(":/TicTacToeUI/Resources/hash.png");
		clicked_button->setIcon(icon);
	}
	else if (symbol == "@")
	{
		const QIcon icon(":/TicTacToeUI/Resources/at.png");
		clicked_button->setIcon(icon);
	}
	else if (symbol == "O")
	{
		const QIcon icon(":/TicTacToeUI/Resources/o.png");
		clicked_button->setIcon(icon);
	}
	else if (symbol == "X")
	{
		const QIcon icon(":/TicTacToeUI/Resources/x.png");
		clicked_button->setIcon(icon);
	}

	const int width = clicked_button->width() - 20;
	const int height = clicked_button->height() - 20;

	const QSize new_icon_size(width, height);

	clicked_button->setIconSize(new_icon_size);
	// Disable the button
	clicked_button->setEnabled(false);
}

void TicTacToeUi::OnCellClicked(const int row, const int col)
{
	// Handle cell click based on row and col

	QPushButton* clicked_button = GetCell(row, col);
	if (clicked_button == nullptr)
		return;
	const auto game_status = GameController::GetGameStatus(game_);
	if (game_status == GameStatus::IN_PROGRESS)
	{
		auto [player_name, symbol] = GetCurrentPlayerInfo();
		UpdateCellIcon(clicked_button, symbol);
		GameController::ExecuteNextMove(game_, row, col);
		UpdateBoard();
		if(GameController::GetGameStatus(game_) == GameStatus::ENDED)
		{
			const auto winner = GameController::GetWinner(game_);
			const QString text(((winner.GetName() + " won the game!!!").data()));

			InformationLine(text);
			QMessageBox::warning(this, "We have a WINNER", text);

			RestoreState();
			ResetUi();
			return;
		}

		if (!ui_.botRadioBtn->isChecked())
		{
			SwitchPlayer();
			const auto text = "Your turn [" + FormatPlayerInfo(player_info_.current_player_info) + "]";
			InformationLine(text);
		}
	}
	if(GameController::GetGameStatus(game_) == GameStatus::DRAW)
	{
		QMessageBox::warning(this, "It's a DRAW",
			"Game ended in a DRAW");
		RestoreState();
		ResetUi();
	}
	//else if (game_status == GameStatus::ENDED)
	//{
	//	const auto winner = GameController::GetWinner(game_);
	//	QMessageBox::warning(this, "We have a WINNER",
	//		(winner.GetName() + " Has won the game").data());
	//}
}

void TicTacToeUi::UpdateBoard() const
{
	const auto board = game_->GetGameBoard().GetBoard();

	for (size_t i = 0; i < board.size(); i++)
	{
		for(size_t j = 0; j<board.size(); j++)
		{
			const auto clicked_button = GetCell(i, j);
			if(const auto player = board[i][j].GetPlayer(); 
				player.GetPlayerType() == PlayerType::BOT && 
				clicked_button->icon().isNull())
			{
				UpdateCellIcon(clicked_button, QString(player.GetSymbol()));

			}
		}
	}
}

void TicTacToeUi::CaptureState()
{
	current_state_.p1_name = ui_.p1NameLineEdit->text();
	current_state_.p1_line_enabled = ui_.p1NameLineEdit->isEnabled();
	current_state_.p1_symbol = ui_.p1SymbolCombo->currentText();
	current_state_.p1_symbol_enabled = ui_.p1SymbolCombo->isEnabled();

	current_state_.bot_selected = ui_.botRadioBtn->isChecked();
	current_state_.bot_enabled = ui_.botRadioBtn->isEnabled();
	current_state_.bot_difficulty_level = ui_.botDifficultyLevelCombo->currentText();
	current_state_.bot_difficulty_level_enabled = ui_.botDifficultyLevelCombo->isEnabled();
	current_state_.player_selected = ui_.playerRadioBtn->isChecked();
	current_state_.player_enabled = ui_.playerRadioBtn->isEnabled();

	current_state_.p2_name = ui_.p2NameLineEdit->text();
	current_state_.p2_line_enabled = ui_.p2NameLineEdit->isEnabled();
	current_state_.p2_symbol = ui_.p2SymbolCombo->currentText();
	current_state_.p2_symbol_enabled = ui_.p2SymbolCombo->isEnabled();
}

void TicTacToeUi::RestoreState() const
{
	ui_.p1NameLineEdit->setText(current_state_.p1_name);
	ui_.p1NameLineEdit->setEnabled(current_state_.p1_line_enabled);
	ui_.p1SymbolCombo->setCurrentText(current_state_.p1_symbol);
	ui_.p1SymbolCombo->setEnabled(current_state_.p1_symbol_enabled);

	ui_.botRadioBtn->setChecked(current_state_.bot_selected);
	ui_.botRadioBtn->setEnabled(current_state_.bot_enabled);
	ui_.botDifficultyLevelCombo->setEnabled(current_state_.bot_difficulty_level_enabled);
	ui_.botDifficultyLevelCombo->setCurrentText(current_state_.bot_difficulty_level);
	ui_.playerRadioBtn->setChecked(current_state_.player_selected);
	ui_.playerRadioBtn->setEnabled(current_state_.player_enabled);

	ui_.p2NameLineEdit->setText(current_state_.p2_name);
	ui_.p2NameLineEdit->setEnabled(current_state_.p2_line_enabled);
	ui_.p2SymbolCombo->setCurrentText(current_state_.p2_symbol);
	ui_.p2SymbolCombo->setEnabled(current_state_.p2_symbol_enabled);
}

void TicTacToeUi::SwitchPlayer()
{
	if (player_info_.current_player_info == player_info_.player1_info)
	{
		player_info_.current_player_info = player_info_.player2_info;
		next_player_index_ = 1;
	}
	else
	{
		player_info_.current_player_info = player_info_.player1_info;
		next_player_index_ = 0;
	}
}

std::tuple<QString, QString> TicTacToeUi::GetCurrentPlayerInfo() const
{
	return player_info_.current_player_info;
}

void TicTacToeUi::InitializePlayers()
{
	player_info_.player1_info = GetPlayer1NameAndSymbol();
	player_info_.player2_info = GetPlayer2NameAndSymbol();
	player_info_.current_player_info = player_info_.player1_info;
}

std::tuple<QString, QString> TicTacToeUi::GetPlayer1NameAndSymbol() const
{
	// Returns the current symbol for Player 1
	return { ui_.p1NameLineEdit->text(), ui_.p1SymbolCombo->currentText() };
}

std::tuple<QString, QString> TicTacToeUi::GetPlayer2NameAndSymbol() const
{
	if (ui_.playerRadioBtn->isChecked())
	{
		// Player 2 selected
		return { ui_.p2NameLineEdit->text(), ui_.p2SymbolCombo->currentText() };
	}
	// Bot is selected, assign bot symbol
	// Get Player 1's symbol
	const QString p1_symbol = ui_.p1SymbolCombo->currentText();

	// Find a symbol for the bot that is different from Player 1's symbol
	QString bot_symbol;
	for (int i = 0; i < ui_.p2SymbolCombo->count(); ++i)
	{
		if (QString symbol = ui_.p2SymbolCombo->itemText(i); symbol != p1_symbol)
		{
			bot_symbol = symbol; // Select the first available symbol that is different
			break; // Break once a valid symbol is found
		}
	}
	// Return Bot's name and selected symbol
	return { "Bot", bot_symbol };
}

void TicTacToeUi::InformationLine(const QString& text) const
{
	ui_.InformationLineEdit->clear();


	ui_.InformationLineEdit->setText(text);
}

BotDifficultyLevel TicTacToeUi::GetBotDifficultyLevel() const
{
	const QString selected_value = ui_.botDifficultyLevelCombo->currentText();

	if (selected_value == "Easy")
		return BotDifficultyLevel::EASY;
	if (selected_value == "Medium")
		return BotDifficultyLevel::MEDIUM;
	if (selected_value == "Hard")
		return BotDifficultyLevel::HARD;

	// Default case, return EASY if no match found
	return BotDifficultyLevel::EASY;
}

void TicTacToeUi::Play()
{
	constexpr int dimension = 3;

	ListOfPlayers players;

	players.push_back(std::make_shared<Player>(std::get<0>(player_info_.player1_info).toStdString(),
		std::get<1>(player_info_.player1_info).toStdString().c_str()[0], PlayerType::HUMAN));

	if (ui_.botRadioBtn->isChecked())
	{
		players.push_back(std::make_shared<Bot>("Bot", std::get<1>(player_info_.player2_info).toStdString().c_str()[0],
			GetBotDifficultyLevel()));
	}
	else
	{
		players.push_back(std::make_shared<Player>(std::get<0>(player_info_.player2_info).toStdString(),
			std::get<1>(player_info_.player2_info).toStdString().c_str()[0], PlayerType::HUMAN));
	}

	game_ = GameController::CreateGame(dimension, players);
}

QString TicTacToeUi::FormatPlayerInfo(const std::tuple<QString, QString>& player_info)
{
	return std::get<0>(player_info) + ": " + std::get<1>(player_info);
}

void TicTacToeUi::OnPlayButtonClicked()
{
	InitializePlayers();

	auto [player2_name, player2_symbol] = GetPlayer2NameAndSymbol();

	if (player2_name.isEmpty())
	{
		QMessageBox::warning(this, "Invalid Input",
			"Please enter a valid name for player 2.");
		return;
	}

	if (!ui_.botRadioBtn->isChecked() && player2_name.toLower().compare("bot") == 0)
	{
		QMessageBox::warning(this, "Invalid Input",
			"Player 2 name cannot be Bot!");
		return;
	}

	CaptureState();
	SetGameState(true);

	ui_.p1NameLineEdit->setEnabled(false);
	ui_.p1SymbolCombo->setEnabled(false);
	ui_.botRadioBtn->setEnabled(false);
	ui_.botDifficultyLevelCombo->setEnabled(false);
	ui_.playerRadioBtn->setEnabled(false);
	ui_.p2NameLineEdit->setEnabled(false);
	ui_.p2SymbolCombo->setEnabled(false);

	const auto text = "Your turn [" + FormatPlayerInfo(player_info_.current_player_info) + "]";
	InformationLine(text);
	Play();
}