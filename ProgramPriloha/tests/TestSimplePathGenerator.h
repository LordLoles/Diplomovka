#ifndef TESTSIMPLEPATHGENERATOR_H
#define TESTSIMPLEPATHGENERATOR_H

#include "../prog/PathGenerators/SimplePathGenerator.h"
#include <iostream>
#include <vector>
#include <tuple>

using namespace std;


class TestSimplePathGenerator //namespace
{
    public:
        void test_2_colors();
        void test_3_colors();
        void test_4_colors();
        void test_all();
};

#endif
