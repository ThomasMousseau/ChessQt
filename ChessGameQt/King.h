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
	static int nInstancesWhite_;
	static int nInstancesBlack_;
};