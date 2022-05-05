#pragma once

#include "Board.h"


class GameManager
{
public:
	GameManager(gamelogic::Board board);
	void manage();
	bool move(std::tuple<char, int> position, std::tuple<char, int> nextPosition);
	bool isInCheck(Color defendingColor) const;
	bool isCheckMate(Color defendingColor) const;
	//Color getTurn() const;
	gamelogic::Board& getBoard() { return board_; }
	

	void printBoard();
	std::string printColor(Color color);

private:
	gamelogic::Board& board_; 

};

