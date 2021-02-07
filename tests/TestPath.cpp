#include "TestPath.h"
#include <iostream>
#include <vector>
#include <tuple>

using namespace std;


void TestPath::test_size()
{
    if (emptyPath.size() != 0) {cout << "test_size: size should be zero, path was "; emptyPath.printPath();}
    if (fullPath.size() != 4) {cout << "test_size: size should be 4, path was "; fullPath.printPath();}
}

void TestPath::test_empty()
{
    if (!emptyPath.empty()) {cout << "test_empty: path should be empty, path was "; emptyPath.printPath();}
    if (fullPath.empty()) {cout << "test_empty: path should not be empty, path was "; fullPath.printPath();}
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

void TestPath::test_at()
{
    if (!fullPath.at(0)[0] == 1 ||
        !fullPath.at(2)[2] == 14 ||
        !fullPath.at(3)[0] == 251)
            {cout << "test_at: should have correct values, path was "; fullPath.printPath();}
}

void TestPath::test_to_vector()
{
    vector<array<int, 3>> path = fullPath.to_vector();
    
    if (!path.at(0)[0] == 1 ||
        !path.at(2)[2] == 14 ||
        !path.at(3)[0] == 251)
            cout << "test_to_vector: should have correct values" << endl;
}

void TestPath::test_push_back()
{
    Path path = fullPath.push_back({5, 6, 7});
    if (path.size() != 5 ||
        path.at(4) != array<int, 3>{5, 6, 7})
        {cout << "test_push_back: should have {5, 6, 7} at last index, path was "; path.printPath();}
}

void TestPath::test_pop_back()
{
    Path path = fullPath.pop_back();
    if (path.size() != 3)
        {cout << "test_pop_back: should have size 3, path was "; path.printPath();}
}

void TestPath::test_set()
{
    Path path = fullPath.set(2, {5, 6, 8});
    if (path.size() != 4 ||
        path.at(2) != array<int, 3>{5, 6, 8})
        {cout << "test_set: should have {5, 6, 8} at index 2, path was "; path.printPath();}
}

void TestPath::test_set_2()
{
    Path path = fullPath.set(2, 1, 50);
    if (path.size() != 4 ||
        path.at(2)[1] != 50)
        {cout << "test_set_2: should have 50 at index 2, position 1, path was "; path.printPath();}
}

void TestPath::test_increment()
{
    Path path = fullPath.increment(2, 1);
    if (path.size() != 4 ||
        path.at(2)[1] != 6)
        {cout << "test_increment: should have 6 at index 2, position 1, path was "; path.printPath();}
}


void TestPath::test_all()
{
    cout << "Testing Path..." << endl;
    test_size();
    test_empty();
    test_at();
    test_to_vector();
    test_push_back();
    test_pop_back();
    test_set();
    test_set_2();
    test_increment();
}
