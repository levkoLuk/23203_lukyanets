#pragma once

#include <vector>

class GameOfLife
{
public:
    enum CellState {
        Dead,
        Alive,
        Zombie
    };

    GameOfLife(int width, int height);
    CellState getCellState(int x, int y) const;
    void toggleCellState(int x, int y);
    void update();
    void reset();
    void setZombieMode(bool enabled);
    int getZombieCount() const;

private:
    int width;
    int height;
    std::vector<std::vector<CellState>> grid;
    bool zombieMode;

    int countLiveNeighbors(int x, int y) const;
};
