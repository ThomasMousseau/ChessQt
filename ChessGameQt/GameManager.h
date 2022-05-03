#pragma once

#include "Board.h"


class GameManager
{
public:
	void manage();
	bool move(std::tuple<char, int> position, std::tuple<char, int> nextPosition);
	bool isCheck(Color defendingColor) const;
	bool isCheckMate(Color defendingColor);
	Color getTurn() const;

	// Utilities
	void printBoard();
	std::string printColor(Color color);

private:
	int moveNumber = 0;
	gamelogic::Board board;

};

