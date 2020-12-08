#include "NonRepetitiveness.h"
#include <iostream>

using namespace std;


//Checks equality of the given coloring on positions from (index - (2*size)) to (index - size) and positions from (index - size) to (index)
//Returns true, if those two parts are equal
//O(n)
bool checkEqualityOnIndexWithSize(const Coloring & coloring, int index, int size)
{
    int pos1 = index - (2*size) + 1;
    int pos2 = index - size + 1;
    for (int i = 0; i < size; i++)
    {
        if (coloring.at(pos1) != coloring.at(pos2)) return false;
        pos1++;
        pos2++;
    }
    return true;
}

//Check nonrepetitiveness for all-sized subcolorings ending on index
//O(n^2)
bool checkNonRepetitivenessOnIndex(const Coloring & coloring, int index)
{
    for (int i = 1; i <= index/2; i++)
    {
        if (checkEqualityOnIndexWithSize(coloring, index, i))
            return false;
    }
    return true;
}

//Check nonrepetitiveness on whole coloring
//O(n^3)
bool checkNonRepetitiveness(const Coloring & coloring)
{
    for (int i = 2; i < coloring.size(); i++)
    {
        if (!checkNonRepetitivenessOnIndex(coloring, i))
            return false;
    }
    return true;
}
