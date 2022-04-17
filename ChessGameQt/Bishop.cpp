#include "Bishop.h"

Bishop::Bishop(Color color) : Piece(BISHOP, color) {}


bool Bishop::isMoving(const Board board, tuple<char, int>& position, tuple<char, int>& nextPosition) const
{
	if (board.isDiagonalMove(position, nextPosition))
		return true;
	return false;
}
