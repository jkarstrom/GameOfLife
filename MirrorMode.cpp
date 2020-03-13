#include "MirrorMode.h"
#include <iostream>

MirrorMode::MirrorMode()
{
  rows = 5;
  columns = 5;
  newNeighbors = new int*[rows];
  for(int i = 0; i < rows; ++i){
      newNeighbors[i] = new int[columns];
  }
  zeroNeighbors();
}

MirrorMode::MirrorMode(Grid *someGrid)
{
  int numNeighbors = 0;
  rows = someGrid->getRows();
  columns = someGrid->getColumns();
  newNeighbors = new int*[rows];
  for(int i = 0; i < rows; ++i){
      newNeighbors[i] = new int[columns];
  }
  zeroNeighbors();
}

MirrorMode::~MirrorMode()
{
  for(int x = 0; x < rows; ++x) {
      delete[] newNeighbors[x];
  }
  delete[] newNeighbors;
}

void MirrorMode::zeroNeighbors(){
    for(int i = 0; i < rows; ++i){
        for(int j = 0; j < columns; ++j){
            newNeighbors[i][j] = 0;
        }
    }
}

void MirrorMode::countNeighbors(Grid *someGrid){
    zeroNeighbors();
    for(int r = 0; r < rows; ++r){
        for(int c = 0; c < columns; ++c){
            // for the top row
            if(r == 0){
                // first column
                if(c == 0){
                    if(someGrid->getCell(r,c) == 'X'){
                        ++newNeighbors[r][c+1];
                        ++newNeighbors[r+1][c+1];
                        ++newNeighbors[r+1][c];
                        ++newNeighbors[r][columns-1];
                        ++newNeighbors[r-1][columns-1];
                        ++newNeighbors[rows-1][c];
                        ++newNeighbors[rows-1][c+1];
                        ++newNeighbors[rows-1][columns-1];
                    }
                }
                // last column
                else if(c == (columns-1)){
                    if(someGrid->getCell(r,c) == 'X'){
                        ++newNeighbors[r][c-1];
                        ++newNeighbors[r+1][c-1];
                        ++newNeighbors[r+1][c];
                    }
                }
                // middle columns
                else{
                    if(someGrid->getCell(r,c) == 'X'){
                        ++newNeighbors[r][c+1];
                        ++newNeighbors[r+1][c+1];
                        ++newNeighbors[r+1][c];
                        ++newNeighbors[r+1][c-1];
                        ++newNeighbors[r][c-1];
                    }
                }
            }
            // for the last row
            else if(r == (rows - 1)){
                // first column
                if(c == 0){
                    if(someGrid->getCell(r,c) == 'X'){
                        ++newNeighbors[r][c+1];
                        ++newNeighbors[r-1][c+1];
                        ++newNeighbors[r-1][c];
                    }
                }
                // last column
                else if(c == (columns-1)){
                    if(someGrid->getCell(r,c) == 'X'){
                        ++newNeighbors[r][c-1];
                        ++newNeighbors[r-1][c-1];
                        ++newNeighbors[r-1][c];
                    }
                }
                // middle column
                else{
                    if(someGrid->getCell(r,c) == 'X'){
                        ++newNeighbors[r][c+1];
                        ++newNeighbors[r-1][c+1];
                        ++newNeighbors[r-1][c];
                        ++newNeighbors[r-1][c-1];
                        ++newNeighbors[r][c-1];
                    }
                }
            }
            // for the middle rows
            else{
                // first column
                if(c == 0){
                    if(someGrid->getCell(r,c) == 'X'){
                        ++newNeighbors[r-1][c];
                        ++newNeighbors[r-1][c+1];
                        ++newNeighbors[r][c+1];
                        ++newNeighbors[r+1][c+1];
                        ++newNeighbors[r+1][c];
                    }
                }
                // last column
                else if(c == (columns-1)){
                    if(someGrid->getCell(r,c) == 'X'){
                        ++newNeighbors[r-1][c];
                        ++newNeighbors[r-1][c-1];
                        ++newNeighbors[r][c-1];
                        ++newNeighbors[r+1][c-1];
                        ++newNeighbors[r+1][c];
                    }
                }
                // middle columns
                else{
                    if(someGrid->getCell(r,c) == 'X'){
                        ++newNeighbors[r-1][c];
                        ++newNeighbors[r-1][c+1];
                        ++newNeighbors[r][c+1];
                        ++newNeighbors[r+1][c+1];
                        ++newNeighbors[r+1][c];
                        ++newNeighbors[r+1][c-1];
                        ++newNeighbors[r][c-1];
                        ++newNeighbors[r-1][c-1];
                    }
                }
            }
        }
    }
    someGrid->updateNeighbors(newNeighbors);
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
