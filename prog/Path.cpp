#include "Path.h"
#include <iostream>
#include "./ToStringPatch.h"

using namespace std;


Path::Path() { }

Path::Path(const vector<array<int, 3>> &path_to_store) : path(path_to_store) { }

Path::Path(vector<array<int, 3>> && path_to_store) : path(path_to_store) { }


void Path::printPath()
{
    cout << to_string() << endl;
}

string Path::to_string()
{
    string result = "";
    for (array<int, 3> &list : path)
        result += (string)"[" + std::to_string(list[0]) + (string)" " + std::to_string(list[1]) + (string)" " + std::to_string(list[2]) + (string)"] ";
    return result;
}

array<int, 3> Path::at(int index) const
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
