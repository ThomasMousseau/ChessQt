﻿#include "ChessWindow.h"


ChessWindow::ChessWindow(QWidget* parent) :
	QMainWindow(parent)
{

}



void ChessWindow::CreateBoard(QGraphicsScene* scene)
{
	/*const int tileSize = 100;
    QPainter painter(this);
    const QBrush brush(Qt::SolidPattern);
    painter.setBrush(brush);
    QPen pen;
    pen.setColor(Qt::gray);*/

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            
            Tile tile(i,j);
            scene->addWidget(tile.getButton());

            /*if (j == 1)
            {
                button->setText("♙");
            }
            else if (j == 6)
            {
                button->setText("♟");
            }
            else
                if (j == 7)
                {
                    switch (i)
                    {
                    case 0:
                    case 7:
                        button->setText("♜");
                        break;
                    case 1:
                    case 6:
                        button->setText("♞");
                        break;
                    case 2:
                    case 5:
                        button->setText("♝");
                        break;
                    case 3:
                        button->setText("♛");
                        break;
                    case 4:
                        button->setText("♚");
                        break;
                    default:
                        break;
                    }
                }
                else
                    if (j == 0)
                    {
                        switch (i)
                        {
                        case 0:
                        case 7:
                            button->setText("♖");
                            break;
                        case 1:
                        case 6:
                            button->setText("♘");
                            break;
                        case 2:
                        case 5:
                            button->setText("♗");
                            break;
                        case 3:
                            button->setText("♕");
                            break;
                        case 4:
                            button->setText("♔");
                            break;
                        default:
                            break;
                        }
                    }*/
        }
    }
}