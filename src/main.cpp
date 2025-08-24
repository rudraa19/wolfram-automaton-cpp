#include "automaton.h"
#include <iostream>
#include <unistd.h>

#define GRID_SIZE 100

using namespace std;

int main()
{
    int rule;
    cout << "Enter rule: ";
    cin >> rule;

    Automaton automaton(GRID_SIZE, rule);
    automaton.setup();

    while (true)
    {
        automaton.print_grid();
        automaton.update_grid();
        usleep(20000);
    }

    return 0;
}