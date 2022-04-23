#pragma once
#include <map>
#include <memory>
#include <vector>
#include <tuple>
#include <QGraphicsScene>

#include "Rook.h"
#include "Bishop.h"
#include "King.h"
#include "Pawn.h"
#include <Knight.h>
#include "Queen.h"

#include "Tile.h"

using namespace std;

//class Piece;
//class Tile;


class Board {

public:
	//Board(){};
	Board(QGraphicsScene* scene);

	vector<Tile*> getTiles();

	//unique_ptr<Tile> getPiece(const tuple<char, int>& position) const;

	bool isOnBoard(const tuple<char, int>& position) const;
	bool isOccupied(const tuple<char, int>& position) const;
	bool isKnightMove(const tuple<char, int>& position, const tuple<char, int>& nextPosition) const;
	bool isVerticalMove(const tuple<char, int>& position, const tuple<char, int>& nextPosition) const;
	bool isHorizontalMove(const tuple<char, int>& position, const tuple<char, int>& nextPosition) const;
	bool isDiagonalMove(const tuple<char, int>& position, const tuple<char, int>& nextPosition) const;
	int getMoveLength(const tuple<char, int>& position, const tuple<char, int>& nextPosition) const;
	unique_ptr<Piece> setPiece(const tuple<char, int>& position, unique_ptr<Piece> piece);

	//set of moves for all pieces
	bool isKingMoveValid(const tuple<char, int>& position, const tuple<char, int>& nextPosition) const;
	bool isRookMoveValid(const tuple<char, int>& position, const tuple<char, int>& nextPosition) const;
	bool isBishopMoveValid(const tuple<char, int>& position, const tuple<char, int>& nextPosition) const;

	void populateTiles();
	void createBishops();
	void createRooks();
	void createKings();
	void createQueens();
	void createPawns();
	void createKnights();
private:
	map<tuple<char, int>, unique_ptr<Tile>> tiles;
	QGraphicsScene* scene_{};

	
};