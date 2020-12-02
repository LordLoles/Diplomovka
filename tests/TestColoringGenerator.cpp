#include "TestColoringGenerator.h"
#include <iostream>
#include <vector>
#include <tuple>
#include <stdlib.h>
#include <time.h>

using namespace std;


void TestColoringGenerator::test_empty_path()
{
    ColoringGenerator coloringGen = ColoringGenerator(Path());
    Coloring col;

    col = coloringGen.nextColoring();
    if (!col.empty()) {cout << "test_empty_path: coloring should be empty "; col.printColoring();}
    col = coloringGen.nextColoring();
    if (!col.empty()) {cout << "test_empty_path: coloring should be empty "; col.printColoring();}
}


void TestColoringGenerator::test_1_sized_path()
{
    ColoringGenerator coloringGen = ColoringGenerator(Path({{0, 1, 2}}));
    Coloring col;
    
    col = coloringGen.nextColoring();
    if (col.empty()) {cout << "test_1_sized_path: coloring should not be empty "; col.printColoring();}
    if (col.at(0) != 0) {cout << "test_1_sized_path: should be {0} "; col.printColoring();}

    col = coloringGen.nextColoring();
    if (col.empty()) {cout << "test_1_sized_path: coloring should not be empty "; col.printColoring();}
    if (col.at(0) != 1) {cout << "test_1_sized_path: should be {1} "; col.printColoring();}
    
    col = coloringGen.nextColoring();
    if (col.empty()) {cout << "test_1_sized_path: coloring should not be empty "; col.printColoring();}
    if (col.at(0) != 2) {cout << "test_1_sized_path: should be {2} "; col.printColoring();}
    
    col = coloringGen.nextColoring();
    if (!col.empty()) {cout << "test_1_sized_path: coloring should be empty "; col.printColoring();}
}

void TestColoringGenerator::test_2_sized_path()
{
    ColoringGenerator coloringGen = ColoringGenerator(Path({{0, 1, 2}, {0, 1, 2}}));
    Coloring col;

    col = coloringGen.nextColoring();
    if (col.empty()) {cout << "test_2_sized_path: coloring should not be empty "; col.printColoring();}
    if (col.at(0) != 0 || col.at(1) != 0) {cout << "test_2_sized_path: should be {0, 0} "; col.printColoring();}

    col = coloringGen.nextColoring();
    if (col.empty()) {cout << "test_2_sized_path: coloring should not be empty "; col.printColoring();}
    if (col.at(0) != 0 || col.at(1) != 1) {cout << "test_2_sized_path: should be {0, 1} "; col.printColoring();}

    col = coloringGen.nextColoring();
    if (col.empty()) {cout << "test_2_sized_path: coloring should not be empty "; col.printColoring();}
    if (col.at(0) != 0 || col.at(1) != 2) {cout << "test_2_sized_path: should be {0, 2} "; col.printColoring();}

    col = coloringGen.nextColoring();
    if (col.empty()) {cout << "test_2_sized_path: coloring should not be empty "; col.printColoring();}
    if (col.at(0) != 1 || col.at(1) != 0) {cout << "test_2_sized_path: should be {1, 0} "; col.printColoring();}

    col = coloringGen.nextColoring();
    if (col.empty()) {cout << "test_2_sized_path: coloring should not be empty "; col.printColoring();}
    if (col.at(0) != 1 || col.at(1) != 1) {cout << "test_2_sized_path: should be {1, 1} "; col.printColoring();}

    col = coloringGen.nextColoring();
    if (col.empty()) {cout << "test_2_sized_path: coloring should not be empty "; col.printColoring();}
    if (col.at(0) != 1 || col.at(1) != 2) {cout << "test_2_sized_path: should be {1, 2} "; col.printColoring();}

    col = coloringGen.nextColoring();
    if (col.empty()) {cout << "test_2_sized_path: coloring should not be empty "; col.printColoring();}
    if (col.at(0) != 2 || col.at(1) != 0) {cout << "test_2_sized_path: should be {2, 0} "; col.printColoring();}

    col = coloringGen.nextColoring();
    if (col.empty()) {cout << "test_2_sized_path: coloring should not be empty "; col.printColoring();}
    if (col.at(0) != 2 || col.at(1) != 1) {cout << "test_2_sized_path: should be {2, 1} "; col.printColoring();}

    col = coloringGen.nextColoring();
    if (col.empty()) {cout << "test_2_sized_path: coloring should not be empty "; col.printColoring();}
    if (col.at(0) != 2 || col.at(1) != 2) {cout << "test_2_sized_path: should be {2, 2} "; col.printColoring();}


    col = coloringGen.nextColoring();
    if (!col.empty()) {cout << "test_2_sized_path: coloring should be empty "; col.printColoring();}
}

void TestColoringGenerator::test_all()
{
    cout << "Testing ColoringGenerator..." << endl;

    test_empty_path();
    test_1_sized_path();
    test_2_sized_path();
}
