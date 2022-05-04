/*
* \file   Knight.h
* \author Matteo Colavita et Thomas Mousseau
* \date   25 avril 2022
* Créé le 20 avril 2022
*/

#pragma once
#include "Piece.h"
class Knight : public Piece
{
public:
	Knight(Color c);
	~Knight() override = default;
	std::vector<std::tuple<char, int>> movesAlgorithm(std::tuple<char, int>, Color) override;
};

