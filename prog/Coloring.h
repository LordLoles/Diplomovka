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
        Coloring(const vector<int> &col);
        Coloring(vector<int> &&col);
        void printColoring() const;
        string to_string() const;
        Coloring* copy(int from, int to) const; //unused
        bool equals(Coloring* another) const; //unused
        int at(int index) const;
        bool empty() const;
        int size() const;
        vector<int> toVector() const;
};
#endif
