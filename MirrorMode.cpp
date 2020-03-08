#include "MirrorMode.h"
#include <iostream>

MirrorMode::MirrorMode()
{
  //default constructor
}

MirrorMode::MirrorMode(array b)
{
  int numNeighbors = 0;
  gameBoard = b;
}

MirrorMode::~MirrorMode()
{
  delete gameBoard;
}

int MirrorMode::countNeighbors()
{
  int tempCorner = 0;
  int tempSide = 0;
  int tempMiddle = 0;

  for(int i = 0; i < gameBoard.length(); ++i)
  {
    for(int j = 0; j < gameBoard[i].length(); ++j)
    {
      if(gameBoard[i][j]=='x')
      {
        if(checkCorner(i,j))
        {
          tempCorner++;
        }
        else if(checkSide(i,j))
        {
          tempSide++;
        }
        else
        {
          tempMiddle++;
        }
      }
    }
  }

  numNeighbors = (tempCorner*3)+(tempSide*2)+tempMiddle;
}

bool MirrorMode::checkCorner(int x, int y)
{
  if(gameBoard[x-1][y]== null || gameBoard[x+1][y]== null)
  {
    if(gameBoard[x][y-1]== null || gameBoard[x][y+1]== null)
    {
        return true;
    }
  }
}

bool MirrorMode::checkSide(int x, int y)
{
  if(gameBoard[x-1][y]== null || gameBoard[x+1][y]== null || gameBoard[x][y-1]== null || gameBoard[x][y+1]== null)
  {
    return true;
  }
}

int MirrorMode::getNumNeighbors()
{

}
