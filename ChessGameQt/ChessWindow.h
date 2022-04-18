#pragma once
#pragma warning(push, 0)
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPainter>
#include <QBrush>
#include <Tile.h>

#pragma pop()

class ChessWindow: public QMainWindow
{
	Q_OBJECT
public:
    ChessWindow(QWidget* parent = nullptr);
    void CreateBoard(QGraphicsScene* scene);
    //~ChessWindow();

private:
    //Ui::ChessWindow* ui;
};
