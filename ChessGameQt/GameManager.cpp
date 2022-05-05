#include "GameManager.h"


GameManager::GameManager(gamelogic::Board board) : board_(board)
{
}


void GameManager::manage()
{
	/*while(true)
	{
		if (isCheckMate(getTurn()))
			break;

	}*/
}

bool GameManager::move(std::tuple<char, int> position, std::tuple<char, int> nextPosition)
{
	return false;
}

//Color GameManager::getTurn() const
//{
//	if (board_.getMoveNumber() % 2 == 0)
//		return Color::WHITE;
//	return Color::BLACK;
//}

bool GameManager::isCheckMate(Color defendingColor) const
{
	if (isInCheck(defendingColor))
	{
		//regarde les position possible du king
		//regarde si ses postions sont atteinable par une des pieces adverse
		//si aucune possibilit return true
		//sinon show les possibilite restante du king
	}
}


bool GameManager::isInCheck(Color defendingColor) const
{
	Color attackingColor;
	if (defendingColor == Color::WHITE)
		attackingColor = Color::BLACK;
	else
		attackingColor = Color::WHITE;

	std::tuple<char, int> kingPosition = board_.getKingLocation(defendingColor);
	std::vector<std::tuple<char, int>> piecesPosition = board_.getPieceLocations(attackingColor);

	for (auto attackingPiece : piecesPosition)
	{
		if (board_.isValidMove(attackingPiece, kingPosition))
			return true;
	}

	return false;
}





