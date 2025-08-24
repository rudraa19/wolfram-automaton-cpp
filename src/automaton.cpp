#include "automaton.h"
#include <iostream>
#include <bitset>

using namespace std;

Automaton::Automaton(int gridSize, int rule) : GRID_SIZE(gridSize), grid(gridSize, 0), rule(rule) {}

void Automaton::setup()
{
    grid[GRID_SIZE / 2] = 1;
    string temp = bitset<8>(rule).to_string();
    for (int i = 0; i < 8; i++)
        rule_set[7 - i] = (temp[i] == '0') ? 0 : 1;
}

void Automaton::print_grid()
{
    for (int i : grid)
        cout << (i ? "██" : "  ");
    cout << endl;
}

int Automaton::current_state(int x)
{
    x += GRID_SIZE;

    int prev = grid[(x - 1) % GRID_SIZE];
    int curr = grid[x % GRID_SIZE];
    int next = grid[(x + 1) % GRID_SIZE];

    return (prev << 2 | curr << 1 | next);
}

void Automaton::update_grid()
{
    vector<int> next = grid;

    for (int i = 0; i < GRID_SIZE; i++)
        next[i] = rule_set[current_state(i)];

    grid = next;
}