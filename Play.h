#include "ClassicMode.h"
#include "MirrorMode.h"
#include "DoughnutMode.h"
//Joan Karstrom, Jennifer Nguyen
//ID: 2318286, 2320560
//karstrom@chapman.edu, jenguyen@chapman.edu
//CPSC: 350 - 2
//Assignment 2: Game of Life

class Play{
public:
    Play();//default constructor
    Play(Grid *someGrid);//overload constructor
    ~Play();//deconstructor

    //cour functions
    void execute(Grid *someGrid); // applies rules of living or death to all cells
    bool checkDeath(Grid *someGrid); // checks if all bacteria is dead

private:
    //vars
    int rows = 0;
    int columns = 0;

};
