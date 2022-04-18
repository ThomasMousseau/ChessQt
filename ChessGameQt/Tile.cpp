#include "Tile.h"


//Piece* Tile::getPiece() const
//{
//	return pieceOnTile_.get();
//}
//



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
	unique_ptr<Piece> movingTile = move(this->pieceOnTile_);
	modifyTextButton(piece.get()->getPieceSymbol());
	this->pieceOnTile_ = move(piece);
	return movingTile;
}

void Tile::modifyTextButton(QString icon)
{
	button_->setText(icon);
}
