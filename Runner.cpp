#include "Runner.h"

Runner::Runner(){
    cout << "How many rows are in the bacteria grid? ";
    cin >> rows;
    cout << "How many columns are in the bacteria grid? ";
    cin >> columns;
    Grid *userGrid = new Grid(rows,columns);
    cout << "Do you have a mapping of the bacteria already? y/n ";
    char mapping;
    cin >> mapping;
    if(mapping == 'y'){
        cout << "Provide the mapping line by line: " << endl;
        // for(int r = 0; r < rows; ++r){
        //     string line;
        //     cin >> line;
        //     for(int c = 0; c < columns; ++c){
        //         userGrid[r][c] = line.at(c);
        //     }
        // }
    }
    // else{
    //     userGrid->randomCells();
    // }
    // userGrid->printGrid();

    // insert how the user wants to view the generations
    // Segmentation fault in this part somewhere
    delete userGrid;
}

Runner::~Runner(){

}

int main(){
    Runner *playing = new Runner();
    return 0;
}
