#include "ClassicMode.h"

ClassicMode::ClassicMode(){
    rows = 5;
    columns = 5;
    newNeighbors = new int*[rows];
    for(int i = 0; i < rows; ++i){
        newNeighbors[i] = new int[columns];
    }
    zeroNeighbors();
    numNeighbors = 0;
}


ClassicMode::ClassicMode(Grid *someGrid){
    rows = someGrid->getRows();
    columns = someGrid->getColumns();
    newNeighbors = new int*[rows];
    for(int i = 0; i < rows; ++i){
        newNeighbors[i] = new int[columns];
    }
    zeroNeighbors();
}

ClassicMode::~ClassicMode(){
    for(int x = 0; x < rows; ++x) {
        delete[] newNeighbors[x];
    }
    delete[] newNeighbors;
}

// zeros newNeighbors array to 0
void ClassicMode::zeroNeighbors(){
    for(int i = 0; i < rows; ++i){
        for(int j = 0; j < columns; ++j){
            newNeighbors[i][j] = 0;
        }
    }
}

// counts and updates the neighborCountGrid
void ClassicMode::countNeighbors(Grid *someGrid){
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
