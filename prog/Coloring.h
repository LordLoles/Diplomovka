#pragma once

#ifndef COLORING_H
#define COLORING_H

#include <vector>
#include <tuple>

using namespace std;

class Coloring
{
    private:
        vector<int> coloring;

    public:
        Coloring();
        Coloring(vector<int> &col);
        void printColoring();
        Coloring* copy(int from, int to); //unused
        bool equals(Coloring* another); //unused
        int at(int index);
        bool empty();
        int size();
        vector<int> toVector();
};
#endif
