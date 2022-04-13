#pragma once
#include <tuple>
using namespace std;

enum Type
{
	PAWN,
	KNIGHT,
	BISHOP,
	ROOK,
	QUEEN,
	KING
};

enum Color
{
	WHITE,
	BLACK
};

class Piece {

public:
	Piece(Type, Color);
	virtual ~Piece() = default;
	virtual void move();

	Type getType() const { return type_; }
	Color getColor() const { return color_; }

protected:
	Type type_;
	Color color_;
	tuple<char, int> position_;

};