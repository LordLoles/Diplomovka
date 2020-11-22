#include "TestNonRepetitiveness.h"
#include <iostream>
#include <vector>
#include <tuple>
#include <stdlib.h>
#include <time.h>

using namespace std;


void TestNonRepetitiveness::test_equality_funtion_equals(Coloring* coloring)
{
    vector<int> col = coloring->toVector();
    vector<int> copy = col;
    col.insert(col.end(), copy.begin(), copy.end());
    Coloring* testing = new Coloring(col);
    if (!nonRepetitiveness->checkEqualityOnIndexWithSize(testing, testing->size(), testing->size()/2))
    {
        cout << "The coloring should be equal in half. Size is " << testing->size() << ", half at " << (testing->size()/2) << " coloring: ";
        testing->printColoring();
    }
}

//Test for no equality, where two halfs differs on positions "pos". Each position needs to be a lower number than colorings size.
void TestNonRepetitiveness::test_equality_funtion_not_equals(Coloring* coloring, vector<int> pos)
{
    vector<int> col = coloring->toVector();
    vector<int> copy = col;
    col.insert(col.end(), copy.begin(), copy.end());
    for (int j = 0; j < pos.size(); j++) col[pos[j]]++;
    Coloring* testing = new Coloring(col);
    if (nonRepetitiveness->checkEqualityOnIndexWithSize(testing, testing->size(), testing->size()/2))
    {
        cout << "The coloring should not equal in half. Size is " << testing->size() << ", half at " << (testing->size()/2) << " coloring: ";
        testing->printColoring();
    }
}

void TestNonRepetitiveness::test_all(int colors, int maxLength, int repeat)
{
    cout << "Testing NonRepetitiveness..." << endl;
    srand(time(NULL));

    for (int i = 0; i < repeat; i++)
    {
        int length = rand() % maxLength;
        vector<int> v;
        for (int j = 0; j < length; j++) v.push_back(rand() % colors);
        Coloring* col = new Coloring(v);

        test_equality_funtion_equals(col);

        for (int j = 0; j < length/10; j++) 
            test_equality_funtion_not_equals(col, {rand() % length});

        for (int j = 0; j < length/10; j++) 
            test_equality_funtion_not_equals(col, {rand() % length, rand() % length, rand() % length});
        

    }
}
