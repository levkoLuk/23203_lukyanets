#include "customscene.h"

CustomScene::CustomScene(QObject *parent) : QGraphicsScene(parent)
{
}

void CustomScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QPointF scenePos = event->scenePos();
    int x = static_cast<int>(scenePos.x()) / 10;
    int y = static_cast<int>(scenePos.y()) / 10;
    emit cellClicked(x, y);
}

void CustomScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton) {
        QPointF scenePos = event->scenePos();
        int x = static_cast<int>(scenePos.x()) / 10;
        int y = static_cast<int>(scenePos.y()) / 10;

        if (x != lastX || y != lastY) {
            lastX = x;
            lastY = y;
            emit cellClicked(x, y);
        }
    }
}
