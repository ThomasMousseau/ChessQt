#pragma once

#include "Piece.h"
#include <memory>
#include <iostream>
#include <QPushButton>
#include <QString>

class Tile
{
public:
	//Tile() {};
	Tile(int posI, int posJ);
	QPushButton* getButton() const { return button_; }
	std::unique_ptr<Piece> setPiece(std::unique_ptr<Piece> piece);
	void modifyTextButton(QString icon) const;
	void buttonSelected();
private:
	std::unique_ptr<Piece> pieceOnTile_ = nullptr;
	QPushButton* button_;
};
