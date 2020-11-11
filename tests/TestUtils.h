#ifndef TESTPATH_H
#define TESTPATH_H

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
        void test_getSetToLength();
        void test_all();
};

#endif