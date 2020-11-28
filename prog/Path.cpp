#include "Path.h"
#include <iostream>

using namespace std;


Path::Path() { }

Path::Path(const vector<tuple<int, int, int>> &path_to_store) : path(path_to_store) { }

Path::Path(vector<tuple<int, int, int>> && path_to_store) : path(path_to_store) { }


void Path::printPath()
{
    for (tuple<int, int, int> &list : path)
        cout << "[" << get<0>(list) << " "<< get<1>(list) << " "<< get<2>(list) << "] ";
    cout << endl;
}

tuple<int, int, int> Path::at(int index) const
{
    return path[index];
}

bool Path::empty()
{
    return path.empty();
}

int Path::size()
{
    return path.size();
}
