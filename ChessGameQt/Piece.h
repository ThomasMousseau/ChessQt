#pragma once
#include <tuple>
//#include "Board.h"

using namespace std;

enum Type
{
	KING,
	PAWN,
	KNIGHT,
	ROOK,
	QUEEN,
	BISHOP
	
};

enum Color
{
	BLACK,
	WHITE
	
};

class Piece {

public:
	Piece(Type, Color);
	virtual ~Piece() = default;
	//virtual bool isMoving(const Board board, tuple<char, int>& position, tuple<char, int>& nextPosition) const;

	Type getType() const { return type_; }
	Color getColor() const { return color_; }

protected:
	Type type_;
	Color color_;
	tuple<char, int> position_;

};

