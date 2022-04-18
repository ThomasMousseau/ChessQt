#include "Board.h"
#include "Rook.h"
#include "Bishop.h"
#include "King.h"


Board::Board()
{
	populateTiles();
	//createBishops();
	//createRooks();
	createKings();
}

void Board::createBishops()
{
	setPiece(make_tuple('c', 1), make_unique<Bishop>(WHITE));
	setPiece(make_tuple('f', 1), make_unique<Bishop>(WHITE));

	setPiece(make_tuple('c', 8), make_unique<Bishop>(BLACK));
	setPiece(make_tuple('f', 8), make_unique<Bishop>(BLACK));

}
void Board::createRooks()
{
	setPiece(make_tuple('h', 1), make_unique<Rook>(WHITE));
	setPiece(make_tuple('a', 1), make_unique<Rook>(WHITE));

	setPiece(make_tuple('h', 8), make_unique<Rook>(BLACK));
	setPiece(make_tuple('a', 8), make_unique<Rook>(BLACK));

}
void Board::createKings()
{
	setPiece(make_tuple('e', 8), make_unique<King>(BLACK));
	setPiece(make_tuple('e', 1), make_unique<King>(WHITE));
}

unique_ptr<Piece> Board::setPiece(const tuple<char, int>& position, unique_ptr<Piece> piece)
{
	return tiles[position]->setPiece(move(piece));
}

bool Board::isOnBoard(const tuple<char, int>& coords) const
{
	if (get<0>(coords) < 'a' || get<0>(coords) > 'h' || get<1>(coords) < 1 || get<1>(coords) > 8)
	{
		return false;
	}
	else
	{
		return true;
	}
}
//bool Board::isOccupied(const tuple<char, int>& coords) const
//{
//	return getPiece(coords) != nullptr;
//
//}
bool Board::isVerticalMove(const tuple<char, int>& position, const tuple<char, int>& nextPosition) const
{
	return get<1>(position) == get<1>(nextPosition);
}

bool Board::isHorizontalMove(const tuple<char, int>& position, const tuple<char, int>& nextPosition) const
{
	return get<0>(position) == get<0>(nextPosition);
}
bool Board::isDiagonalMove(const tuple<char, int>& position, const tuple<char, int>& nextPosition) const
{
	const int vertDis = abs(get<0>(position) - get<0>(nextPosition));
	const int horDis = abs(get<1>(position) - get<1>(nextPosition));

	return vertDis == horDis;
}
int Board::getMoveLength(const tuple<char, int>& position, const tuple<char, int>& nextPosition) const
{
	if (isVerticalMove(position, nextPosition))
	{
		return abs(get<0>(nextPosition) - get<0>(position));
	}
	else if (isHorizontalMove(position, nextPosition))
	{
		return abs(get<1>(nextPosition) - get<0>(position));
	}
	else if (isDiagonalMove(position, nextPosition))
	{
		return abs(get<0>(nextPosition) - get<0>(position));
	}
	else
	{
		return -10; //erreur s<il rentre dans le else
	}
}

bool Board::isKingMoveValid(const tuple<char, int>& position, const tuple<char, int>& nextPosition) const
{
	if (getMoveLength(position, nextPosition) == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Board::isBishopMoveValid(const tuple<char, int>& position, const tuple<char, int>& nextPosition) const
{
	if (isDiagonalMove(position, nextPosition))
		return true;
	return false;
}

void Board::populateTiles()
{
	/*Tile tile(i, j);
	scene->addWidget(tile.getButton());*/

	for(char i = 'a'; i <= 'h'; i++)
	{
		for( int j = 1; j <= 8; j++)
		{
			tuple<char,int> coords = make_tuple(i, j);
			unique_ptr<Tile> tile = make_unique<Tile>();
			tiles.insert(pair(coords, move(tile)));
		}
	}
}

bool Board::isRookMoveValid(const tuple<char, int>& position, const tuple<char, int>& nextPosition) const
{
	if (isVerticalMove(position, nextPosition))
		return true;
	return false;
}