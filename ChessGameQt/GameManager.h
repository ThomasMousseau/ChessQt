#pragma once

#include "Board.h"


class GameManager
{
public:
	void manage();
	bool move(std::tuple<char, int> position, std::tuple<char, int> nextPosition);
	bool isInCheck(Color defendingColor) const;
	bool isCheckMate(Color defendingColor) const;
	Color getTurn() const;

	// Utilities
	void printBoard();
	std::string printColor(Color color);

private:
	int moveNumber = 0;
	gamelogic::Board board; //je dois link le board d<une certaine facon

};

