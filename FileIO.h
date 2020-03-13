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
  void print();

  //vars
  int rows = 0;
  int columns = 0;
  Grid *gameBoard;
  int generationNum:
};
