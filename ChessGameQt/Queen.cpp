#include "Queen.h"

Queen::Queen(Color color) : Piece(QUEEN, color)
{
	if (color == WHITE)
		pieceSymbol_ = "♕";
	else
		pieceSymbol_ = "♛";
}
