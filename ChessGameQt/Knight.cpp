#include "Knight.h"

Knight::Knight(Color color) : Piece(KNIGHT, color)
{
	if (color == WHITE)
		pieceSymbol_ = "♘";
	else
		pieceSymbol_ = "♞";
}
