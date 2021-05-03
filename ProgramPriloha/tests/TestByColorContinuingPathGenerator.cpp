#include "TestByColorContinuingPathGenerator.h"
#include <iostream>
#include <vector>
#include <tuple>
#include <stdlib.h>
#include <time.h>

using namespace std;


void TestByColorContinuingPathGenerator::test_nextFullPathGenerator()
{
    //Path path = Path({{0, 1, -1}, {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}, {0, -1, -1}});
    Path path = Path({{0, 1, -1}, {0, -1, -1}, {1, -1, -1}, {-1, -1, -1}});
    ByColorContinuingPathGenerator pathGenerator = ByColorContinuingPathGenerator(path.size(), 2, 7, path);
    bool isFull;

    isFull = pathGenerator.nextFullPath();
    if (!isFull || pathGenerator.lastResult.at(0) != array<int, 3>{0, 1, 2} || pathGenerator.lastResult.at(1) != array<int, 3>{0, 3, 4} || 
        pathGenerator.lastResult.at(2) != array<int, 3>{1, 3, 4} || pathGenerator.lastResult.at(3) != array<int, 3>{2, 3, 4})
        {cout << "test_nextFullPathGenerator(): path should be {0 1 2} {2 3 4} {0 3 4} {1 3 4}, but was "; pathGenerator.lastResult.printPath();}

    isFull = pathGenerator.nextFullPath();
    if (isFull)
        {cout << "test_nextFullPathGenerator(): path should be empty, but was "; pathGenerator.lastResult.printPath();}
}

void TestByColorContinuingPathGenerator::test_all()
{
    cout << "Testing ByColorContinuingPathGenerator..." << endl;
    
    test_nextFullPathGenerator();
}
