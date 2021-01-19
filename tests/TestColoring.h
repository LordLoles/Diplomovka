#pragma once
#ifndef TESTCOLORING_H
#define TESTCOLORING_H

#include "../prog/Coloring.h"
#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

class TestColoring
{
    private:
        vector<int> input = {1, 2, 3, 5, 1, 2, 3, 5, 14, 251, 15, 1244};
        Coloring fullColoring = Coloring(input);
        Coloring emptyColoring = Coloring();

    public:
        void test_size_1();
        void test_size_2();
        void test_empty_1();
        void test_empty_2();
        void test_full_of_zeroes();
        void test_at_full();
        void test_copy();
        void test_equals();
        void test_push_back();
        void test_pop_back();
        void test_set();
        void test_all();
};

#endif