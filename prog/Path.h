#ifndef PATH_H
#define PATH_H

#include <vector>
#include <tuple>

class Path
{
    private:
        vector<tuple<int, int, int>> path;

    public:
        Path(vector<tuple<int, int, int>> path_to_store);
        static void printPath(vector<tuple<int, int, int>> vt);
        void printPath();
};

#endif