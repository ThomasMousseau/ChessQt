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

std::vector<std::tuple<char, int>> Bishop::movesAlgorithm(std::tuple<char, int> coords, Color color)
{

	std::vector<std::tuple<char, int>> possibleMovesVect;

	int pos = std::get<1>(coords) % 2;

	switch (color)
	{
	case Color::BLACK:

		

		break;

	case Color::WHITE:


		break;

	default:
		break;
	}

	return possibleMovesVect;
}


