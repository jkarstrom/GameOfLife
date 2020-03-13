#include <iostream>

using namespace std;

class MirrorMode
{
  public:
    MirrorMode();//default constructor
    MirrorMode(Grid *someGrid);
    ~MirrorMode();

    //cour functions
    countNeighbors();
    zeroNeighbors();

    //aux functions
    getNumNeighboors();

    //vars
    int numNeighbors;
    int rows = 0;
    int columns = 0;
    int **newNeighbors;

};
