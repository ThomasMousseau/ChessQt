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
	class Board: public QObject {
		Q_OBJECT
	public:
		//Board(); //mettre un bool dans le params du constructeurs  pour savoir si on a une disposition classique ou checkMate
		Board();
		std::vector<Tile*> getTiles() const;
		void createPieces();
		void possibleMovesFilter(std::vector<std::tuple<char, int>>);
		bool isOccupiedSameColor(const std::tuple<char, int>& position, const std::tuple<char, int>& nextPosition) const;

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

		bool isKingMoveValid(const std::tuple<char, int>& position, const std::tuple<char, int>& nextPosition) const;
		bool isRookMoveValid(const std::tuple<char, int>& position, const std::tuple<char, int>& nextPosition) const;
		bool isBishopMoveValid(const std::tuple<char, int>& position, const std::tuple<char, int>& nextPosition) const;
		bool isQueenMoveValid(const std::tuple<char, int>& position, const std::tuple<char, int>& nextPosition) const;
		bool isPawnMoveValid(const std::tuple<char, int>& position, const std::tuple<char, int>& nextPosition, bool isSimulated) const;
		bool isKnightMoveValid(const std::tuple<char, int>& position, const std::tuple<char, int>& nextPosition) const;

		void createKings();
		void movePiece(const std::tuple<char, int>& position, const std::tuple<char, int>& nextPosition);
		bool isValidMove(const std::tuple<char, int>& position, const std::tuple<char, int>& nextPosition) const;
		bool nextMoveIsSafe(const std::tuple<char, int>& position, const std::tuple<char, int>& nextPosition, Color defendingColor) const;
		
		void resetAllTiles();
		std::tuple<char, int> getKingLocation(Color) const;
		std::vector<std::tuple<char, int>> getPieceLocations(Color) const;
		void createSpecialSituation();

		int getMoveNumber() { return moveNumber_; }

		bool getIsCreatingSpecialSituation() { return isCreationSpecialSituation; }
		void creationSpecialSituation() { isCreationSpecialSituation = true; }

		Color getTurn() const;

		void isCheckMate();
		bool isInCheck(Color defendingColor) const;
		bool willBeInCheck(const std::tuple<char, int>& nextPosition, Color defendingColor) const;

	public slots:
		//void findValidMoves(std::tuple<char, int>);
		void checkAllTiles(const std::tuple<char, int>& position);
		void moveLogic(std::tuple<char, int>& position, std::tuple<char, int>& nextPosition);

		
		signals:
			void possibleMovesChanged(std::vector<std::tuple<char, int>> possibleMoves);
			void turnChanged(Color);
		
	private:
		std::map<std::tuple<char, int>, std::unique_ptr<Tile>> tiles_;
		void populateTiles();
		void createBishops();
		void createRooks();
		void createQueens();
		void createPawns();
		void createKnights();

		bool isCreationSpecialSituation = false;
		int moveNumber_ = 0; 


		
	};
}
