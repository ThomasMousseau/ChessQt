#pragma once

#include "Piece.h"
#include <memory>

class Tile
{
public:
	unique_ptr<Piece> setPiece(unique_ptr<Piece> piece);
private:
	unique_ptr<Piece> pieceOnTile;
};