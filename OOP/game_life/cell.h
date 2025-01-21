#ifndef CELL_H
#define CELL_H

#include <QGraphicsRectItem>
#include <QBrush>

class Cell : public QGraphicsRectItem
{
public:
    Cell(int x, int y, bool alive, QGraphicsItem *parent = nullptr);
    void setAlive(bool alive);

private:
    bool isAlive;
    QBrush aliveBrush;
    QBrush deadBrush;
};

#endif // CELL_H


////////
