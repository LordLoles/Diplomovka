#ifndef TESTPARTIALCOLORINGGENERATOR_H
#define TESTPARTIALCOLORINGGENERATOR_H

#include <iostream>
#include <vector>
#include <tuple>
#include "../prog/Coloring.h"
#include "../prog/ColoringGenerators/PartialColoringGenerator.h"

using namespace std;


class TestPartialColoringGenerator
{
    public:
        void test_canIncrement();
        void test_increment();
        void test_canBeEnlarged();
        void test_enlarge();
        void test_shrink();
        void test_shrinkUntilCanIncrement();

        void test_initialColoring();
        void test_nextColoring();
        void test_skipColoring();
        void test_isFullColoring();

        void test_empty_path();
        void test_1_sized_path();
        void test_2_sized_path();
        void test_3_sized_path();

        void test_all();
};

#endif
