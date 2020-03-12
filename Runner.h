#include <thread>
#include <chrono>
#include "Play.h"

class Runner{
public:
    Runner();
    ~Runner();

private:
    int rows = 0;
    int columns = 0;
    Grid *userGrid;
    int view = 0;
    string filename = "NONE";
    int mode = 0;

};
