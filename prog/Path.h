#include <vector>
#include <tuple>

#ifndef PATH_H
#define PATH_H

using namespace std;

class Path
{
    private:
        vector<tuple<int, int, int>> path;

    public:
        Path();
        Path(const vector<tuple<int, int, int>> &path_to_store);
        Path(vector<tuple<int, int, int>> && path_to_store);
        void printPath();
        tuple<int, int, int> at(int index) const;
        bool empty();
        int size();
};

#endif
