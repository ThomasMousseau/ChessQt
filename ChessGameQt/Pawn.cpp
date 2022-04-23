#include "Pawn.h"

Pawn::Pawn(Color color): Piece(PAWN, color)
{
	if(color == WHITE)
		pieceSymbol_ = "♙";
	else
		pieceSymbol_ = "♟";
}
