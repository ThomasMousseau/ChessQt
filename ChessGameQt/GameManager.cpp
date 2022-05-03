#include "GameManager.h"


void GameManager::manage()
{
	while(true)
	{
		if (isCheckMate(getTurn()))
			break;

		//check Input 

	}
}

bool GameManager::move(std::tuple<char, int> position, std::tuple<char, int> nextPosition)
{
	return false;
}

Color GameManager::getTurn() const
{
	if (this->moveNumber % 2 == 0)
		return Color::WHITE;
	return Color::BLACK;
}

bool GameManager::isCheckMate(Color defendingColor) const
{
	if (isInCheck(defendingColor))
	{
		return true; //je dois continuer cette fonction
	}
}


bool GameManager::isInCheck(Color defendingColor) const
{
	Color attackingColor;
	if (defendingColor == Color::WHITE)
		attackingColor = Color::BLACK;
	else
		attackingColor = Color::WHITE;

	std::tuple<char, int> kingPosition = board.getKingLocation(defendingColor);
	std::vector<std::tuple<char, int>> piecesPosition = board.getPieceLocations(attackingColor);

	for (auto attackingPiece : piecesPosition)
	{
		if (board.isValidMove(attackingPiece, kingPosition))
			return true;
	}

	return false;
}





