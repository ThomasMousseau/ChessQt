#include "Tile.h"


//Piece* Tile::getPiece() const
//{
//	return pieceOnTile_.get();
//}
//

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

void Tile::modifyTextButton(QString icon) const
{
	button_->setText(icon);
}

void Tile::buttonSelected()
{
	QPalette pal = button_->palette();
	pal.setColor(QPalette::Button, Qt::green);
	button_->setPalette(pal);
	//button_->setFlat(true);
	button_->setAutoFillBackground(true);
	button_->update();
}
