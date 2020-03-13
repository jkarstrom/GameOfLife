#include "Grid.h"
#include <iostream>

using namespace std;

class MirrorMode
{
  public:
    MirrorMode();//default constructor
    MirrorMode(Grid *someGrid);
    ~MirrorMode();

    //cour functions
    void countNeighbors(Grid *someGrid);
    void zeroNeighbors();

    //vars
    int rows = 0;
    int columns = 0;
    int **newNeighbors;

};
