#include "Grid.h"
#include <string>

class Runner{
public:
    Runner();
    ~Runner();
private:
    int rows;
    int columns;
    Grid *userGrid;
    int view;

};
