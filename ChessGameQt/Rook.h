#pragma once
#include "Piece.h"

class Rook : public Piece
{
public:
	Rook(Color c);
	void move() override;
	~Rook() override = default;
private:

};