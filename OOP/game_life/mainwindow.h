#pragma once

#include <QMainWindow>
#include <QTimer>
#include "gameoflife.h"
#include "customscene.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onStartButtonClicked();
    void onStopButtonClicked();
    void onResetButtonClicked();
    void onZombieModeButtonClicked();
    void updateGame();
    void onCellClicked(int x, int y);

private:
    Ui::MainWindow *ui;
    CustomScene *scene;
    GameOfLife *game;
    QTimer *timer;
    bool zombieMode;
    void drawGrid();
    void updateZombieCount();
};
