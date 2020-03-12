#include "Runner.h"

Runner::Runner(){
    // establish initial grid size
    cout << "How many rows are in the bacteria grid? ";
    cin >> rows;
    cout << "How many columns are in the bacteria grid? ";
    cin >> columns;
    Grid *userGrid = new Grid(rows,columns);

    // fill initial grid with values
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
    cout << "Initial generation: " << endl;
    userGrid->printGrid();

    // determine generation display option
    cout << endl;
    cout << "How would you like to view the generations:" << endl
    << "(1) with a pause between each generation" << endl
    << "(2) I press Enter to generate the next generation" << endl
    << "(3) print them into a file I have" << endl;
    int view = 0;
    cin >> view;
    if(view == 3){
        cout << "What is the file name?" << endl;
        cin >> filename;
    }

    // select mode
    cout << endl;
    cout << "What mode would you like:" << endl
    << "(1) classic" << endl
    << "(2) mirror" << endl
    << "(3) donut" << endl;
    int mode = 0;
    cin >> mode;

    // run generations
    Play *newPlay = new Play(userGrid);
    if(mode == 1){
        ClassicMode *cm = new ClassicMode(userGrid);
        while(!newPlay->checkDeath(userGrid)){
            cm->countNeighbors(userGrid);
            newPlay->execute(userGrid);
            userGrid->printGrid();
            cout << endl;
            if(view == 1){
                this_thread::sleep_for (std::chrono::seconds(1));
            }
            else if(view == 2){
                string pause;
                getline(cin,pause);
            }

        }
        cm = NULL;
        delete cm;
    }
    else if(mode == 2){
        // insert mirror mode
    }
    else{
        // insert donut mode
    }
    newPlay = NULL;
    delete newPlay;
}

Runner::~Runner(){
    userGrid = NULL;
    delete userGrid;
}

int main(){
    Runner *playing = new Runner();
    return 0;
}
