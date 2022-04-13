#include <iostream>
#include <memory>
#include "Tile.h"

Piece* Tile::getPiece() const
{
	return pieceOnTile.get();
}

unique_ptr<Piece> Tile::setPiece(unique_ptr<Piece> piece)
{
	unique_ptr<Piece> movingTile = move(this->pieceOnTile);
	this->pieceOnTile = move(piece);
	return movingTile;
}