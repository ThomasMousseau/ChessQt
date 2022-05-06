/*
* \file   Pawn.h
* \author Matteo Colavita et Thomas Mousseau
* \date   25 avril 2022
* Créé le 20 avril 2022
*/

#pragma once
#include "Piece.h"

class Pawn: public Piece
{
public:
	Pawn(Color);
	~Pawn() override = default;
private:
};

