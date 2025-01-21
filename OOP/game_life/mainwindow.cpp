#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cell.h"
#include <QGraphicsView>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), scene(new CustomScene(this)), game(new GameOfLife(50, 50)), timer(new QTimer(this)), zombieMode(false)
{
    ui->setupUi(this);
    ui->graphicsView->setScene(scene);

    drawGrid();

    connect(ui->startButton, &QPushButton::clicked, this, &MainWindow::onStartButtonClicked);
    connect(ui->stopButton, &QPushButton::clicked, this, &MainWindow::onStopButtonClicked);
    connect(ui->resetButton, &QPushButton::clicked, this, &MainWindow::onResetButtonClicked);
    connect(ui->zombieModeButton, &QPushButton::clicked, this, &MainWindow::onZombieModeButtonClicked);

    connect(scene, &CustomScene::cellClicked, this, &MainWindow::onCellClicked);

    connect(timer, &QTimer::timeout, this, &MainWindow::updateGame);

    updateZombieCount();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete game;
}

void MainWindow::drawGrid()
{
    scene->clear();
    for (int x = 0; x < 50; ++x) {
        for (int y = 0; y < 50; ++y) {
            Cell *cell = new Cell(x, y, game->getCellState(x, y));
            scene->addItem(cell);
        }
    }
    updateZombieCount();
}

void MainWindow::onStartButtonClicked()
{
    timer->start(100);
}

void MainWindow::onStopButtonClicked()
{
    timer->stop();
}

void MainWindow::onResetButtonClicked()
{
    game->reset();
    drawGrid();
}

void MainWindow::onZombieModeButtonClicked()
{
    zombieMode = !zombieMode;
    ui->zombieModeButton->setText(zombieMode ? "Zombie Mode: On" : "Zombie Mode: Off");
    game->setZombieMode(zombieMode);
    drawGrid();
}

void MainWindow::updateGame()
{
    game->update();
    drawGrid();
}

void MainWindow::onCellClicked(int x, int y)
{
    game->toggleCellState(x, y);
    drawGrid();
}

void MainWindow::updateZombieCount()
{
    int zombieCount = game->getZombieCount();
    ui->zombieCountLabel->setText(QString("Zombie Cells: %1").arg(zombieCount));
}
