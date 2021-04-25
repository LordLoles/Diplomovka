#ifndef TESTUTILS_H
#define TESTUTILS_H

#include "../prog/Utils.h"
#include <iostream>
#include <vector>
#include <tuple>

using namespace std;


class TestUtils //namespace
{
    public:
        void test_vectorToLength();
        void test_vectorToLength_2();
        void test_getSetToLength(int length);
        void test_decimalToBase();
        void test_digitsToInt();
        void test_getSubsetsOfLength3(int setSize);
        void test_stringTo3Vector();
        void test_getColorsUsage();

        void test_all(int repeat = 3);
};

#endif
