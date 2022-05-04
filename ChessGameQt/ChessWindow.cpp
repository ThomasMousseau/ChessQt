/*
* \file   ChessWindow.cpp
* \author Matteo Colavita et Thomas Mousseau
* \date   25 avril 2022
* Créé le 20 avril 2022
*/

#include "ChessWindow.h"

#include "Raii.h"

using namespace graphicinterface;

ChessWindow::ChessWindow(QWidget* parent) :
	QMainWindow(parent)
{

}

ChessWindow::ChessWindow(QGraphicsScene* scene, QWidget* parent) : QMainWindow(parent)
{
	scene_ = scene;
	populateBoard();
}

void graphicinterface::ChessWindow::resetBoard()
{
	clickedPositions.clear();

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

void graphicinterface::ChessWindow::addPiece(std::tuple<char, int> coords, std::string symbol)
{
	squares_[coords]->setText(QString::fromStdString(symbol));
}

void graphicinterface::ChessWindow::populateBoard()
{
	for (char i = 'a'; i <= 'h'; i++)
	{
		for (int j = 1; j <= 8; j++)
		{
			scene_->addWidget(addButton(i, j));
		}
	}
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
	QPushButton* button = qobject_cast<QPushButton*>(sender());

	if (clickedPositions.size() == 0 && button->text() != "") //Voir tour
	{
		for(auto&& square: squares_)
		{
			if (button == square.second)
			{
				clickedPositions.push_back(square.first);
				emit tileSelected(square.first);
				break;
			}
		}
	}
	else if(clickedPositions.size() == 1 && button->palette().color(QPalette::Button) == Qt::green)
	{
		for (auto&& square : squares_)
		{
			if (button == square.second)
			{
				clickedPositions.push_back(square.first);
				emit secondClick(clickedPositions.at(0), clickedPositions.at(1));
				break;
			}
		}

		resetBoard();
	}

	else if (clickedPositions.size() == 1 && button->text() != "")
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




