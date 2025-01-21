#include "cell.h"

Cell::Cell(int x, int y, bool alive, QGraphicsItem *parent)
    : QGraphicsRectItem(x * 10, y * 10, 10, 10, parent), isAlive(alive)
{
    aliveBrush = QBrush(Qt::black);
    deadBrush = QBrush(Qt::white);
    setAlive(alive);
}

void Cell::setAlive(bool alive)
{
    isAlive = alive;
    setBrush(isAlive ? aliveBrush : deadBrush);
}
