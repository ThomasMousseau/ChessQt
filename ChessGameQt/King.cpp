#include "King.h"

int King::nInstances_ = 0;

King::King(Color color) : Piece(KING, color)
{
	nInstances_++;
	if(color == WHITE)
		pieceSymbol_ = "♔";
	else
		pieceSymbol_ = "♚";
	
}

//bool King::isMoving(const Board board, tuple<char, int>& position, tuple<char, int>& nextPosition) const
//{
//	if (board.getMoveLength(position, nextPosition) == 1)
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}


