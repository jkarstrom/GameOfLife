#include "Grid.h"
//Joan Karstrom, Jennifer Nguyen
//ID: 2318286, 2320560
//karstrom@chapman.edu, jenguyen@chapman.edu
//CPSC: 350 - 2
//Assignment 2: Game of Life

class ClassicMode{
public:
    ClassicMode();//default constructor
    ClassicMode(Grid *someGrid); 
    ~ClassicMode();//deconstructor

  //core functions
    void countNeighbors(Grid *someGrid); // counts and updates the neighborCountGrid

private:
  //variables
    int rows = 0;
    int columns = 0;
    int **newNeighbors;

  //aux functions
    void zeroNeighbors(); // zeros newNeighbors array to 0

};
