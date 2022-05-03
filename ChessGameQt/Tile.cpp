/*
* \file   Tile.cpp
* \author Matteo Colavita et Thomas Mousseau
* \date   25 avril 2022
* Créé le 20 avril 2022
*/
#include "Tile.h"

using namespace std;

Tile::Tile(int posI, int posJ)
{
	button_ = new QPushButton();
	const int tileSize = 100;
	button_->setGeometry(QRect(posI * tileSize, posJ * tileSize, tileSize, tileSize));
	QPalette pal = button_->palette();
	if ((posI + posJ) % 2)
		pal.setColor(QPalette::Button, Qt::gray);
	else
		pal.setColor(QPalette::Button, Qt::red);

	button_->setPalette(pal);
	button_->setAutoFillBackground(true);
	QFont font = button_->font();
	font.setPointSize(30);
	button_->setFont(font);
}

unique_ptr<Piece> Tile::setPiece(unique_ptr<Piece> piece)
{
	unique_ptr<Piece> movingTile = std::move(pieceOnTile_);
	modifyTextButton(piece.get()->getPieceSymbol());
	this->pieceOnTile_ = std::move(piece);
	return movingTile;
}
Piece* Tile::getPiece()
{
	unique_ptr<Piece> movingTile = std::move(pieceOnTile_);
	return movingTile.get();
}

void Tile::modifyTextButton(QString icon) const
{
	button_->setText(icon);
}

void Tile::buttonSelected()
{
	QPalette pal = button_->palette();
	pal.setColor(QPalette::Button, Qt::green);
	button_->setPalette(pal);
	button_->setAutoFillBackground(true);
	button_->update();
}

void Tile::movePiece(Tile& prochaineTile)
{
	this->pieceOnTile_ = move(prochaineTile.pieceOnTile_);
	prochaineTile.pieceOnTile_ = nullptr;

}
