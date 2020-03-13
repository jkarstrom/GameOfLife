#include <iostream>

using namespace std;

class DoughnutMode
{
  public:

    ClassicMode();//default constructor
    ClassicMode(Grid *someGrid);//overload constructor
    ~ClassicMode();

    //cour functions
    void countNeighbors(Grid *someGrid);

    //aux functions
    void zeroNeighbors();

    //vars
    int rows = 0;
    int columns = 0;
    int **newNeighbors;

};
