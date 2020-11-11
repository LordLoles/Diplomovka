#include "TestUtils.h"
#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

void TestUtils::test_vectorToLength()
{
    vector<int> v = utils->decimalToBase(63, 2);
    vector<int> result = utils->vectorToLength(v, v.size() + 2);
    for (int i = 0; i < result.size(); i++){
}

void TestUtils::test_getSetToLength()
{

}

void TestUtils::test_all()
{
    cout << "Testing Utils..." << endl;
    test_getSetToLength();
    test_vectorToLength();
}
