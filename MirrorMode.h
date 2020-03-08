#include <iostream>

using namespace std;

class MirrorMode
{
public:
    MirrorMode();//default constructor
    MirrorMode(array b);
    ~MirrorMode();

    //cour functions
    countNeighbors();

    //aux functions
    checkCorner();
    checkSide();

    //vars
    int numNeighbors;

    char *gameBoard;

}
