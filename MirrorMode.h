#include "Grid.h"
//Joan Karstrom, Jennifer Nguyen
//ID: 2318286, 2320560
//karstrom@chapman.edu, jenguyen@chapman.edu
//CPSC: 350 - 2
//Assignment 2: Game of Life

class MirrorMode
{
public:
    MirrorMode();//default constructor
    MirrorMode(Grid *someGrid);//overload constructor
    ~MirrorMode();//deconstructor

    //cour functions
    void countNeighbors(Grid *someGrid);

private:
    //aux functions
    void zeroNeighbors();

    //vars
    int rows = 0;
    int columns = 0;
    int **newNeighbors;

};
