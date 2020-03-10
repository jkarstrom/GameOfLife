#include <iostream>
using namespace std;

class Grid{
public:
    Grid();
    Grid(int row, int column);
    ~Grid();
    void assignCells(char **arr);
    void updateNeighbors(char **arr);
    char** generationGrid;
    void randomCells();
    int getRows();
    int getColumns();
    void printGrid();

private:
    int rowCount = 1;
    int columnCount = 1;

    int** neighborCountGrid;
    void fillGrid();
};
