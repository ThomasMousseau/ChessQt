/*
* \file   ChessWindow.cpp
* \author Matteo Colavita et Thomas Mousseau
* \date   25 avril 2022
* Créé le 20 avril 2022
*/

#include "ChessWindow.h"

#include "Board.h"
#include "Raii.h"

using namespace graphicinterface;

ChessWindow::ChessWindow(QWidget* parent) :
	QMainWindow(parent)
{

}

void graphicinterface::ChessWindow::addGameModeLabel()
{
	if(rightLayout_ == nullptr)
	{
		rightLayout_ = new QVBoxLayout();
	}

	gameModeLabel_ = new QLabel();
	QFont gameModeFont = gameModeLabel_->font();
	gameModeFont.setPointSize(25);
	gameModeLabel_->setFont(gameModeFont);
	gameModeLabel_->setText("Please choose a game mode:");
	rightLayout_->addWidget(gameModeLabel_, 0, Qt::AlignBottom | Qt::AlignCenter);
	
}

void graphicinterface::ChessWindow::addGameModeButton()
{
	QHBoxLayout* buttonBoxLayout = new QHBoxLayout();
	buttonBoxLayout->setSpacing(0);

	QPushButton* buttonModeNormal = new QPushButton();
	buttonModeNormal->setText("Mode Normal");
	buttonModeNormal->setFixedSize(200, 100);
	QObject::connect(buttonModeNormal, &QPushButton::clicked, this, &ChessWindow::buttonNormalModeClicked);


	QPushButton* buttonModeSpecial = new QPushButton();
	buttonModeSpecial->setText("Mode Special");
	buttonModeSpecial->setFixedSize(200, 100);
	QObject::connect(buttonModeSpecial, &QPushButton::clicked, this, &ChessWindow::buttonSpecialModeClicked);

	buttonBoxLayout->addWidget(buttonModeNormal, 0, Qt::AlignTop | Qt::AlignCenter);
	buttonBoxLayout->addWidget(buttonModeSpecial, 0, Qt::AlignTop | Qt::AlignCenter);

	rightLayout_->addLayout(buttonBoxLayout);
}

void graphicinterface::ChessWindow::addPlayersTurnLabel()
{
	colorTurnLabel_ = new QLabel();

	if(rightLayout_ == nullptr)
	{
		rightLayout_ = new QVBoxLayout();
	}
	
	colorTurnLabel_->setText("White's turn");
	QFont font = colorTurnLabel_->font();
	font.setPointSize(50);
	colorTurnLabel_->setFont(font);
	colorTurnLabel_->setAlignment(Qt::AlignCenter | Qt::AlignTop);
	layout_->addLayout(rightLayout_);
	rightLayout_->addWidget(colorTurnLabel_, 0, Qt::AlignTop | Qt::AlignCenter);
	
}

ChessWindow::ChessWindow(QHBoxLayout* layout, QWidget* parent) :
QMainWindow(parent), layout_(layout)
{
	populateBoard();
	addGameModeLabel();
	addGameModeButton();
	addPlayersTurnLabel();

	/*}
	catch (TooManyKingsException& e)
	{
		QMessageBox messageBox;
		messageBox.critical(this, "QTERROR", e.what());
	}*/
	
}

void graphicinterface::ChessWindow::resetBoard()
{
	clickedPositions_.clear();

	

	for(auto&& square : squares_)
	{
		QPalette pal = square.second->palette();
		if ((get<0>(square.first) + get<1>(square.first)) % 2)
			pal.setColor(QPalette::Button, Qt::gray);
		else
			pal.setColor(QPalette::Button, Qt::red);

		square.second->setPalette(pal);
		square.second->setAutoFillBackground(true);
		square.second->update();
	}
}

void graphicinterface::ChessWindow::updateBoard()
{
	for(auto&& square: squares_)
	{
		square.second->update();
	}
}

void graphicinterface::ChessWindow::clearBoard()
{
	for (auto&& square : squares_)
	{
		square.second->setText("");
	}
}

void graphicinterface::ChessWindow::addPiece(std::tuple<char, int> coords, std::string symbol)
{
	squares_[coords]->setText(QString::fromStdString(symbol));
}

void graphicinterface::ChessWindow::populateBoard()
{
	QGridLayout* gridLayout = new QGridLayout();
	gridLayout->setSpacing(0);
	gridLayout->setVerticalSpacing(0);
	gridLayout->setHorizontalSpacing(0);
	gridLayout->setAlignment(Qt::AlignCenter);

	for (char i = 'a'; i <= 'h'; i++)
	{
		for (int j = 1; j <= 8; j++)
		{
			gridLayout->addWidget(addButton(i, j), j, i);
		}
	}

	layout_->addLayout(gridLayout);
}

QPushButton* graphicinterface::ChessWindow::addButton(int posI, int posJ)
{
	QPushButton* button = new QPushButton();
	const int tileSize = 100;
	button->setGeometry(QRect(posI * tileSize, posJ * tileSize, tileSize, tileSize));
	QPalette pal = button->palette();
	if ((posI + posJ) % 2)
		pal.setColor(QPalette::Button, Qt::gray);
	else
		pal.setColor(QPalette::Button, Qt::red);

	button->setPalette(pal);
	button->setAutoFillBackground(true);
	QFont font = button->font();
	font.setPointSize(30);
	button->setFont(font);

	std::tuple<char, int> coords = std::make_tuple(posI, posJ);
	QObject::connect(button, &QPushButton::clicked, this, &ChessWindow::buttonClicked);
	squares_.insert(std::pair(coords, button));

	return button;
}

void ChessWindow::buttonClicked()
{

	/*if (board_->isCheckMate(Color::BLACK))
		endGame();
	if (board_->isCheckMate(Color::WHITE))
		endGame();*/

	QPushButton* button = qobject_cast<QPushButton*>(sender());

	if (clickedPositions_.size() == 0 && button->text() != "") //Voir tour
	{
		for(auto&& square: squares_)
		{
			if (button == square.second)
			{
				clickedPositions_.push_back(square.first);
				board_->checkAllTiles(square.first);
				break;
			}
		}
	}
	else if(clickedPositions_.size() == 1 && button->palette().color(QPalette::Button) == Qt::green)
	{
		for (auto&& square : squares_)
		{
			if (button == square.second)
			{
				clickedPositions_.push_back(square.first);
				board_->moveLogic(clickedPositions_.at(0), clickedPositions_.at(1));
				break;
			}
		}

		resetBoard();
	}

	else if (clickedPositions_.size() == 1 && button->text() != "")
	{
		resetBoard();
	}
}

void graphicinterface::ChessWindow::displayPossibleMoves(std::vector<std::tuple<char, int>> possibleMoves)
{
	for(auto&& squaresPosition: possibleMoves)
	{
		auto button = squares_[squaresPosition];
		if(button != nullptr)
		{
			QPalette pal = button->palette();
			pal.setColor(QPalette::Button, Qt::green);
			button->setPalette(pal);
			button->setAutoFillBackground(true);
			button->update();
		}
	}
}

void graphicinterface::ChessWindow::displayPlayerTurn(Color color)
{
	QString colorStr;

	if (color == Color::WHITE)
		colorStr = "White";
	else
		colorStr = "Black";

	colorStr += "'s turn";

	colorTurnLabel_->setText(colorStr);
	colorTurnLabel_->update();
}

void graphicinterface::ChessWindow::connectButtonToTile()
{
	for (auto&& tile : board_->getTiles())
	{
		QObject::connect(tile, SIGNAL(tileTextModified(std::tuple<char, int>, std::string)), this, SLOT(addPiece(std::tuple<char, int>, std::string)));
	}

	QObject::connect(board_, SIGNAL(possibleMovesChanged(std::vector<std::tuple<char, int>>)), this, SLOT(displayPossibleMoves(std::vector<std::tuple<char, int>>)));
	QObject::connect(board_, SIGNAL(turnChanged(Color)), this, SLOT(displayPlayerTurn(Color)));
	QObject::connect(board_, SIGNAL(GameEnded()), this, SLOT(EndGameMessage()));
}

void ChessWindow::buttonNormalModeClicked()
{
	for (auto&& square : squares_)
	{
		square.second->setDisabled(false);
	}


	if(board_ != nullptr)
	{
		delete board_;
		resetBoard();
		clearBoard();
		updateBoard();
		delete colorTurnLabel_;
		addPlayersTurnLabel();
	}

	board_ = new gamelogic::Board();
	connectButtonToTile();
	
	board_->createPieces();
	board_->createKings();

	updateBoard();
}

void ChessWindow::buttonSpecialModeClicked()
{
	for (auto&& square : squares_)
	{
		square.second->setDisabled(false);
	}

	if (board_ != nullptr)
	{
		delete board_;
		resetBoard();
		clearBoard();
		updateBoard();

		delete colorTurnLabel_;
		addPlayersTurnLabel();
	}

	board_ = new gamelogic::Board();
	connectButtonToTile();

	board_->createSpecialSituation();

	updateBoard();
}

void graphicinterface::ChessWindow::EndGameMessage()
{
	QMessageBox* message = new QMessageBox();
	message->critical(this, "Won", "We have a winner!");

	for(auto&& square: squares_)
	{
		square.second->setDisabled(true);
	}
}

graphicinterface::ChessWindow::~ChessWindow()
{
	delete board_;
}




