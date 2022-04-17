#include "Rook.h"

Rook::Rook(Color color) : Piece(ROOK, color) {}

bool Rook::isMoving(const Board board, tuple<char, int>& position, tuple<char, int>& nextPosition) const
{
	if (board.isHorizontalMove(position, nextPosition))
		return true;
	return false;
}