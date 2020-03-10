#include "Runner.h"

Runner::Runner(){
    cout << "How many rows are in the bacteria grid? ";
    cin >> rows;
    cout << "How many columns are in the bacteria grid? ";
    cin >> columns;
    Grid *userGrid = new Grid(rows,columns);

    cout << "Do you have a mapping of the bacteria already? (y/n) ";
    char mapping;
    cin >> mapping;
    if(mapping == 'y'){
        // ask for map file and assignCells
        // userGrid->assignCells(userMap);
    }
    else{
        userGrid->randomCells();
    }
    userGrid->printGrid();

    cout << endl;
    cout << "How would you like to view the generations:" << endl
    << "(1) with a pause between each generation" << endl
    << "(2) I press Enter to generate the next generation" << endl
    << "(3) print them into a file I have" << endl;
    cin >> view;

    cout << endl;
    cout << "What mode would you like:" << endl
    << "(1) classic" << endl
    << "(2) mirror" << endl
    << "(3) donut" << endl;
    cin >> mode;

}

Runner::~Runner(){
    userGrid = NULL;
    delete userGrid;
}

int main(){
    Runner *playing = new Runner();
    return 0;
}
