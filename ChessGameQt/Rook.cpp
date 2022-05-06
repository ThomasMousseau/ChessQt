/*
* \file   Rook.cpp
* \author Matteo Colavita et Thomas Mousseau
* \date   25 avril 2022
* Créé le 20 avril 2022
*/
#include "Rooky.h"

Rook::Rook(Color color) : Piece(Type::ROOK, color)
{
	if (color == Color::WHITE)
		pieceSymbol_ = "♖";
	else
		pieceSymbol_ = "♜";
}
