#include "King.h"

King::King(Color color) : Piece(KING, color)
{
	if(color = WHITE)
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


