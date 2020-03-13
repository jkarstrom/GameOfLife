#include "MirrorMode.h"
//Joan Karstrom, Jennifer Nguyen
//ID: 2318286, 2320560
//karstrom@chapman.edu, jenguyen@chapman.edu
//CPSC: 350 - 2
//Assignment 2: Game of Life

//default constructor
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

//overload constructor
MirrorMode::MirrorMode(Grid *someGrid)
{
  rows = someGrid->getRows();
  columns = someGrid->getColumns();
  newNeighbors = new int*[rows];
  for(int i = 0; i < rows; ++i){
      newNeighbors[i] = new int[columns];
  }
  zeroNeighbors();
}

//deconstructor
MirrorMode::~MirrorMode()
{
  for(int x = 0; x < rows; ++x) {
      delete[] newNeighbors[x];
  }
  delete[] newNeighbors;
}

// zeros newNeighbors array to 0
void MirrorMode::zeroNeighbors()
{
    for(int i = 0; i < rows; ++i){
        for(int j = 0; j < columns; ++j){
            newNeighbors[i][j] = 0;
        }
    }
}

// counts and updates the neighborCountGrid
void MirrorMode::countNeighbors(Grid *someGrid){
    zeroNeighbors();
    for(int r = 0; r < rows; ++r){
        for(int c = 0; c < columns; ++c){
            // for the top row
            if(r == 0){
                // first column
                if(c == 0){
                    if(someGrid->getCell(r,c) == 'X'){
                        newNeighbors[r][c]+=3;
                        ++newNeighbors[r][c+1];
                        ++newNeighbors[r+1][c+1];
                        ++newNeighbors[r+1][c];
                    }
                }
                // last column
                else if(c == (columns-1)){
                    if(someGrid->getCell(r,c) == 'X'){
                        newNeighbors[r][c]+=3;
                        ++newNeighbors[r][c-1];
                        ++newNeighbors[r+1][c-1];
                        ++newNeighbors[r+1][c];
                    }
                }
                // middle columns
                else{
                    if(someGrid->getCell(r,c) == 'X'){
                        newNeighbors[r][c]+=1;
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
                        newNeighbors[r][c]+=3;
                        ++newNeighbors[r][c+1];
                        ++newNeighbors[r-1][c+1];
                        ++newNeighbors[r-1][c];
                    }
                }
                // last column
                else if(c == (columns-1)){
                    if(someGrid->getCell(r,c) == 'X'){
                        newNeighbors[r][c]+=3;
                        ++newNeighbors[r][c-1];
                        ++newNeighbors[r-1][c-1];
                        ++newNeighbors[r-1][c];
                    }
                }
                // middle column
                else{
                    if(someGrid->getCell(r,c) == 'X'){
                        newNeighbors[r][c]+=1;
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
                        newNeighbors[r][c]+=1;
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
                        newNeighbors[r][c]+=1;
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
