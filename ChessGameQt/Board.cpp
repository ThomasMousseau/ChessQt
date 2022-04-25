/**
* \file   Board.cpp
* \author Matteo Colavita et Thomas Mousseau
* \date   25 avril 2022
* Créé le 20 avril 2022
*/


#include "Board.h"


using namespace gamelogic;
using namespace std;

Board::Board(QGraphicsScene* scene) : scene_(scene)
{
	populateTiles();
	createBishops();
	createRooks();
	createPawns();
	createKnights(); 
	createQueens();
}

vector<Tile*> Board::getTiles()
{
	vector<Tile*> tileVect;

	for (auto&& tile : tiles)
		tileVect.push_back(move(tile.second.get()));

	return tileVect;
}

void Board::createBishops()
{
	setPiece(make_tuple('c', 1), make_unique<Bishop>(Color::WHITE));
	setPiece(make_tuple('f', 1), make_unique<Bishop>(Color::WHITE));

	setPiece(make_tuple('c', 8), make_unique<Bishop>(Color::BLACK));
	setPiece(make_tuple('f', 8), make_unique<Bishop>(Color::BLACK));

}
void Board::createRooks()
{
	setPiece(make_tuple('h', 1), make_unique<Rook>(Color::WHITE));
	setPiece(make_tuple('a', 1), make_unique<Rook>(Color::WHITE));

	setPiece(make_tuple('h', 8), make_unique<Rook>(Color::BLACK));
	setPiece(make_tuple('a', 8), make_unique<Rook>(Color::BLACK));

}
void Board::createKings()
{
	setPiece(make_tuple('e', 8), make_unique<King>(Color::BLACK));
	setPiece(make_tuple('e', 1), make_unique<King>(Color::WHITE));
	setPiece(make_tuple('g', 5), make_unique<King>(Color::WHITE)); //Exemple Exception trigger
}

void Board::createPawns()
{
	for (char i = 'a'; i <= 'h'; i++)
	{
		setPiece(make_tuple(i, 2), make_unique<Pawn>(Color::WHITE));
		setPiece(make_tuple(i, 7), make_unique<Pawn>(Color::BLACK));
	}
}

void Board::createKnights()
{
	setPiece(make_tuple('b', 1), make_unique<Knight>(Color::WHITE));
	setPiece(make_tuple('g', 1), make_unique<Knight>(Color::WHITE));

	setPiece(make_tuple('b', 8), make_unique<Knight>(Color::BLACK));
	setPiece(make_tuple('g', 8), make_unique<Knight>(Color::BLACK));
}

void Board::createQueens()
{
	setPiece(make_tuple('d', 8), make_unique<Queen>(Color::BLACK));
	setPiece(make_tuple('d', 1), make_unique<Queen>(Color::WHITE));
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
		return -10;
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
	for(char i = 'a'; i <= 'h'; i++)
	{
		for( int j = 1; j <= 8; j++)
		{
			tuple<char,int> coords = make_tuple(i, j);
			unique_ptr<Tile> tile = make_unique<Tile>(i, j);
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