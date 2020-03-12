#include "ClassicMode.h"
// #include "MirrorMode.h"
// #include "DonutMode.h"

class Play{
public:
    Play();
    Play(Grid *someGrid);
    ~Play();

    void execute(Grid *someGrid); // applies rules of living or death to all cells
    bool checkDeath(Grid *someGrid); // checks if all bacteria is dead

private:
    int rows = 0;
    int columns = 0;

};
