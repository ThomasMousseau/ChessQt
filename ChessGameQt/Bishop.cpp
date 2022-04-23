#include "Bishop.h"

Bishop::Bishop(Color color) : Piece(BISHOP, color)
{
	if (color == WHITE)
		pieceSymbol_ = "♗";
	else
		pieceSymbol_ = "♝";
}


