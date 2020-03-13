#include "Grid.h"

class DoughnutMode
{
public:

    DoughnutMode();//default constructor
    DoughnutMode(Grid *someGrid);//overload constructor
    ~DoughnutMode();

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
