#include "DoughnutMode.h"
#include <iostream>

DoughnutMode::DoughnutMode()
{

}

DoughnutMode::DoughnutMode(array b)
{
  int numNeighbors = 0;
  gameBoard = b;
}

DoughnutMode::~DoughnutMode()
{
  delete gameBoard;
}

DoughnutMode::countNeighbors()
{
  int tempCorner = 0;
  int tempSide = 0;
  int tempMiddle = 0;

  for(int i = 0; i < gameBoard.length(); ++i)
  {
    for(int j = 0; j < gameBoard[i].length(); ++j)
    {
      if(gameBoard[i][j] == 'x')
      {
        
      }
    }
  }
}

bool DoughnutMode::checkCorner(int x, int y)
{

}

bool DoughnutMode::checkSide(int x, int y)
{

}
