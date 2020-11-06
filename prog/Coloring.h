#ifndef COLORING_H
#define COLORING_H

#include <vector>
#include <tuple>

class Path
{
    private:
        vector<tuple<int, int, int>> coloring;

    public:
        Path(vector<tuple<int, int, int>> col);
        void printPath(vector<tuple<int, int, int>> vt);
};
#endif