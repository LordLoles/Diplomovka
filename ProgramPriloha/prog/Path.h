#ifndef PATH_H
#define PATH_H

#include <vector>
#include <tuple>
#include <array>

using namespace std;

//template<int length>
class Path
{
    private:
        //array<array<int, 3>, length> path;
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
        vector<array<int, 3>> to_vector() const;
        Path push_back(array<int, 3> list) const;
        Path pop_back() const;
        Path set(int index, array<int, 3> value) const;
        Path set(int index, int position, int color) const;
        Path increment(int index, int position) const;
};

#endif
