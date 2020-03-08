#include "FileIO.h"

FileIO::FileIO()
{
  //default constructor
}

FileIO::FileIO(array b)
{
  ofstream newfile;
  newfile.open ("Karstrom.txt");
  gameBoard = b;
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

}

void FileIO::printGameBoard()
{

}
