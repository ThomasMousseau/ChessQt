#pragma once

/*
* \file   Rooky.h
* \author Matteo Colavita et Thomas Mousseau
* \date   25 avril 2022
* Créé le 20 avril 2022
*/

#pragma once
#include "Piece.h"

class Rook : public Piece
{
public:
	Rook(Color c);
	~Rook() override = default;
};
