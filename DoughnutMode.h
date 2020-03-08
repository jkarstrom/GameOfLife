#include <iostream>

using namespace std;

class DoughnutMode
{
  public:

    DoughnutMode();//default consturctor
    ~DoughnutMode();

    //cour functions
    countNeighbors();

    //aux functions
    checkCorner();
    checkSide();
    getNumNeighbors();

    //vars
    int numNeighbors;

    char *gameBoard;

};
