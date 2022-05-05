/*
* \file   King.cpp
* \author Matteo Colavita et Thomas Mousseau
* \date   25 avril 2022
* Créé le 20 avril 2022
*/
#include "King.h"

King::King(Color color) : Piece(Type::KING, color)
{
	const bool condition = (nInstancesBlack_ == 1 && color == Color::BLACK) || (nInstancesWhite_ == 1 && color == Color::WHITE);

	if (condition)
	{
		throw TooManyKingsException("Too Many Kings on Board");
	}
	else if (color == Color::WHITE)
	{
		nInstancesWhite_++;
		pieceSymbol_ = "♔";
	}
	else if (color == Color::BLACK)
	{
		nInstancesBlack_++;
		pieceSymbol_ = "♚";
	}
}

std::vector<std::tuple<char, int>> King::movesAlgorithm(std::tuple<char, int> coords, Color pieceColor)
{
	std::vector<std::tuple<char, int>> possibleMovesVect;

	possibleMovesVect.emplace_back(get<0>(coords)+1, get<1>(coords));
	possibleMovesVect.emplace_back(get<0>(coords), get<1>(coords) +1);
	possibleMovesVect.emplace_back(get<0>(coords), get<1>(coords)-1);
	possibleMovesVect.emplace_back(get<0>(coords)-1, get<1>(coords));

	possibleMovesVect.emplace_back(get<0>(coords) + 1, get<1>(coords) + 1);
	possibleMovesVect.emplace_back(get<0>(coords) + 1, get<1>(coords) - 1);
	possibleMovesVect.emplace_back(get<0>(coords) - 1, get<1>(coords) - 1);
	possibleMovesVect.emplace_back(get<0>(coords) - 1, get<1>(coords) + 1);

	return possibleMovesVect;
}


