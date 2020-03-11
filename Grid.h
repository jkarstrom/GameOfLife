#include <iostream>
using namespace std;

class Grid{
public:
    Grid();
    Grid(int row, int column);
    ~Grid();
    void assignCells(char **arr);
    void randomCells();
    void updateNeighbors(int **arr);
    char getCell(int row, int column);
    int getRows();
    int getColumns();
    void printGrid();
    void printGrid2(); // delete

private:
    int rowCount;
    int columnCount;
    char** generationGrid;
    int** neighborCountGrid;
    void fillGrid();
};
