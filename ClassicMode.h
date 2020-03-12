#include "Grid.h"

class ClassicMode{
public:
    ClassicMode();
    ClassicMode(Grid *someGrid);
    ~ClassicMode();

    void countNeighbors(Grid *someGrid); // counts and updates the neighborCountGrid

private:
    int rows = 0;
    int columns = 0;
    int **newNeighbors;

    void zeroNeighbors(); // zeros newNeighbors array to 0

};
