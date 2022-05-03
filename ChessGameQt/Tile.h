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

class Tile: public QObject
{
	Q_OBJECT
public:
	Tile(std::tuple<char, int> coords);
	std::unique_ptr<Piece> setPiece(std::unique_ptr<Piece> piece);

signals:
	void tileTextModified(std::tuple<char, int>, std::string);

private:
	std::unique_ptr<Piece> pieceOnTile_ = nullptr;
	std::tuple<char, int> position_;
};
