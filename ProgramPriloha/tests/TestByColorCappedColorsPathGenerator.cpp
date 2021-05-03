#include "TestByColorCappedColorsPathGenerator.h"
#include <iostream>
#include <vector>
#include <tuple>
#include <stdlib.h>
#include <time.h>

using namespace std;


void TestByColorCappedColorsPathGenerator::test_nextFullPathGenerator()
{
    ByColorCappedColorsPathGenerator pathGenerator = ByColorCappedColorsPathGenerator(2, 2);
    bool isFull;

    isFull = pathGenerator.nextFullPath();
    if (!isFull || pathGenerator.lastResult.at(0) != array<int, 3>{0, 1, -1} || pathGenerator.lastResult.at(1) != array<int, 3>{-1, -1, -1})
        {cout << "test_nextFullPathGenerator(): path should be {0, 1, -1} {-1, -1, -1}, but was "; pathGenerator.lastResult.printPath();}

    isFull = pathGenerator.nextFullPath();
    if (!isFull || pathGenerator.lastResult.at(0) != array<int, 3>{0, 1, -1} || pathGenerator.lastResult.at(1) != array<int, 3>{0, -1, -1})
        {cout << "test_nextFullPathGenerator(): path should be {0, 1, -1} {0, -1, -1}, but was "; pathGenerator.lastResult.printPath();}

    isFull = pathGenerator.nextFullPath();
    if (!isFull || pathGenerator.lastResult.at(0) != array<int, 3>{0, 1, -1} || pathGenerator.lastResult.at(1) != array<int, 3>{0, 1, -1})
        {cout << "test_nextFullPathGenerator(): path should be {0, 1, -1} {0, 1, -1}, but was "; pathGenerator.lastResult.printPath();}

    isFull = pathGenerator.nextFullPath();
    if (isFull)
        {cout << "test_nextFullPathGenerator(): path should be empty, but was "; pathGenerator.lastResult.printPath();}
}

void TestByColorCappedColorsPathGenerator::test_all()
{
    cout << "Testing ByColorCappedColorsPathGenerator..." << endl;
    
    test_nextFullPathGenerator();
}
