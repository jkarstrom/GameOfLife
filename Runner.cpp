#include "Runner.h"
#include "FileIO.h"
//Joan Karstrom, Jennifer Nguyen
//ID: 2318286, 2320560
//karstrom@chapman.edu, jenguyen@chapman.edu
//CPSC: 350 - 2
//Assignment 2: Game of Life

//default constructor
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
        cout << "What is the name of the file with the mapping? ";
        cin >> fileRead;
        FileIO::readMapping(fileRead,userGrid);
    }
    else{
        userGrid->randomCells();
    }
    cout << endl;
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
        cin >> fileWrite;
        FileIO::print(fileWrite, userGrid);
    }

    // select mode
    cout << endl;
    cout << "What mode would you like:" << endl
    << "(1) classic" << endl
    << "(2) mirror" << endl
    << "(3) donut" << endl;
    int mode = 0;
    cin >> mode;
    cout << endl;

    // run generations
    Play *newPlay = new Play(userGrid);
    if(mode == 1){
        ClassicMode *cm = new ClassicMode(userGrid);
        while(!newPlay->checkDeath(userGrid)){
            cm->countNeighbors(userGrid);
            newPlay->execute(userGrid);
            if(view == 1){
                userGrid->printGrid();
                cout << endl;
                this_thread::sleep_for (std::chrono::seconds(1));
            }
            else if(view == 2){
                userGrid->printGrid();
                cout << endl;
                string pause;
                getline(cin,pause);
            }
            else{
                if(userGrid->getGenerationNum() <= 100){
                    FileIO::print(fileWrite, userGrid);
                }
            }

        }
        cm = NULL;
        delete cm;
    }
    else if(mode == 2){
        MirrorMode *mm = new MirrorMode(userGrid);
        while(!newPlay->checkDeath(userGrid)){
            mm->countNeighbors(userGrid);
            newPlay->execute(userGrid);
            if(view == 1){
                userGrid->printGrid();
                cout << endl;
                this_thread::sleep_for (std::chrono::seconds(1));
            }
            else if(view == 2){
                userGrid->printGrid();
                cout << endl;
                string pause;
                getline(cin,pause);
            }
            else{
                if(userGrid->getGenerationNum() <= 100){
                    FileIO::print(fileWrite, userGrid);
                }
            }

        }
        mm = NULL;
        delete mm;
    }
    else{
        DoughnutMode *dm = new DoughnutMode(userGrid);
        while(!newPlay->checkDeath(userGrid)){
            dm->countNeighbors(userGrid);
            newPlay->execute(userGrid);
            if(view == 1){
                userGrid->printGrid();
                cout << endl;
                this_thread::sleep_for (std::chrono::seconds(1));
            }
            else if(view == 2){
                userGrid->printGrid();
                cout << endl;
                string pause;
                getline(cin,pause);
            }
            else{
                if(userGrid->getGenerationNum() <= 100){
                    FileIO::print(fileWrite, userGrid);
                }
            }

        }
        dm = NULL;
        delete dm;
    }
    newPlay = NULL;
    delete newPlay;
}

//deconstructor
Runner::~Runner(){
    userGrid = NULL;
    delete userGrid;
}
