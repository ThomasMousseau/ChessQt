#pragma once
#include "Piece.h"
class Queen :public Piece
{
public:
	Queen(Color);
	//bool isMoving(const Board board, tuple<char, int>& position, tuple<char, int>& nextPosition) const override; //a revoir la fonction
	~Queen() override = default;
private:
};

