/*
* \file   Rook.cpp
* \author Matteo Colavita et Thomas Mousseau
* \date   25 avril 2022
* Créé le 20 avril 2022
*/
#include "Rook.h"

Rook::Rook(Color color) : Piece(Type::ROOK, color)
{
	if (color == Color::WHITE)
		pieceSymbol_ = "♖";
	else
		pieceSymbol_ = "♜";
}

std::vector<std::tuple<char, int>> Rook::movesAlgorithm(std::tuple<char, int> coords, Color color)
{
	std::vector<std::tuple<char, int>> possibleMovesVect;

	for (int i = 1; i <= 8; i++)
	{
		possibleMovesVect.emplace_back(get<0>(coords), i);
	}

	for (char i = 'a'; i <= 'h'; i++)
	{
		possibleMovesVect.emplace_back(i, get<1>(coords));
	}

	return possibleMovesVect;
}
