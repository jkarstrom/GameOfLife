#include "ClassicMode.h"
#include <string>

class Runner{
public:
    Runner();
    ~Runner();
private:
    int rows = 0;
    int columns = 0;
    Grid *userGrid;
    int view = 0;
    int mode = 0;

};
