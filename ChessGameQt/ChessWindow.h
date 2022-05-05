/*
* \file   ChessWindow.h
* \author Matteo Colavita et Thomas Mousseau
* \date   25 avril 2022
* Créé le 20 avril 2022
*/

#pragma once
#pragma warning(push, 0)
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QButtonGroup>
#include <QPainter>
#include "Raii.h"
#include <QVBoxLayout>
#include <QBrush>
#include <QAction>
#include <qboxlayout.h>
#include <QMenuBar>
#include <qmessagebox.h>
#include "Tile.h"
#include <QLabel>
#include "TooManyKingsException.h"
#include <Board.h>

#pragma pop()

namespace graphicinterface
{
    class ChessWindow : public QMainWindow
    {
        Q_OBJECT
    public:
        ChessWindow(QWidget* parent = nullptr);
        ChessWindow(QHBoxLayout* layout, QWidget* parent = 0);
    	void addGameModeLabel();
        void addGameModeButton();
        void addPlayersTurnLabel();
        
        void resetBoard();
        void updateBoard();
        void clearBoard();

        void endGame();

    public slots:
        void addPiece(std::tuple<char, int>, std::string);
    	void buttonClicked();
        void displayPossibleMoves(std::vector<std::tuple<char, int>> possibleMoves);
        void displayPlayerTurn(Color);
        void connectButtonToTile();
        void buttonNormalModeClicked();
        void buttonSpecialModeClicked();
        void EndGameMessage();

    private:
        void populateBoard();
        gamelogic::Board* board_;
    	QPushButton* addButton(int, int);
        QHBoxLayout* layout_;
        QVBoxLayout* rightLayout_;
        std::map<std::tuple<char, int>, QPushButton*> squares_;
        std::vector<std::tuple<char, int>> clickedPositions_;
        QLabel* colorTurnLabel_;
        QLabel* gameModeLabel_;
    };
}

