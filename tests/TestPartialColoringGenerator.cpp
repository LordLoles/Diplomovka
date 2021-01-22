#include "TestPartialColoringGenerator.h"
#include <iostream>
#include <vector>
#include <tuple>
#include <stdlib.h>
#include <time.h>

using namespace std;


void TestPartialColoringGenerator::test_canIncrement()
{
    PartialColoringGenerator gen = PartialColoringGenerator(Path());
    if (!gen.canIncrement()) cout << "empty should return true" << endl;

    gen = PartialColoringGenerator(Path({{0,1,2}}));
    if (!gen.canIncrement()) cout << "empty should return true" << endl;
    gen.initialColoring(); //initialColoring() is tested on other place
    if (!gen.canIncrement()) cout << "should return true on 0" << endl;
    gen.increment();
    if (!gen.canIncrement()) cout << "should return true on 1" << endl;
    gen.increment();
    if (gen.canIncrement()) cout << "should return false on 2" << endl;
}

void TestPartialColoringGenerator::test_increment()
{
    PartialColoringGenerator gen = PartialColoringGenerator(Path());
    try 
    {
        gen.increment();
        cout << "should produce exception (Path())" << endl;
    }
    catch(exception e) { }

    gen = PartialColoringGenerator(Path({{2,5,17}}));
    gen.initialColoring(); //initialColoring() is tested on other place
    if (gen.lastResult.at(0) != 2) cout << "should be 2" << endl;
    gen.increment();
    if (gen.lastResult.at(0) != 5) cout << "should be 5" << endl;
    gen.increment();
    if (gen.lastResult.at(0) != 17) cout << "should be 17" << endl;
    try 
    {
        gen.increment();
        cout << "should produce exception (Path({{2,5,17}})" << endl;
    }
    catch(exception e) { }
}

void TestPartialColoringGenerator::test_canBeEnlarged()
{

}

void TestPartialColoringGenerator::test_enlarge()
{

}

void TestPartialColoringGenerator::test_shrink()
{

}

void TestPartialColoringGenerator::test_shrinkUntilCanIncrement()
{

}


void TestPartialColoringGenerator::test_initialColoring()
{

}

void TestPartialColoringGenerator::test_nextColoring()
{

}

void TestPartialColoringGenerator::test_skipColoring()
{

}

void TestPartialColoringGenerator::test_isFullColoring()
{

}


void TestPartialColoringGenerator::test_empty_path()
{

}

void TestPartialColoringGenerator::test_1_sized_path()
{

}

void TestPartialColoringGenerator::test_2_sized_path()
{

}

void TestPartialColoringGenerator::test_3_sized_path()
{

}


void TestPartialColoringGenerator::test_all()
{
    cout << "Testing PartialColoringGenerator..." << endl;

    test_canIncrement();
    test_increment();
    test_canBeEnlarged();
    test_enlarge();
    test_shrink();
    test_shrinkUntilCanIncrement();

    test_initialColoring();
    test_nextColoring();
    test_skipColoring();
    test_isFullColoring();

    test_empty_path();
    test_3_sized_path();
    test_1_sized_path();
    test_2_sized_path();
}