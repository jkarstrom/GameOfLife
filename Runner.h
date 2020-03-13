#include <thread>
#include <chrono>
#include "Play.h"
//Joan Karstrom, Jennifer Nguyen
//ID: 2318286, 2320560
//karstrom@chapman.edu, jenguyen@chapman.edu
//CPSC: 350 - 2
//Assignment 2: Game of Life

class Runner{
public:
    Runner();//default constructor
    ~Runner();//deconstructor

private:
    //vars
    int rows = 0;
    int columns = 0;
    Grid *userGrid;
    int view = 0;
    string fileRead = "NA";
    string fileWrite = "NA";
    int mode = 0;

};
