#include "ClassicMode.h"

ClassicMode::ClassicMode(){
    newNeighbors = new int*[Grid::getRows()];
    for(int i = 0; i < Grid::getRows(); ++i){
        newNeighbors[i] = new int[Grid::getColumns()];
        for(int j = 0; j < Grid::getColumns(); ++j){
            newNeighbors[i][j] = 0;
        }
    }
}

ClassicMode::~ClassicMode(){

}

void ClassicMode::countNeighbors(){
    for(int r = 0; r < Grid::getRows(); ++r){
        for(int c = 0; c < Grid::getColumns(); ++c){
            if(r == 0 && c == 0){
                if(Grid::generationGrid[r][c] == "X"){
                    ++newNeighbors[r][c+1];
                    ++newNeighbors[r+1][c+1];
                    ++newNeighbors[r+1][c];
                }
            }
            else if(r == 0 && c == (Grid::getColumns()-1)){
                if(Grid::generationGrid[r][c] == "X"){
                    ++newNeighbors[r][c-1];
                    ++newNeighbors[r-1][c-1];
                    ++newNeighbors[r-1][c];
                }
            }
            else if(r == 0){
                if(Grid::generationGrid[r][c] == "X"){
                    ++newNeighbors[r][c+1];
                    ++newNeighbors[r+1][c+1];
                    ++newNeighbors[r+1][c];
                    ++newNeighbors[r-1][c-1];
                    ++newNeighbors[r][c-1];
                }
            }
        }
    }
}
