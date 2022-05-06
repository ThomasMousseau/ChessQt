/*
* \file   King.h
* \author Matteo Colavita et Thomas Mousseau
* \date   25 avril 2022
* Créé le 20 avril 2022
*/

#pragma once
#include "Piece.h"
#include "TooManyKingsException.h"

class King : public Piece
{
public:
	King(Color);
	~King() override = default;
private:
	int nInstancesWhite_ = 0;
	int nInstancesBlack_ = 0;
};