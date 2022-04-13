#pragma once
#include "Piece.h"

class Bishop : public Piece
{
public:
	Bishop(Color c);
	void move() override;
	~Bishop() override = default;
private:

};