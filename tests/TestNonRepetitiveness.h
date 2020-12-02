#pragma once

#ifndef TESTNONREPETITIVENESS_H
#define TESTNONREPETITIVENESS_H

#include <iostream>

using namespace std;


class TestNonRepetitiveness
{
    private:
        const unsigned int seed = 1628868839;

    public:
        void test_equality_on_0100();
        void test_equality_funtion_equals(Coloring coloring);
        void test_equality_funtion_not_equals(Coloring coloring, vector<int> pos);
        void test_nonrepetitiveness_on_index(Coloring coloring);
        void test_nonrepetitiveness(Coloring coloring);
        void test_all(int colors, int maxLength, int repeat = 3);
};

#endif
