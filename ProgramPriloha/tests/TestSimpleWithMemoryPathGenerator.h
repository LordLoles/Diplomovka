#ifndef TESTSIMPLEWITHMEMORYPATHGENERATOR_H
#define TESTSIMPLEWITHMEMORYPATHGENERATOR_H

#include "../prog/PathGenerators/SimpleWithMemoryPathGenerator.h"

using namespace std;


class TestSimpleWithMemoryPathGenerator
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
