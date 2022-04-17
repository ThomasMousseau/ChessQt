#pragma once
#include "Piece.h"

class Bishop : public Piece
{
public:
	Bishop(Color c);
	bool isMoving(const Board board, tuple<char, int>& position, tuple<char, int>& nextPosition) const override;
	~Bishop() override = default;
private:

};