#ifndef TESTPATH_H
#define TESTPATH_H

#include "../prog/Path.h"
#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

class TestPath
{
    private:
        vector<tuple<int, int, int>> input = {{1,2,3}, {5,1,2}, {3,5,14}, {251,15,1244}};
        Path* fullPath = new Path(input);
        Path* emptyPath = new Path();

    public:
        void test_size_1();
        void test_size_2();
        void test_empty_1();
        void test_empty_2();
        void test_at_full();
        void test_all();
};

#endif