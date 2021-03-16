#include "TestSimpleWithMemoryPathGenerator.h"
#include <iostream>
#include <vector>
#include <tuple>

using namespace std;


void TestSimpleWithMemoryPathGenerator::test_setColor()
{
    SimpleWithMemoryPathGenerator simpleWithMemoryGen = SimpleWithMemoryPathGenerator(3, 5);
    simpleWithMemoryGen.initialPath();

    simpleWithMemoryGen.setColor(1, 1, 4);
    if (simpleWithMemoryGen.lastResult.at(1) != array<int, 3>{0, 4, 2})
        cout << "test_setColor(): lastResult hould have had {0, 4, 2} at(1), but was {" <<
            simpleWithMemoryGen.lastResult.at(1).at(0) << ", " <<
            simpleWithMemoryGen.lastResult.at(1).at(1) << ", " <<
            simpleWithMemoryGen.lastResult.at(1).at(2) << "}" << endl;
}

void TestSimpleWithMemoryPathGenerator::test_updateColorsUsage()
{
    SimpleWithMemoryPathGenerator simpleWithMemoryGen = SimpleWithMemoryPathGenerator(3, 5);
    simpleWithMemoryGen.initialPath();

    simpleWithMemoryGen.updateColorsUsage(1, 1, 4);
    if (simpleWithMemoryGen.colorsUsage.at(1) != set<int>{0, 2} || simpleWithMemoryGen.colorsUsage.at(4) != set<int>{1})
        cout << "test_updateColorsUsage(): should have updated colorsUsage to {1} at(4) and to {0, 2} at(1), colors had sizes " <<
            simpleWithMemoryGen.colorsUsage.at(0).size() << ", " <<
            simpleWithMemoryGen.colorsUsage.at(1).size() << ", " <<
            simpleWithMemoryGen.colorsUsage.at(2).size() << ", " <<
            simpleWithMemoryGen.colorsUsage.at(3).size() << ", " <<
            simpleWithMemoryGen.colorsUsage.at(4).size() << endl;
}

void TestSimpleWithMemoryPathGenerator::test_isLast()
{
    SimpleWithMemoryPathGenerator simpleWithMemoryGen = SimpleWithMemoryPathGenerator(3, 5);
    simpleWithMemoryGen.initialPath();

    if (simpleWithMemoryGen.isLast(1,2) ||
        simpleWithMemoryGen.isLast(1,1) ||
        simpleWithMemoryGen.isLast(1,0) ||
        simpleWithMemoryGen.isLast(2,2))
        cout << "test_isLast(): any of those should be last" << endl;

    simpleWithMemoryGen.setColor(1, 2, 4);
    if (!simpleWithMemoryGen.isLast(1,2))
        cout << "test_isLast(): position (1, 2) should have last color, but was " << simpleWithMemoryGen.lastResult.at(1).at(2) << endl;

    simpleWithMemoryGen.setColor(1, 0, 2);
    if (!simpleWithMemoryGen.isLast(1,0))
        cout << "test_isLast(): position (1, 0) should have last color, but was " << simpleWithMemoryGen.lastResult.at(1).at(0) << endl;

    simpleWithMemoryGen.setColor(0, 1, 2);
    if (simpleWithMemoryGen.isLast(0,1))
        {cout << "test_isLast(): position (0, 1) should have not last color, path was "; simpleWithMemoryGen.lastResult.printPath();}
    
}

void TestSimpleWithMemoryPathGenerator::test_reset()
{
    SimpleWithMemoryPathGenerator simpleWithMemoryGen = SimpleWithMemoryPathGenerator(1, 4);
    simpleWithMemoryGen.initialPath();

    simpleWithMemoryGen.reset(0, 2);
    if (simpleWithMemoryGen.lastResult.at(0).at(2) != 2)
        cout << "test_reset(): position (0, 2) should be reset back to 2, but was " << simpleWithMemoryGen.lastResult.at(0).at(2) << endl;

    simpleWithMemoryGen.setColor(0, 1, 3);
    simpleWithMemoryGen.reset(0, 1);
    if (simpleWithMemoryGen.lastResult.at(0).at(1) != 1)
        cout << "test_reset(): position (0, 1) should be reset to 1, but was " << simpleWithMemoryGen.lastResult.at(0).at(1) << endl;
}

void TestSimpleWithMemoryPathGenerator::test_incrementVertexPostion()
{
    SimpleWithMemoryPathGenerator byColorPathGenerator = SimpleWithMemoryPathGenerator(1, 4);
    byColorPathGenerator.initialPath();

    if (!byColorPathGenerator.incrementVertexPostion(0, 0))
        cout << "test_incrementVertexPostion(): position (0, 0) should be able to increment, ended with " << byColorPathGenerator.lastResult.at(0).at(0) << endl;

    if (byColorPathGenerator.incrementVertexPostion(0, 0))
        cout << "test_incrementVertexPostion(): position (0, 0) should be not incremented now, ended with " << byColorPathGenerator.lastResult.at(0).at(0) << endl;
}

void TestSimpleWithMemoryPathGenerator::test_incrementVertex()
{
    SimpleWithMemoryPathGenerator simpleWithMemoryGen = SimpleWithMemoryPathGenerator(1, 4);
    simpleWithMemoryGen.initialPath();

    if (!simpleWithMemoryGen.incrementVertex(0))
        cout << "test_incrementVertex(): position 2 should be incremented, ended with " << simpleWithMemoryGen.lastResult.at(0).at(2) << endl;

    if (simpleWithMemoryGen.lastResult.at(0) != array<int, 3>{0, 1, 3})
        cout << "test_incrementVertex(): should have been incremented to {0, 1, 3}, but was {" <<
            simpleWithMemoryGen.lastResult.at(1).at(0) << ", " <<
            simpleWithMemoryGen.lastResult.at(1).at(1) << ", " <<
            simpleWithMemoryGen.lastResult.at(1).at(2) << "}" << endl;
    

    if (!simpleWithMemoryGen.incrementVertex(0))
        cout << "test_incrementVertex(): position 1 should be incremented, ended with " << simpleWithMemoryGen.lastResult.at(0).at(1) << endl;

    if (simpleWithMemoryGen.lastResult.at(0) != array<int, 3>{0, 2, 3})
        cout << "test_incrementVertex(): should have been incremented to {0, 2, 3}, but was {" <<
            simpleWithMemoryGen.lastResult.at(1).at(0) << ", " <<
            simpleWithMemoryGen.lastResult.at(1).at(1) << ", " <<
            simpleWithMemoryGen.lastResult.at(1).at(2) << "}" << endl;

    if (!simpleWithMemoryGen.incrementVertex(0))
        cout << "test_incrementVertex(): position 0 should be incremented, ended with " << simpleWithMemoryGen.lastResult.at(0).at(0) << endl;

    if (simpleWithMemoryGen.lastResult.at(0) != array<int, 3>{1, 2, 3})
        cout << "test_incrementVertex(): should have been incremented to {0, 1, 3}, but was {" <<
            simpleWithMemoryGen.lastResult.at(1).at(0) << ", " <<
            simpleWithMemoryGen.lastResult.at(1).at(1) << ", " <<
            simpleWithMemoryGen.lastResult.at(1).at(2) << "}" << endl;
            
    if (simpleWithMemoryGen.incrementVertex(0))
        cout << "test_incrementVertex(): should not be incremented, ended with {" <<
            simpleWithMemoryGen.lastResult.at(1).at(0) << ", " <<
            simpleWithMemoryGen.lastResult.at(1).at(1) << ", " <<
            simpleWithMemoryGen.lastResult.at(1).at(2) << "}" << endl;

}

void TestSimpleWithMemoryPathGenerator::test_increment()
{
    SimpleWithMemoryPathGenerator simpleWithMemoryGen = SimpleWithMemoryPathGenerator(2, 4);
    simpleWithMemoryGen.initialPath();

    simpleWithMemoryGen.increment();
    if (simpleWithMemoryGen.lastResult.at(0) != array<int, 3>{0, 1, 2} || simpleWithMemoryGen.lastResult.at(1) != array<int, 3>{0, 1, 3})
        {cout << "test_increment(): should have been incremented to {{0, 1, 2}, {0, 1, 3}}, but was "; simpleWithMemoryGen.lastResult.printPath();}

    simpleWithMemoryGen.increment();
    if (simpleWithMemoryGen.lastResult.at(0) != array<int, 3>{0, 1, 2} || simpleWithMemoryGen.lastResult.at(1) != array<int, 3>{0, 2, 3})
        {cout << "test_increment(): should have been incremented to {{0, 1, 2}, {0, 2, 3}}, but was "; simpleWithMemoryGen.lastResult.printPath();}

    simpleWithMemoryGen.increment();
    if (simpleWithMemoryGen.lastResult.at(0) != array<int, 3>{0, 1, 2} || simpleWithMemoryGen.lastResult.at(1) != array<int, 3>{1, 2, 3})
        {cout << "test_increment(): should have been incremented to {{0, 1, 2}, {1, 2, 3}}, but was "; simpleWithMemoryGen.lastResult.printPath();}

    simpleWithMemoryGen.increment();
    if (!simpleWithMemoryGen.lastResult.empty())
        {cout << "test_increment(): should have been emptied, as first vertex is not suppose to be modified, but was "; simpleWithMemoryGen.lastResult.printPath();}
}

void TestSimpleWithMemoryPathGenerator::test_initialPath()
{
    SimpleWithMemoryPathGenerator simpleWithMemoryGen = SimpleWithMemoryPathGenerator(2, 4);
    simpleWithMemoryGen.initialPath();
    Path res = simpleWithMemoryGen.lastResult;
    if (res.size() != 2 || res.at(0) != array<int, 3>{0, 1, 2} || res.at(1) != array<int, 3>{0, 1, 2})
        {cout << "test_initialPath(): should have been initialized to {{0, 1, 2}, {0, 1, 2}}, but was "; res.printPath();}

    simpleWithMemoryGen = SimpleWithMemoryPathGenerator(1, 4);
    simpleWithMemoryGen.initialPath();
    res = simpleWithMemoryGen.lastResult;
    if (res.size() != 1 || res.at(0) != array<int, 3>{0, 1, 2})
        {cout << "test_initialPath(): should have been initialized to {{0, 1, 2}}, but was "; res.printPath();}


    simpleWithMemoryGen = SimpleWithMemoryPathGenerator(1, 3);
    simpleWithMemoryGen.initialPath();
    res = simpleWithMemoryGen.lastResult;
    if (res.size() != 1 || res.at(0) != array<int, 3>{0, 1, 2})
        {cout << "test_initialPath(): should have been initialized to {{0, 1, 2}} again, but was "; res.printPath();}


    simpleWithMemoryGen = SimpleWithMemoryPathGenerator(3, 5);
    simpleWithMemoryGen.initialPath();
    res = simpleWithMemoryGen.lastResult;
    if (res.size() != 3 || res.at(0) != array<int, 3>{0, 1, 2} || res.at(1) != array<int, 3>{0, 1, 2} || res.at(2) != array<int, 3>{0, 1, 2})
        {cout << "test_initialPath(): should have been initialized to {{0, 1, 2}, {0, 1, 2}, {0, 1, 2}}, but was "; res.printPath();}
}

void TestSimpleWithMemoryPathGenerator::test_nextPath()
{
    //nextPath() should not be tested directly. It depends on isPathRelevant() check.
}


void TestSimpleWithMemoryPathGenerator::test_all()
{
    cout << "Testing SimpleWithMemoryPathGenerator..." << endl;

    test_setColor();
    test_updateColorsUsage();
    test_isLast();
    test_reset();
    test_incrementVertexPostion();
    test_incrementVertex();
    test_increment();
    test_initialPath();
    test_nextPath();
}
