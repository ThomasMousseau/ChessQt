﻿/*
* \file   ChessWindow.cpp
* \author Matteo Colavita et Thomas Mousseau
* \date   25 avril 2022
* Créé le 20 avril 2022
*/

#include "ChessWindow.h"

using namespace graphicinterface;

ChessWindow::ChessWindow(QWidget* parent) :
	QMainWindow(parent)
{

}

ChessWindow::ChessWindow(QGraphicsScene* scene, QWidget* parent) : QMainWindow(parent)
{
	try
	{
		board_ = std::make_shared<gamelogic::Board>(scene);
		board_->createKings();
	}
	catch (TooManyKingsException& e)
	{
		QMessageBox messageBox;
		messageBox.critical(this, "QTERROR", e.what());
	}
	
	scene_ = scene;
	std::vector<Tile*> tiles = board_->getTiles();

	for (auto&& tile : tiles)
	{
		scene_->addWidget(tile->getButton());
		connect(tile->getButton(), &QPushButton::clicked, this, &ChessWindow::buttonClicked);
	}
}

void ChessWindow::buttonClicked()
{
	for (auto&& tile : board_->getTiles())
	{
		if (tile->getButton() == qobject_cast<QPushButton*>(sender()))
		{
			tile_ = tile;
			break;
		}
	}

	QPalette pal = tile_->getButton()->palette();
	pal.setColor(QPalette::Button, Qt::green);
	tile_->getButton()->setPalette(pal);
	tile_->getButton()->setAutoFillBackground(true);
	tile_->getButton()->update();
}


