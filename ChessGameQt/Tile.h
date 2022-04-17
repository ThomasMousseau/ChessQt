#ifndef TILE_H
#define TILE_H

#include <memory>
#include "Piece.h"

using namespace std;

class Tile
{
public:
	//peut-etre que son constrcuteur sera le lien entre le UI et le code
	Piece* getPiece() const;
	unique_ptr<Piece> setPiece(unique_ptr<Piece> piece);
private:
	unique_ptr<Piece> pieceOnTile;
};

#endif