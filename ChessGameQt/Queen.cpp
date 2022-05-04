/*
* \file   Queen.cpp
* \author Matteo Colavita et Thomas Mousseau
* \date   25 avril 2022
* Créé le 20 avril 2022
*/


#include "Queen.h"

Queen::Queen(Color color) : Piece(Type::QUEEN, color)
{
	if (color == Color::WHITE)
		pieceSymbol_ = "♕";
	else
		pieceSymbol_ = "♛";
}

std::vector<std::tuple<char, int>> Queen::movesAlgorithm(std::tuple<char, int> currPos, Color pieceColor)
{
	std::vector<std::tuple<char, int>> possibleMovesVect;

	switch(pieceColor)
	{
	case Color::BLACK:
		break;

	case Color::WHITE:
		break;

	default:
		break;
	}

	for(char i = 'a'; i <= 'h'; i++)
	{
		for (int j = 1; j <= 8; j++)
		{
			possibleMovesVect.emplace_back(i, j);
		}
	}

	return possibleMovesVect;
}
