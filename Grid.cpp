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

// initializes generationGrid and neighborCountGrid to default values
void Grid::fillGrid(){
    for(int r = 0; r < rowCount; ++r){
        for(int c = 0; c < columnCount; ++c){
            generationGrid[r][c] = '\n';
            neighborCountGrid[r][c] = 0;
        }
    }
}

// used for when user has initial cell mapping
void Grid::assignCells(char **arr){
    for(int r = 0; r < rowCount; ++r){
        for(int c = 0; c < columnCount; ++c){
            generationGrid[r][c] = arr[r][c];
        }
    }
}

// generates a random assort of bacteria based on random density
void Grid::randomCells(){
    srand (time(NULL));
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

// changes the neighborCountGrid
void Grid::updateNeighbors(int **arr){
    for(int r = 0; r < rowCount; ++r){
        for(int c = 0; c < columnCount; ++c){
            neighborCountGrid[r][c] = arr[r][c];
        }
    }
}

// increments generation number
void Grid::updateGeneration(){
    ++generationNum;
}

// change the selected cell value
void Grid::setCell(int row, int column, char bacteria){
    generationGrid[row][column] = bacteria;
}

// returns X if bacteria is alive at cell
char Grid::getCell(int row, int column){
    return generationGrid[row][column];
}

// returns the number of neighbors for a cell
int Grid::getCellNeighbors(int row, int column){
    return neighborCountGrid[row][column];
}

// returns number of rows for grid
int Grid::getRows(){
    return rowCount;
}

// returns number of columns for grid
int Grid::getColumns(){
    return columnCount;
}

int Grid::getGenerationNum(){
    return generationNum;
}

// prints bacteria colony
void Grid::printGrid(){
    cout << "Generation: " << generationNum << endl;
    for(int r = 0; r < rowCount; ++r){
        for(int c = 0; c < columnCount; ++c){
            cout << generationGrid[r][c];
        }
        cout << endl;
    }
}

// prints neighborCountGrid (DELETE BEFORE SUBMISSION)
void Grid::printGrid2(){
    for(int r = 0; r < rowCount; ++r){
        for(int c = 0; c < columnCount; ++c){
            cout << neighborCountGrid[r][c];
        }
        cout << endl;
    }
}
