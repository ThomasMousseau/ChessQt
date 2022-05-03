/**
* \file   Board.cpp
* \author Matteo Colavita et Thomas Mousseau
* \date   25 avril 2022
* Créé le 20 avril 2022
*/


#include "Board.h"


using namespace gamelogic;
using namespace std;

int Board::ConvertCharToInt(char c)
{
	switch (c)
	{
		case 'a' : return 1;
		case 'b': return 2;
		case 'c': return 3;
		case 'd': return 4;
		case 'e': return 5;
		case 'f': return 6;
		case 'g': return 7;
		case 'h': return 8;
	}
}

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
void Board::movePiece(const std::tuple<char, int>& position, const std::tuple<char, int>& nextPosition)
{
	tiles[nextPosition]->movePiece(*tiles[nextPosition].get()); //JSP si cette ligne va fonctionner

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

bool Board::isOccupied(const tuple<char, int>& coords) const
{
	return getPiece(coords) != nullptr;

}

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
		return abs(get<1>(nextPosition) - get<1>(position));
	}
	else if (isDiagonalMove(position, nextPosition))
	{
		return abs(get<0>(nextPosition) - get<0>(position)); 
	}
	else
	{
		return -1;
	}
}

bool Board::isKingMoveValid(const tuple<char, int>& position, const tuple<char, int>& nextPosition) const
{
	if (getMoveLength(position, nextPosition) == 1)
		return true;
	else
		return false;
}

bool Board::isBishopMoveValid(const tuple<char, int>& position, const tuple<char, int>& nextPosition) const
{
	if (isDiagonalMove(position, nextPosition))
		if (isPathValid(position, nextPosition))
			return true;
}

bool Board::isPathValid(const tuple<char, int>& position, const tuple<char, int>& nextPosition) const
{

	int composantVecteurVer = (get<0>(nextPosition) - get<0>(position));
	int composantVecteurHor = (get<1>(nextPosition) - get<1>(position));

	if (composantVecteurVer != 0)
		composantVecteurVer /= abs(composantVecteurVer);
	if (composantVecteurHor != 0)
		composantVecteurHor /= abs(composantVecteurHor);

	auto posActuel = position;
	bool isAtFinalTile;
	do
	{
		get<0>(posActuel) =+ composantVecteurVer; 
		get<1>(posActuel) =+ composantVecteurHor;

		isAtFinalTile = get<0>(posActuel) != get<0>(nextPosition) && get<1>(posActuel) != get<1>(nextPosition);

		if(isAtFinalTile)
		{
			if (!isOccupiedDifferentColor(position,posActuel))
				return false;
		}
		else
		{
			if (isOccupied(posActuel))
				return false;
		}

	} while (!isAtFinalTile);

	return true;
}

bool Board::isQueenMoveValid(const tuple<char, int>& position, const tuple<char, int>& nextPosition) const
{
	if (isVerticalMove(position, nextPosition) || isHorizontalMove(position, nextPosition))
		if (isPathValid(position, nextPosition))
			return true;

	 if (isDiagonalMove(position, nextPosition))
		if (isPathValid(position, nextPosition))
			return true;

	return false;
}

bool Board::isForwardMove(const tuple<char, int>& position, const tuple<char, int>& nextPosition) const
{
	return true; //TODO A FAIRE CETTE FONCTION

}

Piece* Board::getPiece(const std::tuple<char, int>& position) const
{
	return tiles.find(position)->second->getPiece();
}

bool Board::isOccupiedDifferentColor(const tuple<char, int>& position, const tuple<char, int>& nextPosition) const
{
	const Piece* fromPiece = getPiece(position);
	Color fromColor;
	if (fromPiece != nullptr)
	{
		fromColor = fromPiece->getColor();
	}
	else
	{
		return false;
	}

	const Piece* toPiece = getPiece(nextPosition);
	Color toColor;
	if (toPiece != nullptr)
	{
		toColor = toPiece->getColor();
	}
	else
	{
		return false;
	}

	return fromColor != toColor;

}

bool Board::isPawnMoveValid(const tuple<char, int>& position, const tuple<char, int>& nextPosition) const
{
	int moveLength = getMoveLength(position, nextPosition);

	if (isForwardMove(position, nextPosition))
	{
		return false;
	}

	if (isHorizontalMove(position, nextPosition))
	{
		return false;
	}

	if (isDiagonalMove(position, nextPosition)) //pour manger
	{
		if (moveLength == 1)
		{
			if (isOccupiedDifferentColor(position, nextPosition))
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}

	if (isVerticalMove(position, nextPosition))
	{
		if (isOccupied(nextPosition))
		{
			return false;
		}

		if (moveLength == 2)
		{
			//condition au debut pour un movement de 2
		}
		else if (moveLength == 1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	return false;
}

bool Board::isKnightMove(const std::tuple<char, int>& position, const std::tuple<char, int>& nextPosition) const
{

	int verticalDifference = abs(get<0>(position) - get<0>(nextPosition));
	int horizontalDifference = abs(get<1>(position) - get<1>(nextPosition));

	if ((verticalDifference == 2 && horizontalDifference == 1) || (verticalDifference == 1 && horizontalDifference == 2))
		return true;
	else
		return false;
}

bool Board::isKnightMoveValid(const tuple<char, int>& position, const tuple<char, int>& nextPosition) const
{
	if (isKnightMove(position, nextPosition))
		return true;
	else
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
	if (isHorizontalMove(position, nextPosition) || isVerticalMove(position, nextPosition))
		if (isPathValid(position, nextPosition))
			return true;
}