/*
* \file   Board.h
* \author Matteo Colavita et Thomas Mousseau
* \date   25 avril 2022
* Créé le 20 avril 2022
*/

#pragma once
#include <map>
#include <memory>
#include <vector>
#include <tuple>
#include <QGraphicsScene>
#include "Rook.h"
#include "Bishop.h"
#include "King.h"
#include "Pawn.h"
#include "Knight.h"
#include "Queen.h"
#include "Tile.h"

namespace gamelogic
{
	
	class Board {

	public:
		Board(QGraphicsScene* scene);

		std::vector<Tile*> getTiles();

		//unique_ptr<Tile> getPiece(const std::tuple<char, int>& position) const;

		bool isOnBoard(const std::tuple<char, int>& position) const;
		bool isOccupied(const std::tuple<char, int>& position) const;
		bool isOccupiedDifferentColor(const std::tuple<char, int>& position, const std::tuple<char, int>& nextPosition) const;
		bool isForwardMove(const std::tuple<char, int>& position, const std::tuple<char, int>& nextPosition) const;
		bool isKnightMove(const std::tuple<char, int>& position, const std::tuple<char, int>& nextPosition) const;
		bool isVerticalMove(const std::tuple<char, int>& position, const std::tuple<char, int>& nextPosition) const;
		bool isHorizontalMove(const std::tuple<char, int>& position, const std::tuple<char, int>& nextPosition) const;
		bool isDiagonalMove(const std::tuple<char, int>& position, const std::tuple<char, int>& nextPosition) const;
		int getMoveLength(const std::tuple<char, int>& position, const std::tuple<char, int>& nextPosition) const;
		std::unique_ptr<Piece> setPiece(const std::tuple<char, int>& position, std::unique_ptr<Piece> piece);
		int ConvertCharToInt(char c);
		Piece* getPiece(const std::tuple<char, int>& position) const;
		bool isPathValid(const std::tuple<char, int>& position, const std::tuple<char, int>& nextPosition) const;

		//set of moves for all pieces
		bool isKingMoveValid(const std::tuple<char, int>& position, const std::tuple<char, int>& nextPosition) const;
		bool isRookMoveValid(const std::tuple<char, int>& position, const std::tuple<char, int>& nextPosition) const;
		bool isBishopMoveValid(const std::tuple<char, int>& position, const std::tuple<char, int>& nextPosition) const;
		bool isQueenMoveValid(const std::tuple<char, int>& position, const std::tuple<char, int>& nextPosition) const;
		bool isPawnMoveValid(const std::tuple<char, int>& position, const std::tuple<char, int>& nextPosition) const;
		bool isKnightMoveValid(const std::tuple<char, int>& position, const std::tuple<char, int>& nextPosition) const;

		void createKings();
		void movePiece(const std::tuple<char, int>& position, const std::tuple<char, int>& nextPosition);
		
	private:
		std::map<std::tuple<char, int>, std::unique_ptr<Tile>> tiles;
		QGraphicsScene* scene_{};
		void populateTiles();
		void createBishops();
		void createRooks();
		void createQueens();
		void createPawns();
		void createKnights();
		
	};
}
