#ifndef AUTOMATON_H
#define AUTOMATON_H

#include <vector>
using namespace std;

class Automaton
{
private:
    int GRID_SIZE;
    vector<int> grid;
    int rule;
    int rule_set[8];

public:
    Automaton(int grid_size, int rule);
    void setup();
    void print_grid();
    void update_grid();
};

#endif