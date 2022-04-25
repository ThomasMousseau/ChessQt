/*
* \file   Queen.cpp
* \author Matteo Colavita et Thomas Mousseau
* \date   25 avril 2022
* Créé le 20 avril 2022
*/


#include "Queen.h"

Queen::Queen(Color color) : Piece(Type::QUEEN, color)
{
	if (color == Color::WHITE)
		pieceSymbol_ = "♕";
	else
		pieceSymbol_ = "♛";
}
