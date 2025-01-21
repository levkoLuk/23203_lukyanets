#pragma once

#include <QGraphicsRectItem>
#include <QBrush>
#include "gameoflife.h"

class Cell : public QGraphicsRectItem
{
public:
    Cell(int x, int y, GameOfLife::CellState state, QGraphicsItem *parent = nullptr);
    void setState(GameOfLife::CellState state);

private:
    GameOfLife::CellState state;
    QBrush aliveBrush;
    QBrush deadBrush;
    QBrush zombieBrush;
};
