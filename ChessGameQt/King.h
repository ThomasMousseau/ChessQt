#pragma once
#include "Piece.h"

class King : public Piece
{
public:
	King(Color);
	void move() override; //a revoir la fonction
	~King() override = default;
private:
};