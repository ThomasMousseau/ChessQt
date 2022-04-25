/*
* \file   Pawn.cpp
* \author Matteo Colavita et Thomas Mousseau
* \date   25 avril 2022
* Créé le 20 avril 2022
*/
#include "Pawn.h"

Pawn::Pawn(Color color): Piece(Type::PAWN, color)
{
	if(color == Color::WHITE)
		pieceSymbol_ = "♙";
	else
		pieceSymbol_ = "♟";
}
