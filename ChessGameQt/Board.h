#pragma once
#include <map>
#include <memory>
#include <vector>
#include <tuple>

#include "Tile.h"

using namespace std;

//class Piece;
//class Tile;


class Board {
public:
	Board();

	void printBoard();
	Piece* getPiece(const tuple<char, int>& position) const;

	bool isOnBoard(const tuple<char, int>& position) const;
	bool isOccupied(const tuple<char, int>& position) const;
	bool isKnightMove(const tuple<char, int>& position, const tuple<char, int>& nextPosition) const;
	bool isVerticalMove(const tuple<char, int>& position, const tuple<char, int>& nextPosition) const;
	bool isHorizontalMove(const tuple<char, int>& position, const tuple<char, int>& nextPosition) const;
	bool isDiagonalMove(const tuple<char, int>& position, const tuple<char, int>& nextPosition) const;
	int getMoveLength(const tuple<char, int>& position, const tuple<char, int>& nextPosition) const;
	unique_ptr<Piece> setPiece(const tuple<char, int>& position, unique_ptr<Piece> piece);


private:

	map<tuple<char, int>, unique_ptr<Tile>> tiles;

	void createBishops();
	void createRooks();
	void createKings();
};