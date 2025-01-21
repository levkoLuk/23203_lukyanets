#ifndef GAMEOFLIFE_H
#define GAMEOFLIFE_H

#include <vector>

class GameOfLife {
public:
    GameOfLife(int width, int height);
    bool getCellState(int x, int y) const;
    void toggleCellState(int x, int y);
    void update();
    void reset();

private:
    int width;
    int height;
    std::vector<std::vector<bool>> grid;

    int countLiveNeighbors(int x, int y) const;
};

#endif // GAMEOFLIFE_H
