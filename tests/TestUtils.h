#ifndef TESTUTILS_H
#define TESTUTILS_H

#include "../prog/Utils.h"
#include "../prog/Utils.cpp"
#include <iostream>
#include <vector>
#include <tuple>

using namespace std;


class TestUtils
{
    private:
        Utils* utils = new Utils();

    public:
        void test_vectorToLength();
        void test_vectorToLength_2();
        void test_getSetToLength(int length);
        void test_decimalToBase();
        void test_digitsToInt();
        void test_all(int repeat = 3);
        void test_getSubsetsOfLength3(int setSize);
};

#endif
