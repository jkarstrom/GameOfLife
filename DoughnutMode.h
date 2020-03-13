#include "Grid.h"
//Joan Karstrom, Jennifer Nguyen
//ID: 2318286, 2320560
//karstrom@chapman.edu, jenguyen@chapman.edu
//CPSC: 350 - 2
//Assignment 2: Game of Life

class DoughnutMode
{
public:

    DoughnutMode();//default constructor
    DoughnutMode(Grid *someGrid);//overload constructor
    ~DoughnutMode();//deconstructor

    //core functions
    void countNeighbors(Grid *someGrid);

private:
    //aux functions
    void zeroNeighbors();

    //vars
    int rows = 0;
    int columns = 0;
    int **newNeighbors;

};
