#include "Coloring.h"
#include <iostream>
#include <vector>
#include <tuple>

using namespace std;


Coloring::Coloring(vector<int> &col)
{
    coloring = col;
}

Coloring::Coloring()
{
    coloring = vector<int>();
}

void Coloring::printColoring()
{
    for (int &vertex : coloring)
        cout << vertex << " ";
    cout << endl;
}

bool Coloring::empty()
{
    return coloring.empty();
}

int Coloring::size()
{
    return coloring.size();
}
