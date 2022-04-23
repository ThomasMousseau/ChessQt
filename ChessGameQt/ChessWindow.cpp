#include "ChessWindow.h"

#include <QButtonGroup>


ChessWindow::ChessWindow(QWidget* parent) :
	QMainWindow(parent)
{
	
}

ChessWindow::ChessWindow(QGraphicsScene* scene, QWidget* parent) :
	QMainWindow(parent), board_(new Board(scene))
{
	scene_ = scene;

	vector<Tile*> tiles = board_->getTiles();
		
	for(auto&& tile: tiles)
	{
		scene_->addWidget(tile->getButton());
		connect(tile->getButton(), &QPushButton::clicked, this, &ChessWindow::buttonClicked);
	}
}

void ChessWindow::buttonClicked()
{
	for (auto&& tile : board_->getTiles())
	{
		if(tile->getButton() == qobject_cast<QPushButton*>(sender()))
		{
			tile_ = tile;
			break;
		}
	}

	tile_->buttonSelected();
}


