#include "gameoflife.h"

GameOfLife::GameOfLife(int width, int height)
    : width(width), height(height), grid(height, std::vector<CellState>(width, Dead)), zombieMode(false)
{
}

GameOfLife::CellState GameOfLife::getCellState(int x, int y) const
{
    return grid[y][x];
}

void GameOfLife::toggleCellState(int x, int y)
{
    if (grid[y][x] == Alive) {
        grid[y][x] = Dead;
    } else {
        grid[y][x] = Alive;
    }
}

void GameOfLife::update()
{
    std::vector<std::vector<CellState>> newGrid = grid;

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int liveNeighbors = countLiveNeighbors(x, y);

            if (grid[y][x] == Alive) {
                if (liveNeighbors < 2 || liveNeighbors > 3) {
                    newGrid[y][x] = zombieMode ? Zombie : Dead;
                }
            } else if (grid[y][x] == Zombie) {
                if (liveNeighbors == 2) {
                    newGrid[y][x] = Alive;
                }
            } else {
                if (liveNeighbors == 3) {
                    newGrid[y][x] = Alive;
                }
            }
        }
    }

    grid = newGrid;
}

void GameOfLife::reset()
{
    grid = std::vector<std::vector<CellState>>(height, std::vector<CellState>(width, Dead));
}

void GameOfLife::setZombieMode(bool enabled)
{
    zombieMode = enabled;
}

int GameOfLife::getZombieCount() const
{
    int count = 0;
    for (const auto& row : grid) {
        for (const auto& cell : row) {
            if (cell == Zombie) {
                ++count;
            }
        }
    }
    return count;
}

int GameOfLife::countLiveNeighbors(int x, int y) const
{
    int count = 0;

    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            if (i == 0 && j == 0) continue;

            int nx = ((x + i)+ height)% height;
            int ny = ((y + j) + width)% width;

            if (nx >= 0 && nx < width && ny >= 0 && ny < height && grid[ny][nx] == Alive) {
                ++count;
            }
        }
    }

    return count;
}
