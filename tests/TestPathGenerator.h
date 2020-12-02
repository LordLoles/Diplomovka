#ifndef TESTPATHGENERATOR_H
#define TESTPATHGENERATOR_H

#include "../prog/PathGenerator.h"
#include "../prog/PathGenerator.cpp"
#include <iostream>
#include <vector>
#include <tuple>

using namespace std;


class TestPathGenerator //namespace
{
    public:
        void test_2_colors();
        void test_3_colors();
        void test_4_colors();
        void test_all();
};

#endif
