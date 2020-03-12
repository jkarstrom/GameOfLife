#include "Play.h"

Play::Play(){
    rows = 5;
    columns = 5;
}

Play::Play(Grid *someGrid){
    rows = someGrid->getRows();
    columns = someGrid->getColumns();
}

Play::~Play(){

}

// applies rules of living or death to all cells
void Play::execute(Grid *someGrid){
    for(int r = 0; r < rows; ++r){
        for(int c = 0; c < columns; ++c){
            int neighbors = someGrid->getCellNeighbors(r,c);
            if(neighbors <= 1){
                // dies of loneliness
                someGrid->setCell(r,c,'-');
            }
            else if(neighbors == 2){
                // stable living
            }
            else if(neighbors == 3){
                // ideal for life
                someGrid->setCell(r,c,'X');
            }
            else{
                // dies of crowdedness
                someGrid->setCell(r,c,'-');
            }
        }
    }
}

// checks if all bacteria is dead
bool Play::checkDeath(Grid *someGrid){
    bool state = true;
    int living = 0;
    for(int r = 0; r < rows; ++r){
        for(int c = 0; c < columns; ++c){
            if(someGrid->getCell(r,c) == 'X'){
                ++living;
            }
        }
    }
    if(living > 0){
        state = false;
    }
    return state;
}
