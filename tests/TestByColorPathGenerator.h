#ifndef TESTBYCOLORPATHGENERATOR_H
#define TESTBYCOLORPATHGENERATOR_H

#include "../prog/PathGenerators/ByColorPathGenerator.h"
#include <iostream>
#include <vector>
#include <tuple>

using namespace std;


class TestByColorPathGenerator
{
    public:
        void test_generateNextColor();
        void test_getFirstNotFullVertex();
        void test_isColorDisjunct();
        void test_deleteColorBeingGenerated();
        void test_nextFullPath();
        void test_all();
};

#endif
