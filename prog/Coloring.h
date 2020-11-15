#include <vector>
#include <tuple>

#ifndef COLORING_H
#define COLORING_H

using namespace std;

class Coloring
{
    private:
        vector<int> coloring;

    public:
        Coloring();
        Coloring(vector<int> &col);
        void printColoring();
        int at(int index);
        bool empty();
        int size();
};
#endif
