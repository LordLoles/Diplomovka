#ifndef TESTCOLORINGGENERATOR_H
#define TESTCOLORINGGENERATOR_H

#include <iostream>
#include <vector>
#include <tuple>
#include "../prog/Coloring.h"
#include "../prog/ColoringGenerators/AllAndWholeColoringGenerator.h"

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
