/*
* \file   Tile.cpp
* \author Matteo Colavita et Thomas Mousseau
* \date   25 avril 2022
* Créé le 20 avril 2022
*/
#include "Tile.h"

using namespace std;

Tile::Tile(tuple<char, int> coords) : position_(coords)
{
}

unique_ptr<Piece> Tile::setPiece(unique_ptr<Piece> piece)
{
	unique_ptr<Piece> movingTile = std::move(pieceOnTile_);
	this->pieceOnTile_ = std::move(piece);
	emit tileTextModified(position_, pieceOnTile_->getPieceSymbol());
	return movingTile;
}
