#include "TestSimplePathGenerator.h"
#include <iostream>
#include <vector>
#include <tuple>
#include <stdlib.h>
#include <time.h>

using namespace std;


void TestSimplePathGenerator::test_2_colors()
{
    try
    {
        SimplePathGenerator pathGen = SimplePathGenerator(2, 2);
        pathGen.nextPath();
        cout << "test_2_colors should have generated an exception!" << endl;
    }
    catch(const std::exception& e)
    {
        cout << "test_2_colors should have generated char const* exception!" << endl;
    }
    catch(char const* c)
    { }
}

void TestSimplePathGenerator::test_3_colors()
{
    SimplePathGenerator pathGen = SimplePathGenerator(5, 3);
    Path path;

    path = pathGen.nextPath();
    if (path.empty()) {cout << "test_3_colors: path should not be empty "; path.printPath();}

    path = pathGen.nextPath();
    if (!path.empty()) {cout << "test_3_colors: path should be empty "; path.printPath();}
    path = pathGen.nextPath();
    if (!path.empty()) {cout << "test_3_colors: path should be empty "; path.printPath();}
}

void TestSimplePathGenerator::test_4_colors()
{
    SimplePathGenerator pathGen = SimplePathGenerator(1, 4);
    Path path;

    path = pathGen.nextPath();
    if (path.empty()) {cout << "test_4_colors: path should not be empty "; path.printPath();}
    path = pathGen.nextPath();
    if (path.empty()) {cout << "test_4_colors: path should not be empty "; path.printPath();}
    path = pathGen.nextPath();
    if (path.empty()) {cout << "test_4_colors: path should not be empty "; path.printPath();}
    path = pathGen.nextPath();
    if (path.empty()) {cout << "test_4_colors: path should not be empty "; path.printPath();}

    path = pathGen.nextPath();
    if (!path.empty()) {cout << "test_4_colors: path should be empty "; path.printPath();}
    path = pathGen.nextPath();
    if (!path.empty()) {cout << "test_4_colors: path should be empty "; path.printPath();}
}

void TestSimplePathGenerator::test_all()
{
    cout << "Testing SimplePathGenerator..." << endl;
    test_2_colors();
    test_3_colors();
    test_4_colors();
}
