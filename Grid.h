#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

class Grid{
public:
    Grid();
    Grid(int row, int column);
    ~Grid();

    void assignCells(char **arr); // used for when user has initial cell mapping
    void randomCells(); // generates a random assort of bacteria based on random density
    void updateNeighbors(int **arr); // changes the neighborCountGrid
    void updateGeneration(); // increments generation number
    void setCell(int row, int column, char bacteria); // change the selected cell value
    char getCell(int row, int column); // returns X if bacteria is alive at cell
    int getCellNeighbors(int row, int column); // returns the number of neighbors for a cell
    int getRows(); // returns number of rows for grid
    int getColumns(); // returns number of columns for grid
    int getGenerationNum(); // returns the generation number
    void printGrid(); // prints bacteria colony
    void printGrid2(); // prints neighborCountGrid (DELETE BEFORE SUBMISSION)

private:
    int rowCount = 0;
    int columnCount = 0;
    int generationNum = 0;
    char** generationGrid;
    int** neighborCountGrid;

    void fillGrid(); // initializes generationGrid and neighborCountGrid to default values

};

#endif /* GRID_H */
