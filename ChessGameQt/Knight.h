#pragma once
#include "Piece.h"
class Knight : public Piece
{
public:
	Knight(Color c);
	//bool isMoving(const Board board, tuple<char, int>& position, tuple<char, int>& nextPosition) const override;
	~Knight() override = default;
};

