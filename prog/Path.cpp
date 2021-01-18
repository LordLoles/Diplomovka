#include "Path.h"
#include <iostream>
#include "./ToStringPatch.h"

using namespace std;


Path::Path() { }

Path::Path(const vector<tuple<int, int, int>> &path_to_store) : path(path_to_store) { }

Path::Path(vector<tuple<int, int, int>> && path_to_store) : path(path_to_store) { }


void Path::printPath()
{
    cout << to_string() << endl;
}

string Path::to_string()
{
    string result = "";
    for (tuple<int, int, int> &list : path)
        result += (string)"[" + std::to_string(get<0>(list)) + (string)" " + std::to_string(get<1>(list)) + (string)" " + std::to_string(get<2>(list)) + (string)"] ";
    return result;
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
