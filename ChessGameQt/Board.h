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
		std::vector<Tile*> getTiles();
		void createPieces();
		void possibleMovesFilter(std::vector<std::tuple<char, int>>);
		bool isOccupiedSameColor(const std::tuple<char, int>& position, const std::tuple<char, int>& nextPosition);
		bool isOnBoard(const std::tuple<char, int>& position);
		bool isOccupied(const std::tuple<char, int>& position);
		bool isOccupiedDifferentColor(const std::tuple<char, int>& position, const std::tuple<char, int>& nextPosition);
		bool isForwardMove(const std::tuple<char, int>& position, const std::tuple<char, int>& nextPosition);
		bool isKnightMove(const std::tuple<char, int>& position, const std::tuple<char, int>& nextPosition);
		bool isVerticalMove(const std::tuple<char, int>& position, const std::tuple<char, int>& nextPosition);
		bool isHorizontalMove(const std::tuple<char, int>& position, const std::tuple<char, int>& nextPosition);
		bool isDiagonalMove(const std::tuple<char, int>& position, const std::tuple<char, int>& nextPosition);
		int getMoveLength(const std::tuple<char, int>& position, const std::tuple<char, int>& nextPosition);
		std::unique_ptr<Piece> setPiece(const std::tuple<char, int>& position, std::unique_ptr<Piece> piece);
		int ConvertCharToInt(char c);
		Piece* getPiece(const std::tuple<char, int>& position);
		bool isPathValid(const std::tuple<char, int>& position, const std::tuple<char, int>& nextPosition);
		bool isKingMoveValid(const std::tuple<char, int>& position, const std::tuple<char, int>& nextPosition);
		bool isRookMoveValid(const std::tuple<char, int>& position, const std::tuple<char, int>& nextPosition);
		bool isBishopMoveValid(const std::tuple<char, int>& position, const std::tuple<char, int>& nextPosition);
		bool isQueenMoveValid(const std::tuple<char, int>& position, const std::tuple<char, int>& nextPosition);
		bool isPawnMoveValid(const std::tuple<char, int>& position, const std::tuple<char, int>& nextPosition, bool isSimulated);
		bool isKnightMoveValid(const std::tuple<char, int>& position, const std::tuple<char, int>& nextPosition);
		void createKings();
		void movePiece(const std::tuple<char, int>& position, const std::tuple<char, int>& nextPosition);
		bool isValidMove(const std::tuple<char, int>& position, const std::tuple<char, int>& nextPosition);
		bool nextMoveIsSafe(const std::tuple<char, int>& nextPosition, Color defendingColor);
		void resetAllTiles();
		std::tuple<char, int> getKingLocation(Color);
		std::vector<std::tuple<char, int>> getPieceLocations(Color);
		void createSpecialSituation();
		int getMoveNumber() { return moveNumber_; }
		bool getIsCreatingSpecialSituation() { return isCreationSpecialSituation; }
		void creationSpecialSituation() { isCreationSpecialSituation = true; }
		Color getTurn() const;
		void isCheckMate();
		bool isInCheck(Color defendingColor);
		bool willBeInCheck(const std::tuple<char, int>& nextPosition, Color defendingColor);

	public slots:
			void checkAllTiles(const std::tuple<char, int>& position);
			void moveLogic(std::tuple<char, int>& position, std::tuple<char, int>& nextPosition);

		
		signals:
			void possibleMovesChanged(std::vector<std::tuple<char, int>> possibleMoves);
			void turnChanged(Color);
			void GameEnded();
		
	private:
		std::map<std::tuple<char, int>, std::unique_ptr<Tile>> tiles_;
		void populateTiles();
		void createBishops();
		void createRooks();
		void createQueens();
		void createPawns();
		void createKnights();

		std::vector<std::tuple<char, int>> threatsToKing_;
		bool isCreationSpecialSituation = false;
		int moveNumber_ = 0; 


		
	};
}
