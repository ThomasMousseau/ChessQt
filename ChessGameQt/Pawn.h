#pragma once
#include "Piece.h"

class Pawn: public Piece
{
public:
	Pawn(Color);
	//bool isMoving(const Board board, tuple<char, int>& position, tuple<char, int>& nextPosition) const override;
	~Pawn() override = default;
private:

};

