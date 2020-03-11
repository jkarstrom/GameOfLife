#include <iostream>
#include "Grid.h"
using namespace std;

class ClassicMode{
public:
    ClassicMode();
    ClassicMode(Grid *someGrid);
    ~ClassicMode();
    void countNeighbors(Grid *someGrid);
private:
    int rows;
    int columns;
    void zeroNeighbors();
    int **newNeighbors;
};
