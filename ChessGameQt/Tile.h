#pragma once

#include "Piece.h"
#include <memory>

class Tile
{
public:

private:
	unique_ptr<Piece> pieceOnTile;
};