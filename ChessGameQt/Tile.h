#pragma once

#include "Piece.h"
#include <memory>
#include <iostream>
#include <QPushButton>
#include <QString>

class Tile
{
public:
	Tile() {};
	Tile(int posI, int posJ);
	QPushButton* getButton() { return button_; }
	unique_ptr<Piece> setPiece(unique_ptr<Piece> piece);
	void modifyTextButton(QString icon);
private:
	unique_ptr<Piece> pieceOnTile_ = nullptr;
	QPushButton* button_;
};
