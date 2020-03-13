#include "Grid.h"
//Joan Karstrom, Jennifer Nguyen
//ID: 2318286, 2320560
//karstrom@chapman.edu, jenguyen@chapman.edu
//CPSC: 350 - 2
//Assignment 2: Game of Life

class FileIO
{
public:

  FileIO();//default constructor
  ~FileIO();//deconstructor

  //core functions
  static void readMapping(string fileName, Grid *someGrid);

  //aux functions
  static void print(string fileName, Grid *someGrid);

private:
  //vars
  int rows = 0;
  int columns = 0;
};
