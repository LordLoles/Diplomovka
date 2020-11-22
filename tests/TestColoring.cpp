#include "TestColoring.h"
#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <algorithm>

using namespace std;



void TestColoring::test_size_1()
{
    if (emptyColoring->size() != 0) cout << "size should be zero" << endl;
}
void TestColoring::test_size_2()
{
    if (fullColoring->size() != 12) cout << "size should be 12" << endl;
}

void TestColoring::test_empty_1()
{
    if (!emptyColoring->empty()) cout << "should be empty" << endl;
}

void TestColoring::test_empty_2()
{
    if (fullColoring->empty()) cout << "should not be empty" << endl;
}

void TestColoring::test_at_full()
{
    if (!(fullColoring->at(0)) == 1 ||
        !(fullColoring->at(2)) == 3 ||
        !(fullColoring->at(9)) == 251)
            cout << "should have correct values" << endl;
}

void TestColoring::test_copy()
{
    //cout << "TODO test_copy" << endl;
}

void TestColoring::test_equals()
{
    //cout << "TODO test_equals" << endl;
}

void TestColoring::test_all()
{
    cout << "Testing Coloring..." << endl;
    test_size_1();
    test_size_2();
    test_empty_1();
    test_at_full();
    test_copy();
    test_equals();
}
