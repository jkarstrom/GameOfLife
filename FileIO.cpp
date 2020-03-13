#include "FileIO.h"
#include <fstream>
#include <string>

FileIO::FileIO()
{
  //default constructor
}

FileIO::FileIO(Grid *someGrid, int genNum)
{
  ofstream newfile;
  newfile.open("GameOfLife.txt");
  rows = someGrid->getRows();
  columns = someGrid->getColumns();
  gameBoard = new char*[rows];
  for(int i = 0; i < rows; ++i){
      gameBoard[i] = new char[columns];
  }
  generationNum = genNum;
}

FileIO::~FileIO()
{
  delete gameBoard;
}

void FileIO::print()
{
  if (newfile.is_open())
  {
    newfile << "\nThe number of generations was: " << generationNum;
    for(int i = 0; i < rows; ++i)
    {
      for(int j = 0; j < columns; ++j)
      {
        newfile << gameBoard[i][j];
      }
      newfile << "   \n";
    }
    newfile.close();
  }
  else cout << "Unable to open file";
  return 0;
}
