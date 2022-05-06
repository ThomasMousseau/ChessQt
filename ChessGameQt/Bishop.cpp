/**
* \file   Bishop.cpp
* \author Matteo Colavita et Thomas Mousseau
* \date   25 avril 2022
* Créé le 20 avril 2022
*/

#include "Bishop.h"

Bishop::Bishop(Color color) : Piece(Type::BISHOP, color)
{
	if (color == Color::WHITE)
		pieceSymbol_ = "♗";
	else
		pieceSymbol_ = "♝";
}



