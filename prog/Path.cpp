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

vector<array<int, 3>> Path::to_vector() const
{
    return path;
}

Path Path::push_back(array<int, 3> list) const
{
    vector<array<int, 3>> res = to_vector();
    res.push_back(list);
    return Path(res);
}


Path Path::pop_back() const
{
    vector<array<int, 3>> res = to_vector();
    res.pop_back();
    return Path(res);
}

Path Path::set(int index, array<int, 3> value) const
{
    vector<array<int, 3>> res = to_vector();
    res[index] = value;
    return Path(res);
}


Path Path::set(int index, int position, int color) const
{
    vector<array<int, 3>> res = to_vector();
    res[index][position] = color;
    return Path(res);
}

Path Path::increment(int index, int position) const
{
    return set(index, position, path.at(index).at(position) + 1);
}
