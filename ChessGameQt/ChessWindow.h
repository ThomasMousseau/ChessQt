#pragma once
#pragma warning(push, 0)
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPainter>
#include <QBrush>
#include <QAction>
#include <QMenuBar>

#include "Tile.h"
#include "Board.h"

#pragma pop()

class ChessWindow: public QMainWindow
{
	Q_OBJECT
public:
    ChessWindow(QWidget* parent = nullptr);
    ChessWindow(QGraphicsScene* scene, QWidget* parent = 0);
    
    //~ChessWindow() = default;
public slots:
    void buttonClicked();

private:
    //void setup();
    QGraphicsScene* scene_;
    Board* board_;
    Tile* tile_;
    //Ui::ChessWindow* ui;
};
