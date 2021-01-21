#ifndef PATH_H
#define PATH_H

#include <vector>
#include <tuple>
#include <array>

using namespace std;

class Path
{
    private:
        vector<array<int, 3>> path;

    public:
        Path();
        Path(const vector<array<int, 3>> &path_to_store);
        Path(vector<array<int, 3>> && path_to_store);
        void printPath();
        string to_string();
        array<int, 3> at(int index) const;
        bool empty();
        int size();
};

#endif
