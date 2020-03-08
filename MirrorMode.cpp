#include "MirrorMode.h"

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
  for(i = 0; i < gameBoard.length(); ++i)
  {
    for(j = 0; j < gameBoard[i].length(); ++j)
    {
      int tempCorner = 0;
      int tempSide = 0;
      int tempMiddle = 0;

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
