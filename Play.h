#include "ClassicMode.h"

class Play{
public:
    Play();
    Play(Grid *someGrid);
    ~Play();
    void execute(Grid *someGrid);
    bool checkDeath(Grid *someGrid);

private:
    int rows = 0;
    int columns = 0;
};
