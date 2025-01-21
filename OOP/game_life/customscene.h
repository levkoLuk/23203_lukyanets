#ifndef CUSTOMSCENE_H
#define CUSTOMSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

class CustomScene : public QGraphicsScene
{
    Q_OBJECT

public:
    explicit CustomScene(QObject *parent = nullptr);

signals:
    void cellClicked(int x, int y);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif // CUSTOMSCENE_H
