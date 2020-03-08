#include "FileIO.h"
#include <fstream>
#include <string>
#include <bits/stdc++.h>

FileIO::FileIO()
{
  //default constructor
}

FileIO::FileIO(array b, int genNum)
{
  ofstream newfile;
  newfile.open ("GameOfLife.txt");
  gameBoard = b;
  generationNum = genNum;
}

FileIO::~FileIO()
{
  delete gameBoard;
}

void FileIO::print()
{

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
