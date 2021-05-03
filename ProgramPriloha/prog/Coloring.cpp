#include "Coloring.h"
#include <iostream>
#include <vector>
#include "./ToStringPatch.h"

using namespace std;


Coloring::Coloring() { }

Coloring::Coloring(const vector<int> &col) : coloring (col) { }

Coloring::Coloring(vector<int> &&col) : coloring (col) { }

Coloring::Coloring(int length) : coloring (vector<int>(length, 0)) { }


void Coloring::printColoring() const
{
    cout << to_string() << endl;
}

string Coloring::to_string() const
{
    if (coloring.empty()) return "empty";
    string result = "";
    for (const int &vertex : coloring)
        result += std::to_string(vertex) + " ";
    return result;
}

Coloring Coloring::copy(int from, int to) const
{
    vector<int>::const_iterator first = coloring.begin() + from;
    vector<int>::const_iterator last = coloring.begin() + to;
    vector<int> newVec(first, last);
    return Coloring(newVec);
}

bool Coloring::equals(Coloring another) const
{
    if (size() != another.size()) return false;

    for (int i = 0; i < size(); i++)
    {
        if (at(i) != another.at(i)) return false;
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

Coloring Coloring::push_back(int i) const
{
    vector<int> res = toVector();
    res.push_back(i);
    return Coloring(res);
}


Coloring Coloring::pop_back() const
{
    vector<int> res = toVector();
    res.pop_back();
    return Coloring(res);
}

Coloring Coloring::set(int index, int value) const
{
    vector<int> res = toVector();
    res[index] = value;
    return Coloring(res);
}
