#include "GameManager.h"


void GameManager::manage()
{
	while(true)
	{
		if (isCheckMate(getTurn()))
			break;

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

bool GameManager::isCheckMate(Color defendingColor)
{
	return true; //idk yet
}






