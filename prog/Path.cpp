#include "Path.h"
#include <iostream>

using namespace std;


Path::Path(vector<tuple<int, int, int>> path_to_store)
{
    path = path_to_store;
}

void Path::printPath(vector<tuple<int, int, int>> vt)
{
    for (tuple<int, int, int> &list : vt)
        cout << "[" << get<0>(list) << " "<< get<1>(list) << " "<< get<2>(list) << "] ";
    cout << endl;
}

void Path::printPath()
{
    printPath(path);
}
