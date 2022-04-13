#include <memory>
#include "Piece.h"

using namespace std;

class Tile
{
public:
	Piece* getPiece() const;
	unique_ptr<Piece> setPiece(unique_ptr<Piece> piece);
protected:
	unique_ptr<Piece> pieceOnTile;
};
