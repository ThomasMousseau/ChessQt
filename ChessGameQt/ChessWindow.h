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
#include <QPainter>
#include <QBrush>
#include <QAction>
#include <QMenuBar>
#include <qmessagebox.h>
#include "Tile.h"
#include "Board.h"
#include "TooManyKingsException.h"

#pragma pop()

namespace graphicinterface
{
    class ChessWindow : public QMainWindow
    {
        Q_OBJECT
    public:
        ChessWindow(QWidget* parent = nullptr);
        ChessWindow(QGraphicsScene* scene, QWidget* parent = 0);
    public slots:
        void buttonClicked();

    private:
        QGraphicsScene* scene_;
    	std::shared_ptr<gamelogic::Board> board_;
        Tile* tile_;
    };
}

