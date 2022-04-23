#include "King.h"

int King::nInstancesWhite_ = 0;
int King::nInstancesBlack_ = 0;


King::King(Color color) : Piece(KING, color)
{
	const bool condition = (nInstancesBlack_ == 1 && color == BLACK) || (nInstancesWhite_ == 1 && color == WHITE);

	if (condition)
	{
		throw TooManyKingsException("Too Many Kings on Board");
	}
	else if (color == WHITE)
	{
		nInstancesWhite_++;
		pieceSymbol_ = "♔";
	}
	else if (color == BLACK)
	{
		nInstancesBlack_++;
		pieceSymbol_ = "♚";
	}
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


