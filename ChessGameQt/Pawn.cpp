/*
* \file   Pawn.cpp
* \author Matteo Colavita et Thomas Mousseau
* \date   25 avril 2022
* Créé le 20 avril 2022
*/
#include "Pawn.h"

Pawn::Pawn(Color color): Piece(Type::PAWN, color)
{
	if(color == Color::WHITE)
		pieceSymbol_ = "♙";
	else
		pieceSymbol_ = "♟";
}

std::vector<std::tuple<char, int>> Pawn::movesAlgorithm(std::tuple<char, int> coords, Color color)
{
	std::vector<std::tuple<char, int>> possibleMovesVect;

	switch(color)
	{
	case Color::BLACK:

		if (nTimeMoved == 0)
		{
			for (int i = get<1>(coords); i >= (get<1>(coords)-2); i--)
			{
				possibleMovesVect.emplace_back(get<0>(coords), i);
			}
		}
		else if(get<1>(coords)-- >= 1) //a tester
		{
			possibleMovesVect.emplace_back(get<0>(coords), get<1>(coords)--);
		}
			

		break;

	case Color::WHITE:

		if(nTimeMoved == 0)
		{
			for (int i = get<1>(coords); i <= (get<1>(coords) + 2); i++)
			{
				possibleMovesVect.emplace_back(get<0>(coords), i);
			}
		}
		else
			possibleMovesVect.emplace_back(get<0>(coords), get<1>(coords)++);
		
		break;

	default:
		break;
	}
	
	return possibleMovesVect;
}
