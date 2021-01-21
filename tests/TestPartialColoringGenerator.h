#ifndef TESTWHOLECOLORINGGENERATOR_H
#define TESTWHOLECOLORINGGENERATOR_H

#include <iostream>
#include <vector>
#include <tuple>
#include "../prog/Coloring.h"
#include "../prog/ColoringGenerators/WholeColoringGenerator.h"

using namespace std;


class TestWholeColoringGenerator //namespace
{
    public:
        void test_empty_path();
        void test_1_sized_path();
        void test_2_sized_path();
        void test_all();
};

#endif
