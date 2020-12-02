#ifndef TESTCOLORINGGENERATOR_H
#define TESTCOLORINGGENERATOR_H

#include "../prog/ColoringGenerator.h"
#include "../prog/ColoringGenerator.cpp"
#include <iostream>
#include <vector>
#include <tuple>
#include "../prog/Coloring.h"

using namespace std;


class TestColoringGenerator //namespace
{
    public:
        void test_empty_path();
        void test_1_sized_path();
        void test_2_sized_path();
        void test_all();
};

#endif
