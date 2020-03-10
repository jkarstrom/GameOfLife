#include "Grid.h"

Grid::Grid(){
    rowCount = 5;
    columnCount = 5;
    generationGrid = new char*[rowCount];
    for(int i = 0; i < rowCount; ++i){
        generationGrid[i] = new char[columnCount];
    }
    neighborCountGrid = new int*[rowCount];
    for(int j = 0; j < rowCount; ++j){
        neighborCountGrid[j] = new int[columnCount];
    }
    fillGrid();
}

Grid::Grid(int row, int column){
    rowCount = row;
    columnCount = column;
    generationGrid = new char*[rowCount];
    for(int i = 0; i < rowCount; ++i){
        generationGrid[i] = new char[columnCount];
    }
    neighborCountGrid = new int*[rowCount];
    for(int j = 0; j < rowCount; ++j){
        neighborCountGrid[j] = new int[columnCount];
    }
    fillGrid();
}

Grid::~Grid(){
    for(int x = 0; x < rowCount; ++x) {
        delete[] generationGrid[x];
        delete[] neighborCountGrid[x];
    }
    delete[] generationGrid;
    delete[] neighborCountGrid;
}

void Grid::fillGrid(){
    for(int r = 0; r < rowCount; ++r){
        for(int c = 0; c < columnCount; ++c){
            generationGrid[r][c] = '\n';
            neighborCountGrid[r][c] = 0;
        }
    }
}

void Grid::assignCells(char **arr){
    for(int r = 0; r < rowCount; ++r){
        for(int c = 0; c < columnCount; ++c){
            generationGrid[r][c] = arr[r][c];
        }
    }
}

void Grid::updateNeighbors(int **arr){
    for(int r = 0; r < rowCount; ++r){
        for(int c = 0; c < columnCount; ++c){
            neighborCountGrid[r][c] = arr[r][c];
        }
    }
}

void Grid::randomCells(){
    float density = (float)(rand())/(float)(RAND_MAX);
    for(int r = 0; r < rowCount; ++r){
        for(int c = 0; c < columnCount; ++c){
            float cellOccupied = (float)(rand())/(float)(RAND_MAX);
            if(cellOccupied <= density){
                generationGrid[r][c] = 'X';
            }
            else{
                generationGrid[r][c] = '-';
            }
        }
    }
}


int Grid::getRows(){
    return rowCount;
}

int Grid::getColumns(){
    return columnCount;
}

void Grid::printGrid(){
    for(int r = 0; r < rowCount; ++r){
        for(int c = 0; c < columnCount; ++c){
            cout << generationGrid[r][c];
        }
        cout << endl;
    }
}

int main(){
    Grid *userGrid = new Grid(2,2);
    userGrid->randomCells();
    userGrid = NULL;
    delete userGrid;
}
