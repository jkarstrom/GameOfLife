#include <iostream>
#include "Grid.h"
using namespace std;

class ClassicMode{
public:
    ClassicMode();
    ~ClassicMode();
    void countNeighbors();
private:
    int **newNeighbors;
};
