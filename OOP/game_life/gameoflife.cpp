#include "gameoflife.h"

GameOfLife::GameOfLife(int width, int height)
    : width(width), height(height), grid(height, std::vector<bool>(width, false))
{
}

bool GameOfLife::getCellState(int x, int y) const
{
    return grid[y][x];
}

void GameOfLife::toggleCellState(int x, int y) {

    grid[y][x] = !grid[y][x];
}

void GameOfLife::update() {

    std::vector<std::vector<bool>> newGrid = grid;

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int liveNeighbors = countLiveNeighbors(x, y);

            if (grid[y][x]) {
                if (liveNeighbors < 2 || liveNeighbors > 3) {
                    newGrid[y][x] = false;
                }
            } else {
                if (liveNeighbors == 3) {
                    newGrid[y][x] = true;
                }
            }
        }
    }

    grid = newGrid;
}

void GameOfLife::reset(){

    grid = std::vector<std::vector<bool>>(height, std::vector<bool>(width, false));
}

int GameOfLife::countLiveNeighbors(int x, int y) const {

    int count = 0;

    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            if (i == 0 && j == 0) continue;

            int nx = x + i;
            int ny = y + j;

            if (nx >= 0 && nx < width && ny >= 0 && ny < height && grid[ny][nx]) {
                ++count;
            }
        }
    }

    return count;
}
