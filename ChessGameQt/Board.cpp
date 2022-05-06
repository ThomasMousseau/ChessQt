/**
* \file   Board.cpp
* \author Matteo Colavita et Thomas Mousseau
* \date   25 avril 2022
* Créé le 20 avril 2022
*/


#include "Board.h"


using namespace gamelogic;
using namespace std;


Board::Board()
{
	populateTiles();

}

vector<Tile*> Board::getTiles()
{
	vector<Tile*> tileVect;

	for (auto&& tile : tiles_)
		tileVect.push_back(move(tile.second.get()));

	return tileVect;
}

void Board::createPieces()
{
	createBishops();
	createRooks();
	createPawns();
	createKnights();
	createQueens();
}

void Board::createSpecialSituation()
{
	setPiece(make_tuple('d', 5), make_unique<King>(Color::WHITE));
	setPiece(make_tuple('f', 7), make_unique<Queen>(Color::WHITE));

	setPiece(make_tuple('d', 8), make_unique<King>(Color::BLACK));
	setPiece(make_tuple('b', 6), make_unique<Rook>(Color::BLACK));
}

bool Board::isOccupiedSameColor(const std::tuple<char, int>& position, const std::tuple<char, int>& nextPosition)
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

	return fromColor == toColor;
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
	return tiles_[position]->setPiece(move(piece));
}
void Board::movePiece(const std::tuple<char, int>& position, const std::tuple<char, int>& nextPosition)
{
	tiles_[nextPosition]->movePiece(*tiles_[position].get());
	emit tiles_[position]->tileTextModified(position, "");
}

bool Board::isOnBoard(const tuple<char, int>& coords)
{
	if (get<0>(coords) < 'a' || get<0>(coords) > 'h' || get<1>(coords) < 1 || get<1>(coords) > 8)
		return false;
	return true;
}

bool Board::isOccupied(const tuple<char, int>& coords)
{
	return getPiece(coords) != nullptr;

}

bool Board::isVerticalMove(const tuple<char, int>& position, const tuple<char, int>& nextPosition)
{
	return get<0>(position) == get<0>(nextPosition); 
}

bool Board::isHorizontalMove(const tuple<char, int>& position, const tuple<char, int>& nextPosition)
{
	return get<1>(position) == get<1>(nextPosition);
}
bool Board::isDiagonalMove(const tuple<char, int>& position, const tuple<char, int>& nextPosition)
{
	const int vertDis = abs(get<0>(position) - get<0>(nextPosition));
	const int horDis = abs(get<1>(position) - get<1>(nextPosition));

	return vertDis == horDis;
}
int Board::getMoveLength(const tuple<char, int>& position, const tuple<char, int>& nextPosition)
{
	if (isVerticalMove(position, nextPosition))
	{
		return abs(get<1>(nextPosition) - get<1>(position));
	}
	if (isHorizontalMove(position, nextPosition))
	{
		return abs(get<0>(nextPosition) - get<0>(position));
	}
	if (isDiagonalMove(position, nextPosition))
	{
		return abs(get<0>(nextPosition) - get<0>(position)); 
	}
	return 0;
}

bool Board::isKingMoveValid(const tuple<char, int>& position, const tuple<char, int>& nextPosition)
{
	Color defendingColor = tiles_.find(position)->second->getPiece()->getColor();
	if(defendingColor == getTurn() && (isInCheck(defendingColor) || willBeInCheck(nextPosition, defendingColor)))
	{
		if (getMoveLength(position, nextPosition) == 1 && nextMoveIsSafe(nextPosition, defendingColor))
			return true;
		return false;
	}
	if (getMoveLength(position, nextPosition) == 1)
		return true;
	return false;
	
}

bool Board::nextMoveIsSafe(const tuple<char, int>& nextPosition, Color defendingColor)
{

	bool isSafe = true;
	Color attackingColor;
	if (defendingColor == Color::WHITE)
		attackingColor = Color::BLACK;
	else
		attackingColor = Color::WHITE;

	std::vector<std::tuple<char, int>> allAttackingPieces = getPieceLocations(attackingColor);

	for (auto attackingPiece : allAttackingPieces)
	{
		if (isValidMove(attackingPiece, nextPosition))
		{
			threatsToKing_.push_back(attackingPiece);
			isSafe =  false;
		}
	}
	return isSafe;
}

bool Board::willBeInCheck(const std::tuple<char, int>& nextPosition, Color defendingColor)
{
	Color attackingColor;
	if (defendingColor == Color::WHITE)
		attackingColor = Color::BLACK;
	else
		attackingColor = Color::WHITE;

	std::tuple<char, int> nextKingPosition = nextPosition;
	std::vector<std::tuple<char, int>> piecesPosition = getPieceLocations(attackingColor);

	for (auto attackingPiece : piecesPosition)
	{
		if (isValidMove(attackingPiece, nextKingPosition))
			return true;
	}
	return false;
}


bool Board::isBishopMoveValid(const tuple<char, int>& position, const tuple<char, int>& nextPosition)
{
	if (isDiagonalMove(position, nextPosition))
		if (isPathValid(position, nextPosition))
			return true;
}

bool Board::isPathValid(const tuple<char, int>& position, const tuple<char, int>& nextPosition)
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
		get<0>(posActuel) += composantVecteurVer; 
		get<1>(posActuel) += composantVecteurHor;

		isAtFinalTile = get<0>(posActuel) == get<0>(nextPosition) && get<1>(posActuel) == get<1>(nextPosition);

		if(isAtFinalTile)
		{
			if (isOccupiedSameColor(position,posActuel))
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

bool Board::isQueenMoveValid(const tuple<char, int>& position, const tuple<char, int>& nextPosition)
{
	if (isVerticalMove(position, nextPosition) || isHorizontalMove(position, nextPosition))
		if (isPathValid(position, nextPosition))
			return true;

	 if (isDiagonalMove(position, nextPosition))
		if (isPathValid(position, nextPosition))
			return true;

	return false;
}

bool Board::isForwardMove(const tuple<char, int>& position, const tuple<char, int>& nextPosition)
{
	auto color = tiles_.find(position)->second.get()->getPiece()->getColor();

	if (color == Color::BLACK && get<1>(position) > get<1>(nextPosition))
		return true;
	if (color == Color::WHITE && get<1>(position) < get<1>(nextPosition))
		return true;
	return false;
}

Piece* Board::getPiece(const std::tuple<char, int>& position)
{
	return tiles_.find(position)->second->getPiece();
}

bool Board::isOccupiedDifferentColor(const tuple<char, int>& position, const tuple<char, int>& nextPosition)
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

bool Board::isPawnMoveValid(const tuple<char, int>& position, const tuple<char, int>& nextPosition, bool isSimulated)
{
	int moveLength = getMoveLength(position, nextPosition);
	Piece* piece = getPiece(position);

	if (!isForwardMove(position, nextPosition))
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
				if(!isSimulated)
					piece->incrementNTimeMoves();
				return true;
			}
			return false;
		}
		return false;
	}

	if (isVerticalMove(position, nextPosition))
	{
		if (isOccupied(nextPosition))
			return false;

		if (moveLength == 2)
		{
			if (tiles_.find(position)->second.get()->getPiece()->getNTimesMoved() == 0)
			{
				if (!isSimulated)
					piece->incrementNTimeMoves();
				return true;
			}
		}
		else if (moveLength == 1)
		{
			if (!isSimulated)
				piece->incrementNTimeMoves();
			return true;
		}
		else
			return false;
	}
	return false;
}

bool Board::isKnightMove(const std::tuple<char, int>& position, const std::tuple<char, int>& nextPosition)
{

	int verticalDifference = abs(get<0>(position) - get<0>(nextPosition));
	int horizontalDifference = abs(get<1>(position) - get<1>(nextPosition));

	if ((verticalDifference == 2 && horizontalDifference == 1) || (verticalDifference == 1 && horizontalDifference == 2))
		return true;
	return false;
}

bool Board::isKnightMoveValid(const tuple<char, int>& position, const tuple<char, int>& nextPosition)
{
	if (isKnightMove(position, nextPosition))
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
			unique_ptr<Tile> tile = make_unique<Tile>(coords);
			tiles_.insert(pair(coords, move(tile)));
		}
	}
}

bool Board::isRookMoveValid(const tuple<char, int>& position, const tuple<char, int>& nextPosition)
{
	if (isHorizontalMove(position, nextPosition) || isVerticalMove(position, nextPosition))
		if (isPathValid(position, nextPosition))
			return true;
}

bool Board::isValidMove(const std::tuple<char, int>& position, const std::tuple<char, int>& nextPosition)
{
	if (!isOnBoard(position) || !isOnBoard(nextPosition))
		return false;

	if (isOccupiedSameColor(position, nextPosition))
		return false;

	Piece* piece = getPiece(position);
	if (piece == nullptr)
		return false;

	switch(piece->getType())
	{
		case Type::BISHOP : return isBishopMoveValid(position, nextPosition);
		case Type::KING : return isKingMoveValid(position, nextPosition);
		case Type::ROOK : return isRookMoveValid(position, nextPosition);
		case Type::QUEEN : return isQueenMoveValid(position, nextPosition);
		case Type::PAWN : return isPawnMoveValid(position, nextPosition, false);
		case Type::KNIGHT : return isKnightMoveValid(position, nextPosition);
	}
}

void Board::checkAllTiles(const std::tuple<char, int>& position)
{
	std::vector<std::tuple<char, int>> tileAccessible;
	Piece* piece = getPiece(position);

	if(piece->getColor() != getTurn())
		return;

	for(auto it = tiles_.begin(); it != tiles_.end(); ++it)
	{
		if (isOccupiedSameColor(position, it->first))
			continue;
		switch (piece->getType())
		{
			case Type::BISHOP:  
				if (isBishopMoveValid(position, it->first))
					tileAccessible.push_back(it->first);
				break;
			case Type::KING: 
				if(isKingMoveValid(position, it->first))
					tileAccessible.push_back(it->first);
				break;
			case Type::ROOK:  
				if (isRookMoveValid(position, it->first))
					tileAccessible.push_back(it->first);
				break;
			case Type::QUEEN:  
				if(isQueenMoveValid(position, it->first))
					tileAccessible.push_back(it->first);
				break;
			case Type::PAWN: 
				if(isPawnMoveValid(position, it->first, true))
					tileAccessible.push_back(it->first);
				break;
			case Type::KNIGHT:  
				if(isKnightMoveValid(position, it->first))
					tileAccessible.push_back(it->first);
				break;
		}
	}
	bool allThreatAreSafe = true;
	for(auto pieceThreats : threatsToKing_)
	{
		if (willBeInCheck(pieceThreats, piece->getOppsiteColor()))
			allThreatAreSafe = false;
	}
	if (piece->getType() == Type::KING && tileAccessible.size() == 0 && allThreatAreSafe)
			isCheckMate();
	emit possibleMovesChanged(tileAccessible);
}
std::tuple<char, int> Board::getKingLocation(Color color)
{
	for (auto const& tile : tiles_) {
		Piece* piece = tile.second->getPiece();
		if (piece != nullptr && piece->getColor() == color && piece->getType() == Type::KING)
		{
			return tile.first;
		}
	}
}

std::vector<std::tuple<char, int>> Board::getPieceLocations(Color color)
{
	std::vector<std::tuple<char, int>> pieceLocations;

	for (auto const& tile : tiles_)
	{
		Piece* piece = tile.second->getPiece();
		if (piece != nullptr && piece->getColor() == color)
		{
			pieceLocations.push_back(tile.first);
		}
	}
	return pieceLocations;
}

void Board::moveLogic(std::tuple<char, int>& position, std::tuple<char, int>& nextPosition)
{
	if(isValidMove(position, nextPosition) && tiles_[position].get()->getPiece()->getColor() == getTurn())
	{
		movePiece(position, nextPosition);
		moveNumber_++;
		emit turnChanged(getTurn());
	}
}

Color Board::getTurn() const
{
	if (moveNumber_ % 2 == 0)
		return Color::WHITE;
	return Color::BLACK;
}

void Board::isCheckMate() 
{
	emit GameEnded();
}
bool Board::isInCheck(Color defendingColor)
{
	Color attackingColor;
	if (defendingColor == Color::WHITE)
		attackingColor = Color::BLACK;
	else
		attackingColor = Color::WHITE;

	std::tuple<char, int> kingPosition = getKingLocation(defendingColor);
	std::vector<std::tuple<char, int>> piecesPosition = getPieceLocations(attackingColor);

	for (auto attackingPiece : piecesPosition)
	{
		if (isValidMove(attackingPiece, kingPosition))
			return true;
	}
	return false;
}
