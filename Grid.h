#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

//Joan Karstrom, Jennifer Nguyen
//ID: 2318286, 2320560
//karstrom@chapman.edu, jenguyen@chapman.edu
//CPSC: 350 - 2
//Assignment 2: Game of Life

class Grid{
public:
    Grid();//default constructor
    Grid(int row, int column);//overload constructor
    ~Grid();//deconstructor

    //cor funtions
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

private:

    //vars
    int rowCount = 0;
    int columnCount = 0;
    int generationNum = 0;
    char** generationGrid;
    int** neighborCountGrid;

    //aux funtions
    void fillGrid(); // initializes generationGrid and neighborCountGrid to default values

};

#endif /* GRID_H */
