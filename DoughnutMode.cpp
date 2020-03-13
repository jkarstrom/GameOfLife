#include "DoughnutMode.h"

DoughnutMode::DoughnutMode()
{
  rows = 5;
  columns = 5;
  newNeighbors = new int*[rows];
  for(int i = 0; i < rows; ++i){
      newNeighbors[i] = new int[columns];
  }
  zeroNeighbors();
}

DoughnutMode::DoughnutMode(Grid *someGrid)
{
  rows = someGrid->getRows();
  columns = someGrid->getColumns();
  newNeighbors = new int*[rows];
  for(int i = 0; i < rows; ++i){
      newNeighbors[i] = new int[columns];
  }
  zeroNeighbors();
}

DoughnutMode::~DoughnutMode()
{
  for(int x = 0; x < rows; ++x) {
      delete[] newNeighbors[x];
  }
  delete[] newNeighbors;
}

void DoughnutMode::zeroNeighbors(){
    for(int i = 0; i < rows; ++i){
        for(int j = 0; j < columns; ++j){
            newNeighbors[i][j] = 0;
        }
    }
}

void DoughnutMode::countNeighbors(Grid *someGrid){
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
                        ++newNeighbors[r+1][columns-1];
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
                        ++newNeighbors[r][0];
                        ++newNeighbors[r+1][0];
                        ++newNeighbors[rows-1][c];
                        ++newNeighbors[rows-1][c-1];
                        ++newNeighbors[rows-1][0];
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
                        ++newNeighbors[rows-1][c];
                        ++newNeighbors[rows-1][c+1];
                        ++newNeighbors[rows-1][c-1];
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
                        ++newNeighbors[0][c];
                        ++newNeighbors[0][c+1];
                        ++newNeighbors[r][columns-1];
                        ++newNeighbors[r-1][columns-1];
                        ++newNeighbors[0][columns-1];
                    }
                }
                // last column
                else if(c == (columns-1)){
                    if(someGrid->getCell(r,c) == 'X'){
                        ++newNeighbors[r][c-1];
                        ++newNeighbors[r-1][c-1];
                        ++newNeighbors[r-1][c];
                        ++newNeighbors[r][0];
                        ++newNeighbors[r-1][0];
                        ++newNeighbors[0][c-1];
                        ++newNeighbors[0][c];
                        ++newNeighbors[0][0];
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
                        ++newNeighbors[0][c];
                        ++newNeighbors[0][c-1];
                        ++newNeighbors[0][c+1];
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
                        ++newNeighbors[r][columns-1];
                        ++newNeighbors[r-1][columns-1];
                        ++newNeighbors[r+1][columns-1];
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
                        ++newNeighbors[r][0];
                        ++newNeighbors[r+1][0];
                        ++newNeighbors[r-1][0];
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
