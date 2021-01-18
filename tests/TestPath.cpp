#include "TestPath.h"
#include <iostream>
#include <vector>
#include <tuple>

using namespace std;


void TestPath::test_size_1()
{
    if (emptyPath.size() != 0) cout << "size should be zero" << endl;
}
void TestPath::test_size_2()
{
    if (fullPath.size() != 4) cout << "size should be 4" << endl;
}

void TestPath::test_empty_1()
{
    if (!emptyPath.empty()) cout << "path should be empty" << endl;
}

void TestPath::test_empty_2()
{
    if (fullPath.empty()) cout << "path should not be empty" << endl;
}

/* https://stackoverflow.com/questions/2350489/how-to-catch-segmentation-fault-in-linux
void test_at_empty()
{
    try
    {
        emptyPath->at(0);
        cout << "should produce seg fault exception" << endl;
    }
    catch(const std::exception& e) {cout << "shouldsdfsgdfgn" << endl;}
}*/

void TestPath::test_at_full()
{
    if (!get<0>(fullPath.at(0)) == 1 ||
        !get<2>(fullPath.at(2)) == 5 ||
        !get<1>(fullPath.at(3)) == 251)
            cout << "should have correct values" << endl;
}

void TestPath::test_all()
{
    cout << "Testing Path..." << endl;
    test_size_1();
    test_size_2();
    test_empty_1();
    //test_at_empty();
    test_at_full();
}
