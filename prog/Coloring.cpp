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

Coloring* Coloring::copy(int from, int to)
{
    vector<int>::const_iterator first = coloring.begin() + from;
    vector<int>::const_iterator last = coloring.begin() + to;
    vector<int> newVec(first, last);
    return new Coloring(newVec);
}

bool Coloring::equals(Coloring* another)
{
    if (size() != another->size()) return false;

    for (int i = 0; i < size(); i++)
    {
        if (at(i) != another->at(i)) return false;
    }
    return true;
}

int Coloring::at(int index)
{
    return coloring[index];
}

bool Coloring::empty()
{
    return coloring.empty();
}

int Coloring::size()
{
    return coloring.size();
}

vector<int> Coloring::toVector()
{
    return coloring;
}
