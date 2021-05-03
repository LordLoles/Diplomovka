#include "TestNonRepetitiveness.h"
#include <iostream>
#include <vector>
#include <tuple>
#include <stdlib.h>
#include <time.h>
#include "../prog/NonRepetitiveness.h"

using namespace std;


void TestNonRepetitiveness::test_equality_function()
{
    Coloring testing = Coloring({0, 1, 0, 0});
    if (checkEqualityOnIndexWithSize(testing, 1, 1)) {cout << "test_equality_on_0100: should not equal, index 1, size 1, col "; testing.printColoring();}
    if (checkEqualityOnIndexWithSize(testing, 2, 1)) {cout << "test_equality_on_0100: should not equal, index 2, size 1, col "; testing.printColoring();}
    if (!checkEqualityOnIndexWithSize(testing, 3, 1)) {cout << "test_equality_on_0100: should equal, index 3, size 1, col "; testing.printColoring();}
    if (checkEqualityOnIndexWithSize(testing, 3, 2)) {cout << "test_equality_on_0100: should not equal, index 3, size 2, col "; testing.printColoring();}
}

void TestNonRepetitiveness::test_nonrepetitiveness_on_index()
{
    Coloring testing = Coloring({0, 1, 0, 0});
    if (!checkNonRepetitivenessOnIndex(testing, 0)) {cout << "test_nonrepetitiveness_on_index: should be nonrepetitive, index 0, col "; testing.printColoring();}
    if (!checkNonRepetitivenessOnIndex(testing, 1)) {cout << "test_nonrepetitiveness_on_index: should be nonrepetitive, index 1, col "; testing.printColoring();}
    if (!checkNonRepetitivenessOnIndex(testing, 2)) {cout << "test_nonrepetitiveness_on_index: should be nonrepetitive, index 2, col "; testing.printColoring();}
    if (checkNonRepetitivenessOnIndex(testing, 3)) {cout << "test_nonrepetitiveness_on_index: should be repetitive, index 2, col "; testing.printColoring();}
}

void TestNonRepetitiveness::test_nonrepetitiveness_on_last_index()
{
    Coloring testing = Coloring({0, 1, 0, 0});
    if (checkNonRepetitivenessOnLastIndex(testing)) {cout << "test_nonrepetitiveness_on_last_index: should be repetitive on last index, col "; testing.printColoring();}
    testing = Coloring({0, 1, 0, 2, 1, 0, 2});
    if (checkNonRepetitivenessOnLastIndex(testing)) {cout << "test_nonrepetitiveness_on_last_index: should be repetitive on last index, col "; testing.printColoring();}
    testing = Coloring({0, 0});
    if (checkNonRepetitivenessOnLastIndex(testing)) {cout << "test_nonrepetitiveness_on_last_index: should be repetitive on last index, col "; testing.printColoring();}
}

void TestNonRepetitiveness::test_nonrepetitiveness()
{
    Coloring testing = Coloring({0, 1, 0, 0});
    if (checkNonRepetitiveness(testing)) {cout << "test_nonrepetitiveness: should be repetitive, col "; testing.printColoring();}
    
    testing = Coloring({0, 1, 0, 2});
    if (!checkNonRepetitiveness(testing)) {cout << "test_nonrepetitiveness: should be nonrepetitive, col "; testing.printColoring();}

    testing = Coloring(vector<int>{5});
    if (!checkNonRepetitiveness(testing)) {cout << "test_nonrepetitiveness: should be nonrepetitive, col "; testing.printColoring();}

    testing = Coloring({0, 1, 0, 2, 1, 0, 2});
    if (checkNonRepetitiveness(testing)) {cout << "test_nonrepetitiveness: should be repetitive, col "; testing.printColoring();}
}


void TestNonRepetitiveness::test_equality_funtion_equals(Coloring coloring)
{
    vector<int> col = coloring.toVector();
    vector<int> copy = col;
    col.insert(col.end(), copy.begin(), copy.end());
    Coloring testing = Coloring(col);

    if (!checkEqualityOnIndexWithSize(testing, testing.size()-1, testing.size()/2))
    {
        cout << "The coloring should be equal in half. Size is " << testing.size() << ", half at " << (testing.size()/2) << " coloring: ";
        testing.printColoring();
    }
}

//Test for no equality, where two halfs differs on positions "pos". Each position needs to be a lower number than colorings size.
void TestNonRepetitiveness::test_equality_funtion_not_equals(Coloring coloring, vector<int> pos)
{
    vector<int> col = coloring.toVector();
    vector<int> copy = col;
    col.insert(col.end(), copy.begin(), copy.end());
    for (int j = 0; j < pos.size(); j++) col[pos[j]]++;
    Coloring testing = Coloring(col);

    if (checkEqualityOnIndexWithSize(testing, testing.size(), testing.size()/2))
    {
        cout << "The coloring should not equal in half. Size is " << testing.size() << ", half at " << (testing.size()/2) << " coloring: ";
        testing.printColoring();
    }
}

void TestNonRepetitiveness::test_all(int colors, int maxLength, int repeat)
{
    cout << "Testing NonRepetitiveness..." << endl;

    test_equality_function();
    test_nonrepetitiveness_on_index();
    test_nonrepetitiveness_on_last_index();
    test_nonrepetitiveness();



    srand(seed);

    for (int i = 0; i < repeat; i++)
    {
        int length = rand() % maxLength;
        vector<int> v;
        for (int j = 0; j < length; j++) v.push_back(rand() % colors);
        Coloring col = Coloring(v);

        test_equality_funtion_equals(col);

        for (int j = 0; j < length/10; j++) 
            test_equality_funtion_not_equals(col, {rand() % length});

        for (int j = 0; j < length/10; j++) 
            test_equality_funtion_not_equals(col, {rand() % length, rand() % length, rand() % length});
        

    }
}