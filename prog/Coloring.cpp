#include "Coloring.h"
#include <iostream>

using namespace Coloring;
using namespace std;


Coloring(vector<tuple<int, int, int>> col)
{
    coloring = col;
}

void printColoring(vector<tuple<int, int, int>> vt)
{
    for (tuple<int, int, int> &list : vt)
        cout << "[" << get<0>(list) << " "<< get<1>(list) << " "<< get<2>(list) << "] ";
    cout << endl;
}
