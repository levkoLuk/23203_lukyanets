#include "cell.h"

Cell::Cell(int x, int y, GameOfLife::CellState state, QGraphicsItem *parent)
    : QGraphicsRectItem(x * 10, y * 10, 10, 10, parent), state(state)
{
    aliveBrush = QBrush(Qt::black);
    deadBrush = QBrush(Qt::white);
    zombieBrush = QBrush(Qt::red);
    setState(state);
}

void Cell::setState(GameOfLife::CellState state)
{
    this->state = state;
    if (state == GameOfLife::Alive) {
        setBrush(aliveBrush);
    } else if (state == GameOfLife::Zombie) {
        setBrush(zombieBrush);
    } else {
        setBrush(deadBrush);
    }
}
