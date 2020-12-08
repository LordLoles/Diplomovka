#include "Coloring.h"
#include <iostream>
#include <vector>

using namespace std;


Coloring::Coloring() { }

Coloring::Coloring(const vector<int> &col) : coloring (col) { }

Coloring::Coloring(vector<int> &&col) : coloring (col) { }


void Coloring::printColoring() const
{
    cout << to_string() << endl;
}

string Coloring::to_string() const
{
    string result = "";
    for (const int &vertex : coloring)
        result += std::to_string(vertex) + " ";
    return result;
}

Coloring* Coloring::copy(int from, int to) const
{
    vector<int>::const_iterator first = coloring.begin() + from;
    vector<int>::const_iterator last = coloring.begin() + to;
    vector<int> newVec(first, last);
    return new Coloring(newVec);
}

bool Coloring::equals(Coloring* another) const
{
    if (size() != another->size()) return false;

    for (int i = 0; i < size(); i++)
    {
        if (at(i) != another->at(i)) return false;
    }
    return true;
}

int Coloring::at(int index) const
{
    return coloring[index];
}

bool Coloring::empty() const
{
    return coloring.empty();
}

int Coloring::size() const
{
    return coloring.size();
}

vector<int> Coloring::toVector() const
{
    return coloring;
}
