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
        Path fullPath = Path({{1,2,3}, {5,1,2}, {3,5,14}, {251,15,1244}});
        Path emptyPath = Path();

    public:
        void test_size();
        void test_empty();
        void test_at();
        void test_to_vector();
        void test_push_back();
        void test_pop_back();
        void test_set();
        void test_set_2();
        void test_increment();
        void test_all();
};

#endif