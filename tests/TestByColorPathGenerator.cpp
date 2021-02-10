#include "TestByColorPathGenerator.h"
#include <iostream>
#include <vector>
#include <tuple>

using namespace std;


void TestByColorPathGenerator::test_setColor()
{
    ByColorPathGenerator byColorPathGenerator = ByColorPathGenerator(3, 5);
    byColorPathGenerator.initialPath();

    byColorPathGenerator.setColor(1, 1, 4);
    if (byColorPathGenerator.lastResult.at(1) != array<int, 3>{0, 4, 2})
        cout << "test_setColor(): lastResult hould have had {0, 4, 2} at(1), but was {" <<
            byColorPathGenerator.lastResult.at(1).at(0) << ", " <<
            byColorPathGenerator.lastResult.at(1).at(1) << ", " <<
            byColorPathGenerator.lastResult.at(1).at(2) << "}" << endl;
}

void TestByColorPathGenerator::test_updateColorsUsage()
{
    ByColorPathGenerator byColorPathGenerator = ByColorPathGenerator(3, 5);
    byColorPathGenerator.initialPath();

    byColorPathGenerator.updateColorsUsage(1, 1, 4);
    if (byColorPathGenerator.colorsUsage.at(1) != set<int>{0, 2} || byColorPathGenerator.colorsUsage.at(4) != set<int>{1})
        cout << "test_updateColorsUsage(): should have updated colorsUsage to {1} at(4) and to {0, 2} at(1), colors had sizes " <<
            byColorPathGenerator.colorsUsage.at(0).size() << ", " <<
            byColorPathGenerator.colorsUsage.at(1).size() << ", " <<
            byColorPathGenerator.colorsUsage.at(2).size() << ", " <<
            byColorPathGenerator.colorsUsage.at(3).size() << ", " <<
            byColorPathGenerator.colorsUsage.at(4).size() << endl;
}

void TestByColorPathGenerator::test_isLast()
{
    ByColorPathGenerator byColorPathGenerator = ByColorPathGenerator(3, 5);
    byColorPathGenerator.initialPath();

    if (byColorPathGenerator.isLast(1,2) ||
        byColorPathGenerator.isLast(1,1) ||
        byColorPathGenerator.isLast(1,0) ||
        byColorPathGenerator.isLast(2,2))
        cout << "test_isLast(): any of those should be last" << endl;

    byColorPathGenerator.setColor(1, 0, 4);
    if (!byColorPathGenerator.isLast(1,0))
        cout << "test_isLast(): position (1, 0) should have last color, but was " << byColorPathGenerator.lastResult.at(1).at(0) << endl;
}

void TestByColorPathGenerator::test_reset()
{
    ByColorPathGenerator byColorPathGenerator = ByColorPathGenerator(1, 4);
    byColorPathGenerator.initialPath();

    byColorPathGenerator.reset(0, 2);
    if (!byColorPathGenerator.lastResult.at(0).at(2) != 2)
        cout << "test_reset(): position (0, 2) should be reset back to 2, but was " << byColorPathGenerator.lastResult.at(0).at(2) << endl;

    byColorPathGenerator.setColor(0, 1, 3);
    byColorPathGenerator.reset(0, 1);
    if (!byColorPathGenerator.lastResult.at(0).at(1) != 1)
        cout << "test_reset(): position (0, 1) should be reset to 1, but was " << byColorPathGenerator.lastResult.at(0).at(1) << endl;
}

void TestByColorPathGenerator::test_incrementVertexPostion()
{
    ByColorPathGenerator byColorPathGenerator = ByColorPathGenerator(1, 4);
    byColorPathGenerator.initialPath();

    if (!byColorPathGenerator.incrementVertexPostion(0, 1))
        cout << "test_incrementVertexPostion(): position (0, 1) should be able to increment, ended with " << byColorPathGenerator.lastResult.at(0).at(1) << endl;

    if (!byColorPathGenerator.incrementVertexPostion(0, 1))
        cout << "test_incrementVertexPostion(): position (0, 1) should be able to increment again, ended with " << byColorPathGenerator.lastResult.at(0).at(1) << endl;

    if (byColorPathGenerator.incrementVertexPostion(0, 1))
        cout << "test_incrementVertexPostion(): position (0, 1) should be not incremented now, ended with " << byColorPathGenerator.lastResult.at(0).at(1) << endl;
}

void TestByColorPathGenerator::test_incrementVertex()
{
    ByColorPathGenerator byColorPathGenerator = ByColorPathGenerator(1, 4);
    byColorPathGenerator.initialPath();

    if (!byColorPathGenerator.incrementVertex(0))
        cout << "test_incrementVertex(): vertex 0 should be incremented, ended with " << byColorPathGenerator.lastResult.at(0).at(1) << endl;

    //TODO
}

void TestByColorPathGenerator::test_increment()
{

}

void TestByColorPathGenerator::test_initialPath()
{

}

void TestByColorPathGenerator::test_nextPath()
{

}


void TestByColorPathGenerator::test_all()
{
    cout << "Testing ByColorPathGenerator..." << endl;

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