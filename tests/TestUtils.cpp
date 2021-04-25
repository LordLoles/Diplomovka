#include <iostream>
#include <vector>
#include <tuple>
#include <stdlib.h>
#include <time.h>
#include <set>
#include "../prog/Path.h"
#include "TestUtils.h"

using namespace std;



int binomialCoefficients(int n, int k) {
    if (k == 0 || k == n)
        return 1;
    return binomialCoefficients(n - 1, k - 1) + binomialCoefficients(n - 1, k);
}


void TestUtils::test_vectorToLength()
{
    vector<int> v = decimalToBase(63, 2);
    vector<int> result = vectorToLength(v, v.size() + 2);
    if (result[0] != 0) cout << "na nultej pozicii ma byt nula" << endl;
    if (result[1] != 0) cout << "na nultej pozicii ma byt nula" << endl;
    for (int i = 2; i < result.size(); i++)
    {
        if (result[i] != 1) 
        {
            cout << "na pozicii " << i << " ma byt jendotka, nie " << result[i] << " pre vektor ";
            printVector(result);
        }
    }
}

void TestUtils::test_vectorToLength_2()
{
    vector<int> v = decimalToBase(0, 4);
    vector<int> result = vectorToLength(v, v.size() + 2);
    for (int i = 1; i < result.size(); i++)
    {
        if (result[i] != 0) cout << "na pozicii " << i << " ma byt nula" << endl;
    }
}

void TestUtils::test_getSetToLength(int length)
{
    vector<int> result = getSetToLength(length);
    for (int i = 0; i < result.size(); i++)
    {
        if (result[i] != i) cout << "na pozicii " << i << " ma byt " << i << endl;
    }
}

void TestUtils::test_decimalToBase()
{
    vector<int> vec = decimalToBase(17, 2);
    int result = digitsToInt(vec);
    if (result != 10001) cout << "17 v dvojkovej ma byt 10001, nie " << result << endl;
    
    vec = decimalToBase(31, 2);
    result = digitsToInt(vec);
    if (digitsToInt(vec) != 11111) cout << "35 v dvojkovej ma byt 11111, nie " << result << endl;
}

void TestUtils::test_digitsToInt()
{
    int result = digitsToInt({1, 0, 1});
    if (result != 101) cout << "1, 0, 1 ma byt 101" << endl;

    result = digitsToInt({8, 2, 6, 0});
    if (result != 8260) cout << "8, 2, 6, 0 ma byt 8260" << endl;
}

void TestUtils::test_getSubsetsOfLength3(int setSize)
{
    vector<int> setToColors = getSetToLength(setSize);
    vector<array<int, 3>> pseudoPath = getSubsetsOfLength3(setToColors);
    int count = binomialCoefficients(setSize, 3);
    if (pseudoPath.size() != count)
    {
        cout << "subsets size = " << pseudoPath.size() << ", but should be " << count << " for setSize " << setSize << " and path " << endl;
        (Path(pseudoPath)).printPath();
    }
}

void TestUtils::test_stringTo3Vector()
{
    string pathString = "{0 5 -1} {22 -4 6} {9 10 11}";
    Path path = Path(stringTo3Vector(pathString));
    if (path.at(0) != array<int, 3>{0, 5, -1} || path.at(1) != array<int, 3>{22, -4, 6} || path.at(2) != array<int, 3>{9, 10, 11})
        {cout << "test_stringTo3Vector(): parsed path should be {0 5 -1} {22 -4 6} {9 10 11}, but was "; path.printPath();}
}

void TestUtils::test_getColorsUsage()
{
    Path path = Path({{1, 2, 3}, {-1, 2, 5}, {2, -1, -1}});
    vector<set<int>> colorsUsage = getColorsUsage(path, 7);

    if (colorsUsage.at(0) != set<int>{} || colorsUsage.at(1) != set<int>{0} || colorsUsage.at(2) != set<int>{0, 1, 2} || 
        colorsUsage.at(3) != set<int>{0} || colorsUsage.at(4) != set<int>{} || colorsUsage.at(5) != set<int>{1} || colorsUsage.at(6) != set<int>{})
        {cout << "test_getColorsUsage(): colorsUsage should be {} {0} {0, 1, 2} {0} {} {1} {}, but was not" << endl;}
}

void TestUtils::test_all(int repeat)
{
    cout << "Testing Utils..." << endl;
    test_vectorToLength();
    test_vectorToLength_2();
    test_decimalToBase();
    test_digitsToInt();
    test_stringTo3Vector();
    test_getColorsUsage();

    srand(40087711);

    for (int i = 0; i < repeat; i++)
    {
        test_getSetToLength(rand() % 200);
        test_getSubsetsOfLength3(rand() % 200);
    }
}
