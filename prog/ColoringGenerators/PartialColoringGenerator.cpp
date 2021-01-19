#include "PartialColoringGenerator.h"
#include <iostream>
#include "../Consts.h"

using namespace std;


PartialColoringGenerator::PartialColoringGenerator(Path path_to_work_on)
    : path(path_to_work_on)
    , fullLength(path_to_work_on.size())
    , lastResult(Coloring())
    , colorIndeces()
{ }

//returns if the coloring's last color can be change to next color from corresponding path tuple
//returns true, if the coloring is empty
bool PartialColoringGenerator::canIncrement(Coloring col)
{
    return (col.empty() || colorIndeces.at(col.size()) < 2);
}

//returns coloring with the last color incremented with respect to colors in path
Coloring PartialColoringGenerator::increment(Coloring col)
{
    int pos = col.size();
    colorIndeces.at(pos)++;
    return col.set(pos, path.at(pos)[colorIndeces.at(pos)]);
}

//returns if the coloring is not at its max length, thus can be enlarged
bool PartialColoringGenerator::canBeEnlarged(Coloring col)
{
    return col.size() < fullLength;
}

//returns coloring one vertex longer with the first color available (from path)
Coloring PartialColoringGenerator::enlarge(Coloring col)
{
    int index = col.size()+1;
    int color = path.at(index)[0];
    colorIndeces.push_back(0);
    return col.push_back(color);
}

//returns coloring one vertex shorter
Coloring PartialColoringGenerator::shrink(Coloring col)
{
    colorIndeces.pop_back();
    return col.pop_back();
}

//performs shrink(col) until canIncrement holds false
//returns shrinked coloring that can be incremented OR empty coloring, if it can not be increment more times
Coloring PartialColoringGenerator::shrinkUntilCanIncrement(Coloring col)
{
    while (!canIncrement(col))
    {
        col = shrink(col);
    }
    return col;
}

//initialise this generator and returns its first coloring
Coloring PartialColoringGenerator::initialColoring()
{
    lastResult = Coloring(vector<int>{get<0>(path.at(0))}); // get coloring of length 1 with the zero color from path[0]
    colorIndeces[0] = 0;
    return lastResult;
}

//generate and returns next coloring
//examples on 012 colors for every vertex, maximal length 5:
// --- last coloring is 00, this will return 000
// --- last coloring is 10120, this will return 10121
// --- last coloring is 10122, this will return 102
Coloring PartialColoringGenerator::nextColoring()
{
    if (canBeEnlarged(lastResult)) lastResult = enlarge(lastResult);
    else if (canIncrement(lastResult)) lastResult = increment(lastResult);
    else skipColoring();

    return lastResult;
}

//skips whole subtree under lastly generater coloring
//returns first coloring from the next subtree
//examples on 012 colors for every vertex, maximal length 5:
// --- last coloring is 00, this will return 01
// --- last coloring is 102, this will return 11
// --- last coloring is 10122, this will return 102
Coloring PartialColoringGenerator::skipColoring()
{
    lastResult = shrinkUntilCanIncrement(lastResult);
    if (lastResult.empty()) return Coloring();

    lastResult = increment(lastResult); //shrinkUntilCanIncrement() has checked already, if we can increment

    return lastResult;
}

bool PartialColoringGenerator::isFullColoring()
{
    return lastResult.size() == fullLength;
}
