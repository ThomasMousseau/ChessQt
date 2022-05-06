/*
* \file   Knight.h
* \author Matteo Colavita et Thomas Mousseau
* \date   25 avril 2022
* Créé le 20 avril 2022
*/

#include "Knight.h"

Knight::Knight(Color color) : Piece(Type::KNIGHT, color)
{
	if (color == Color::WHITE)
		pieceSymbol_ = "♘";
	else
		pieceSymbol_ = "♞";
}

