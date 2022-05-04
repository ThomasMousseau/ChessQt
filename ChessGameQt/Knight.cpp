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

std::vector<std::tuple<char, int>> Knight::movesAlgorithm(std::tuple<char, int> coords, Color color)
{
	std::vector<std::tuple<char, int>> possibleMovesVect;

	switch (color)
	{
	case Color::BLACK:

		possibleMovesVect.emplace_back(get<0>(coords) + 1, (get<1>(coords) - 2));
		possibleMovesVect.emplace_back(get<0>(coords) - 1, (get<1>(coords) - 2));

		break;

	case Color::WHITE:

		possibleMovesVect.emplace_back(get<0>(coords) + 1, (get<1>(coords) + 2));
		possibleMovesVect.emplace_back(get<0>(coords) - 1, (get<1>(coords) + 2));

		break;

	default:
		break;
	}

	return possibleMovesVect;
}
