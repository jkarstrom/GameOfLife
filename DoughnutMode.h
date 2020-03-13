#include "Grid.h"
#include <iostream>

using namespace std;

class DoughnutMode
{
  public:

    DoughnutMode();//default constructor
    DoughnutMode(Grid *someGrid);//overload constructor
    ~DoughnutMode();

    //cour functions
    void countNeighbors(Grid *someGrid);

    //aux functions
    void zeroNeighbors();

    //vars
    int rows = 0;
    int columns = 0;
    int **newNeighbors;

};
