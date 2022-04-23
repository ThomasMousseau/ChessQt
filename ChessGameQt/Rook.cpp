#include "Rook.h"

Rook::Rook(Color color) : Piece(ROOK, color)
{
	if (color == WHITE)
		pieceSymbol_ = "♖";
	else
		pieceSymbol_ = "♜";
}
