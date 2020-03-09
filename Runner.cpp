#include "Runner.h"

Runner::Runner(){
    cout << "How many rows are in the bacteria grid? ";
    cin >> rows;
    cout << "How many columns are in the bacteria grid? ";
    cin >> columns;
    // userGrid = new Grid(rows,columns);
    // userGrid->randomCells();
    // userGrid->printGrid();
    // delete userGrid;
}

Runner::~Runner(){

}

int main(){
    Runner *playing = new Runner();
    return 0;
}
