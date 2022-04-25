/*
* \file   Tile.h
* \author Matteo Colavita et Thomas Mousseau
* \date   25 avril 2022
* Créé le 20 avril 2022
*/
#pragma once
#include "Piece.h"
#include <memory>
#include <QPushButton>

class Tile
{
public:
	Tile(int posI, int posJ);
	QPushButton* getButton() const { return button_; }
	std::unique_ptr<Piece> setPiece(std::unique_ptr<Piece> piece);
	void modifyTextButton(QString icon) const;
	void buttonSelected();
private:
	std::unique_ptr<Piece> pieceOnTile_ = nullptr;
	QPushButton* button_;
};
