#include "Grid.h"

class FileIO
{
public:

  FileIO();
  ~FileIO();

  //core functions
  static void readMapping(string fileName, Grid *someGrid);

  //aux functions
  static void print(string fileName, Grid *someGrid);

private:
  //vars
  int rows = 0;
  int columns = 0;
};
