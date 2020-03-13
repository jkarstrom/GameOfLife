#include "FileIO.h"
#include <fstream>
#include <string>
#include <bits/stdc++.h>

FileIO::FileIO()
{
  //default constructor
}

FileIO::FileIO(Grid *someGrid, int genNum)
{
  ofstream newfile;
  newfile.open ("GameOfLife.txt");
  gameBoard = someGrid;
  generationNum = genNum;
}

FileIO::~FileIO()
{
  delete gameBoard;
}

void FileIO::print()
{
  printGenNumbers();
  printGameBoard();
}

void FileIO::printGenNumbers()
{
  newfile << "\nThe number of generations was: " << generationNum << endl;
}

void FileIO::printGameBoard()
{
  for(int i = 0; i < gameBoard.length(); ++i)
  {
    for(int j = 0; i < gameBoard[i].length(); ++j)
    {
      newfile << gameBoard[i][j] << endl;
    }
    newfile << "   \n" << endl;
  }
}
