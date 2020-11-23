#include "NonRepetitiveness.h"
#include <iostream>

using namespace std;



//Checks equality on positions from (index - (2*size)) to (index - size) of the given coloring and positions from (index - size) to (index)
//O(n)
bool NonRepetitiveness::checkEqualityOnIndexWithSize(Coloring* coloring, int index, int size)
{
    int pos1 = index - (2*size);
    int pos2 = index - size;
    for (int i = 0; i < size; i++)
    {
        if (coloring->at(pos1) != coloring->at(pos2)) return false;
        pos1++;
        pos2++;
    }
    return true;
}

//Check nonrepetitiveness for all-sized subcolorings ending on index
//O(n^2)
bool NonRepetitiveness::checkNonRepetitivenessOnIndex(Coloring* coloring, int index)
{
    for (int i = 1; i < index/2; i++)
    {
        if (!checkEqualityOnIndexWithSize(coloring, index, i))
            return false;
    }
    return true;
}

//Check nonrepetitiveness on whole coloring
//O(n^3)
bool NonRepetitiveness::checkNonRepetitiveness(Coloring* coloring)
{
    for (int i = 2; i < coloring->size(); i++)
    {
        if (!checkNonRepetitivenessOnIndex(coloring, i))
            return false;
    }
    return true;
}