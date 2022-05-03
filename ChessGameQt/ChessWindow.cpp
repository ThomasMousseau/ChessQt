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
	QPalette pal = button->palette();
	pal.setColor(QPalette::Button, Qt::green);
	button->setPalette(pal);
	button->setAutoFillBackground(true);
	button->update();

	for(auto&& square: squares_)
	{
		if (button == square.second)
		{
			emit tileSelected(square.first);
		}
	}
}


