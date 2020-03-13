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
  numNeighbors = 0;
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
  numNeighbors = 0;
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
    numNeighbors = 0;
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
                        numNeighbors+= 3;
                    }
                }
                // last column
                else if(c == (columns-1)){
                    if(someGrid->getCell(r,c) == 'X'){
                        ++newNeighbors[r][c-1];
                        ++newNeighbors[r+1][c-1];
                        ++newNeighbors[r+1][c];
                        numNeighbors+= 3;
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
                        numNeighbors++;
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
                        numNeighbors+= 3;
                    }
                }
                // last column
                else if(c == (columns-1)){
                    if(someGrid->getCell(r,c) == 'X'){
                        ++newNeighbors[r][c-1];
                        ++newNeighbors[r-1][c-1];
                        ++newNeighbors[r-1][c];
                        numNeighbors+= 3;
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
                        numNeighbors++;
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
                        numNeighbors+= 3;
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
                        numNeighbors+= 3;
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
                        numNeighbors++;
                    }
                }
            }
        }
    }
    someGrid->updateNeighbors(newNeighbors);
}

int MirrorMode::getNumNeighboors()
{
  return numNeighbors;
}
