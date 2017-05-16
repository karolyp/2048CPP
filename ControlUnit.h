#include "Table.h"

class ControlUnit
{
public:
    ControlUnit();
    ~ControlUnit();
    void start();
    void drawTable();
    void drawValues();

    void core();
    void merge(int be, Table& t);
    void addTile();
    bool contains(int value);



protected:

private:
    Table t;
    Table t0;
    int score;

};
