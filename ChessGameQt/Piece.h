/*
* \file   Piece.h
* \author Matteo Colavita et Thomas Mousseau
* \date   25 avril 2022
* Créé le 20 avril 2022
*/

#pragma once
#include <QString>
#include <tuple>

enum class Type
{
	KING,
	PAWN,
	KNIGHT,
	ROOK,
	QUEEN,
	BISHOP
	
};

enum class Color
{
	BLACK,
	WHITE
	
};

class Piece {

public:
	Piece() {};
	Piece(Type, Color);
	virtual ~Piece() = default;

	Type getType() const { return type_; }
	Color getColor() const { return color_; }
	Color getOppsiteColor() const
	{
		if (color_ == Color::BLACK)
			return Color::WHITE;
		return Color::BLACK;
	}
	std::string getPieceSymbol() const { return pieceSymbol_; }
	int getNTimesMoved() const { return nTimeMoved; }
	void incrementNTimeMoves() { nTimeMoved++; }

protected:
	Type type_;
	Color color_;
	std::tuple<char, int> position_;
	std::string pieceSymbol_;
	int nTimeMoved = 0;
};

