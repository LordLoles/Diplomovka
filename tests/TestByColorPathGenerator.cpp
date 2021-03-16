#include "TestByColorPathGenerator.h"
#include <iostream>
#include <vector>
#include <tuple>
#include <stdlib.h>
#include <time.h>

using namespace std;


void TestByColorPathGenerator::test_isColorDisjunct()
{
    cout << "TODO test_isColorDisjunct" << endl;
}

void TestByColorPathGenerator::test_getFirstNotFullVertex()
{
    cout << "TODO test_getFirstNotFullVertex" << endl;
}

void TestByColorPathGenerator::test_generateNextColor()
{
    ByColorPathGenerator byColorPathGenerator = ByColorPathGenerator(2, 4);

    byColorPathGenerator.generateNextColor(0);
    if (byColorPathGenerator.lastResult.at(0) != array<int, 3>{0, -1, -1} || byColorPathGenerator.lastResult.at(1) != array<int, 3>{-1, -1, -1})
        {cout << "test_generateNextColor(): should have generated {0, -1, -1} {-1, -1, -1}, but was "; byColorPathGenerator.lastResult.printPath();}

    byColorPathGenerator.generateNextColor(0);
    if (byColorPathGenerator.lastResult.at(0) != array<int, 3>{0, -1, -1} || byColorPathGenerator.lastResult.at(1) != array<int, 3>{0, -1, -1})
        {cout << "test_generateNextColor(): should have generated {0, -1, -1} {0, -1, -1}, but was "; byColorPathGenerator.lastResult.printPath();}

    byColorPathGenerator.generateNextColor(2);
    if (byColorPathGenerator.lastResult.at(0) != array<int, 3>{0, 2, -1} || byColorPathGenerator.lastResult.at(1) != array<int, 3>{0, -1, -1})
        {cout << "test_generateNextColor(): should have generated {0, 2, -1} {0, -1, -1}, but was "; byColorPathGenerator.lastResult.printPath();}

    byColorPathGenerator.generateNextColor(1);
    if (byColorPathGenerator.lastResult.at(0) != array<int, 3>{0, 2, 1} || byColorPathGenerator.lastResult.at(1) != array<int, 3>{0, -1, -1})
        {cout << "test_generateNextColor(): should have generated {0, 2, 1} {0, -1, -1}, but was "; byColorPathGenerator.lastResult.printPath();}

    byColorPathGenerator.generateNextColor(1);
    if (byColorPathGenerator.lastResult.at(0) != array<int, 3>{0, 2, 1} || byColorPathGenerator.lastResult.at(1) != array<int, 3>{0, 1, -1})
        {cout << "test_generateNextColor(): should have generated {0, 2, 1} {0, 1, -1}, but was "; byColorPathGenerator.lastResult.printPath();}

    bool ret = byColorPathGenerator.generateNextColor(1);
    if (ret || byColorPathGenerator.lastResult.at(0) != array<int, 3>{0, 2, -1} || byColorPathGenerator.lastResult.at(1) != array<int, 3>{0, -1, -1})
        {cout << "test_generateNextColor(): should have generated {0, 2, -1} {0, -1, -1}, but was "; byColorPathGenerator.lastResult.printPath();}

    ret = byColorPathGenerator.generateNextColor(1);
    if (!ret || byColorPathGenerator.lastResult.at(0) != array<int, 3>{0, 2, 1} || byColorPathGenerator.lastResult.at(1) != array<int, 3>{0, -1, -1})
        {cout << "test_generateNextColor(): should have generated {0, 2, 1} {0, -1, -1}, but was "; byColorPathGenerator.lastResult.printPath();}

    ret = byColorPathGenerator.generateNextColor(0);
    if (ret || byColorPathGenerator.lastResult.at(0) != array<int, 3>{-1, 2, 1} || byColorPathGenerator.lastResult.at(1) != array<int, 3>{-1, -1, -1})
        {cout << "test_generateNextColor(): should have generated {-1, 2, 1} {-1, -1, -1}, but was "; byColorPathGenerator.lastResult.printPath();}

        
    byColorPathGenerator = ByColorPathGenerator(3, 4);
    byColorPathGenerator.generateNextColor(0);
    byColorPathGenerator.generateNextColor(0);
    byColorPathGenerator.generateNextColor(1);
    byColorPathGenerator.generateNextColor(2);
    if (byColorPathGenerator.lastResult.at(0) != array<int, 3>{0, 1, 2} || 
        byColorPathGenerator.lastResult.at(1) != array<int, 3>{-1, -1, -1} || 
        byColorPathGenerator.lastResult.at(2) != array<int, 3>{0, -1, -1})
        {cout << "test_generateNextColor(): should have generated {0, 1, 2} {-1, -1, -1} {0, -1, -1}, but was "; byColorPathGenerator.lastResult.printPath();}

    byColorPathGenerator.generateNextColor(3);
    byColorPathGenerator.generateNextColor(3);
    if (byColorPathGenerator.lastResult.at(0) != array<int, 3>{0, 1, 2} || 
        byColorPathGenerator.lastResult.at(1) != array<int, 3>{3, -1, -1} || 
        byColorPathGenerator.lastResult.at(2) != array<int, 3>{0, 3, -1})
        {cout << "test_generateNextColor(): should have generated {0, 1, 2} {3, -1, -1} {0, 3, -1}, but was "; byColorPathGenerator.lastResult.printPath();}

    byColorPathGenerator.generateNextColor(1);
    byColorPathGenerator.generateNextColor(2);
    if (byColorPathGenerator.lastResult.at(0) != array<int, 3>{0, 1, 2} || 
        byColorPathGenerator.lastResult.at(1) != array<int, 3>{3, 2, -1} || 
        byColorPathGenerator.lastResult.at(2) != array<int, 3>{0, 3, 1})
        {cout << "test_generateNextColor(): should have generated {0, 1, 2} {3, 2, -1} {0, 3, 1}, but was "; byColorPathGenerator.lastResult.printPath();}
}

void TestByColorPathGenerator::test_nextFullPath()
{
    cout << "TODO test_nextFullPath" << endl;
}

void TestByColorPathGenerator::test_all()
{
    cout << "Testing ByColorPathGenerator..." << endl;
    test_isColorDisjunct();
    test_getFirstNotFullVertex();
    test_generateNextColor();
    test_nextFullPath();
}
