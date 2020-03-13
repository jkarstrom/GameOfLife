#include "Grid.h"
#include <iostream>

using namespace std;

class FileIO
{
public:

  FileIO();
  FileIO(Grid *someGrid, int genNum);
  ~FileIO();

  //cour functions

  //aux functions
  printGameBoard();
  printGenNumbers();

  //vars
  int **newNeighbors;
  int generationNum:
}
