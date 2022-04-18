#pragma once
#include "Piece.h"

class King : public Piece
{
public:
	King(Color);
	//bool isMoving(const Board board, tuple<char, int>& position, tuple<char, int>& nextPosition) const override; //a revoir la fonction
	~King() override = default;
private:
};