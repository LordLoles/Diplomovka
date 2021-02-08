#ifndef TESTBYCOLORPATHGENERATOR_H
#define TESTBYCOLORPATHGENERATOR_H

#include "../prog/PathGenerators/ByColorPathGenerator.h"

using namespace std;


class TestByColorPathGenerator
{
    public:
    
        void test_setColor();
        void test_updateColorsUsage();
        void test_isLast();
        void test_reset();
        void test_incrementVertexPostion();
        void test_incrementVertex();
        void test_increment();
        void test_initialPath();
        void test_nextPath();

        void test_all();
};

#endif
