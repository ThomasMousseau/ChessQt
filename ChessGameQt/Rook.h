#pragma once
#include "Piece.h"

class Rook : public Piece
{
public:
	Rook(Color c);
	bool isMoving(const Board board, tuple<char, int>& position, tuple<char, int>& nextPosition) const override;
	~Rook() override = default;
private:

};