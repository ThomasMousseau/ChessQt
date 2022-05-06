/*
* \file   Queen.h
* \author Matteo Colavita et Thomas Mousseau
* \date   25 avril 2022
* Créé le 20 avril 2022
*/

#pragma once
#include "Piece.h"

class Queen :public Piece
{
public:
	Queen(Color);
	~Queen() override = default;
};

