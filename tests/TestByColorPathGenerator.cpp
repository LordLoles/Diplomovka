#include "TestByColorPathGenerator.h"
#include <iostream>
#include <vector>
#include <tuple>
#include <stdlib.h>
#include <time.h>

using namespace std;


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
        
    byColorPathGenerator.generateNextColor(1);
    if (byColorPathGenerator.lastResult.at(0) != array<int, 3>{0, 1, 2} || 
        byColorPathGenerator.lastResult.at(1) != array<int, 3>{3, 2, 1} || 
        byColorPathGenerator.lastResult.at(2) != array<int, 3>{0, 3, -1})
        {cout << "test_generateNextColor(): should have generated {0, 1, 2} {3, 2, 1} {0, 3, -1}, but was "; byColorPathGenerator.lastResult.printPath();}
        
    byColorPathGenerator.generateNextColor(1);
    if (byColorPathGenerator.lastResult.at(0) != array<int, 3>{0, 1, 2} || 
        byColorPathGenerator.lastResult.at(1) != array<int, 3>{3, 2, 1} || 
        byColorPathGenerator.lastResult.at(2) != array<int, 3>{0, 3, 1})
        {cout << "test_generateNextColor(): should have generated {0, 1, 2} {3, 2, 1} {0, 3, 1}, but was "; byColorPathGenerator.lastResult.printPath();}
        
    byColorPathGenerator.generateNextColor(1);
    if (byColorPathGenerator.lastResult.at(0) != array<int, 3>{0, -1, 2} || 
        byColorPathGenerator.lastResult.at(1) != array<int, 3>{3, 2, -1} || 
        byColorPathGenerator.lastResult.at(2) != array<int, 3>{0, 3, -1})
        {cout << "test_generateNextColor(): should have generated {0, -1, 2} {3, 2, -1} {0, 3, -1}, but was "; byColorPathGenerator.lastResult.printPath();}
}

void TestByColorPathGenerator::test_getFirstNotFullVertex()
{
    ByColorPathGenerator byColorPathGenerator = ByColorPathGenerator(3, 4);

    int vertex = byColorPathGenerator.getFirstNotFullVertex();
    if (vertex != 0)
        {cout << "test_getFirstNotFullVertex(): First not full should be 0, but was " << vertex << ", whole path was"; byColorPathGenerator.lastResult.printPath();}

    byColorPathGenerator.generateNextColor(0);
    byColorPathGenerator.generateNextColor(0);
    vertex = byColorPathGenerator.getFirstNotFullVertex();
    if (vertex != 0)
        {cout << "test_getFirstNotFullVertex(): First not full should be 0 again, but was " << vertex << ", whole path was"; byColorPathGenerator.lastResult.printPath();}

    byColorPathGenerator.generateNextColor(1);
    vertex = byColorPathGenerator.getFirstNotFullVertex();
    if (vertex != 0)
        {cout << "test_getFirstNotFullVertex(): First not full should be 0 once again, but was " << vertex << ", whole path was"; byColorPathGenerator.lastResult.printPath();}

    byColorPathGenerator.generateNextColor(2);
    vertex = byColorPathGenerator.getFirstNotFullVertex();
    if (vertex != 1)
        {cout << "test_getFirstNotFullVertex(): First not full should be 1, but was " << vertex << ", whole path was"; byColorPathGenerator.lastResult.printPath();}

    byColorPathGenerator.generateNextColor(3);
    byColorPathGenerator.generateNextColor(3);
    byColorPathGenerator.generateNextColor(1);
    byColorPathGenerator.generateNextColor(2);
    byColorPathGenerator.generateNextColor(1);
    //path should be {0, 1, 2} {3, 2, 1} {0, 3, -1}
    vertex = byColorPathGenerator.getFirstNotFullVertex();
    if (vertex != 2)
        {cout << "test_getFirstNotFullVertex(): First not full should be 2, but was " << vertex << ", whole path was"; byColorPathGenerator.lastResult.printPath();}

    byColorPathGenerator.generateNextColor(1);
    //path should be full - {0, 1, 2} {3, 2, 1} {0, 3, 1}
    vertex = byColorPathGenerator.getFirstNotFullVertex();
    if (vertex != -1)
        {cout << "test_getFirstNotFullVertex(): There should not be not full vertex, but function returned " << 
        vertex << ", whole path was"; byColorPathGenerator.lastResult.printPath();}
}

void TestByColorPathGenerator::test_isColorDisjunct()
{
    ByColorPathGenerator byColorPathGenerator = ByColorPathGenerator(3, 4);

    byColorPathGenerator.generateNextColor(0);
    byColorPathGenerator.generateNextColor(0);
    byColorPathGenerator.generateNextColor(1);
    byColorPathGenerator.generateNextColor(1);
    byColorPathGenerator.generateNextColor(1);
    byColorPathGenerator.generateNextColor(2);
    byColorPathGenerator.generateNextColor(3);
    byColorPathGenerator.generateNextColor(3);
    //path should be {0, 1, 2} {1, 3, -1} {0, 3, -1}

    if (byColorPathGenerator.isColorDisjunct(0))
        {cout << "test_isColorDisjunct(): Color 0 should not be disjunct on path "; byColorPathGenerator.lastResult.printPath();}
    if (byColorPathGenerator.isColorDisjunct(1))
        {cout << "test_isColorDisjunct(): Color 1 should not be disjunct on path "; byColorPathGenerator.lastResult.printPath();}
    if (byColorPathGenerator.isColorDisjunct(2))
        {cout << "test_isColorDisjunct(): Color 2 should not be disjunct on path "; byColorPathGenerator.lastResult.printPath();}
    if (!byColorPathGenerator.isColorDisjunct(3))
        {cout << "test_isColorDisjunct(): Color 3 should be disjunct on path "; byColorPathGenerator.lastResult.printPath();}
}

void TestByColorPathGenerator::test_nextFullPath()
{
    ByColorPathGenerator byColorPathGenerator = ByColorPathGenerator(1, 3);

    bool isFull = byColorPathGenerator.nextFullPath();
    if (!isFull || byColorPathGenerator.lastResult.at(0) != array<int, 3>{0, 1, 2})
        {cout << "test_nextFullPath() 0: Full path should be {0, 1, 2}, but was "; byColorPathGenerator.lastResult.printPath();}

    isFull = byColorPathGenerator.nextFullPath();
    if (isFull)
        {cout << "test_nextFullPath() 0: There should not be any more full paths, but was generated "; byColorPathGenerator.lastResult.printPath();}


    byColorPathGenerator = ByColorPathGenerator(1, 5);

    isFull = byColorPathGenerator.nextFullPath();
    if (!isFull || byColorPathGenerator.lastResult.at(0) != array<int, 3>{0, 1, 2})
        {cout << "test_nextFullPath() 1: Full path should be {0, 1, 2}, but was "; byColorPathGenerator.lastResult.printPath();}

    isFull = byColorPathGenerator.nextFullPath();
    if (!isFull || byColorPathGenerator.lastResult.at(0) != array<int, 3>{0, 1, 3})
        {cout << "test_nextFullPath() 1: Full path should be {0, 1, 3}, but was "; byColorPathGenerator.lastResult.printPath();}

    isFull = byColorPathGenerator.nextFullPath();
    if (!isFull || byColorPathGenerator.lastResult.at(0) != array<int, 3>{0, 1, 4})
        {cout << "test_nextFullPath() 1: Full path should be {0, 1, 4}, but was "; byColorPathGenerator.lastResult.printPath();}

    isFull = byColorPathGenerator.nextFullPath();
    if (!isFull || byColorPathGenerator.lastResult.at(0) != array<int, 3>{0, 2, 3})
        {cout << "test_nextFullPath() 1: Full path should be {0, 2, 3}, but was "; byColorPathGenerator.lastResult.printPath();}

    isFull = byColorPathGenerator.nextFullPath();
    if (!isFull || byColorPathGenerator.lastResult.at(0) != array<int, 3>{0, 2, 4})
        {cout << "test_nextFullPath() 1: Full path should be {0, 2, 4}, but was "; byColorPathGenerator.lastResult.printPath();}

    isFull = byColorPathGenerator.nextFullPath();
    if (!isFull || byColorPathGenerator.lastResult.at(0) != array<int, 3>{0, 3, 4})
        {cout << "test_nextFullPath() 1: Full path should be {0, 3, 4}, but was "; byColorPathGenerator.lastResult.printPath();}

    isFull = byColorPathGenerator.nextFullPath();
    if (!isFull || byColorPathGenerator.lastResult.at(0) != array<int, 3>{1, 2, 3})
        {cout << "test_nextFullPath() 1: Full path should be {1, 2, 3}, but was "; byColorPathGenerator.lastResult.printPath();}

    isFull = byColorPathGenerator.nextFullPath();
    isFull = byColorPathGenerator.nextFullPath();
    isFull = byColorPathGenerator.nextFullPath();
    isFull = byColorPathGenerator.nextFullPath();
    if (isFull)
        {cout << "test_nextFullPath() 1: There should not be any more full paths, but was generated "; byColorPathGenerator.lastResult.printPath();}

}

void TestByColorPathGenerator::test_all()
{
    cout << "Testing ByColorPathGenerator..." << endl;
    test_generateNextColor();
    test_getFirstNotFullVertex();
    test_isColorDisjunct();
    test_nextFullPath();
}
