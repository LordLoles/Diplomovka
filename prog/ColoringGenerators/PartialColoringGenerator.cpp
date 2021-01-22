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
bool PartialColoringGenerator::canIncrement()
{
    return (lastResult.empty() || colorIndeces.at(lastResult.size()) < 2);
}

//increments the last color of coloring lastResult with respect to colors in path
void PartialColoringGenerator::increment()
{
    int pos = lastResult.size();
    colorIndeces.at(pos)++;
    lastResult.set(pos, path.at(pos)[colorIndeces.at(pos)]);
}

//returns if the coloring is not at its max length, thus can be enlarged
bool PartialColoringGenerator::canBeEnlarged()
{
    return lastResult.size() < fullLength;
}

//makes next coloring one vertex longer with the first color available (from path)
void PartialColoringGenerator::enlarge()
{
    int index = lastResult.size()+1;
    int color = path.at(index)[0];
    colorIndeces.push_back(0);
    lastResult.push_back(color);
}

//makes next coloring one vertex shorter
void PartialColoringGenerator::shrink()
{
    colorIndeces.pop_back();
    lastResult.pop_back();
}

//performs shrink() until canIncrement() holds false
//saved result is shrinked as much as can and can be incremented OR empty coloring, if it can not be increment any more
void PartialColoringGenerator::shrinkUntilCanIncrement()
{
    while (!canIncrement())
    {
        shrink();
    }
}

//initialise this generator and returns its first coloring
Coloring PartialColoringGenerator::initialColoring()
{
    lastResult = Coloring(vector<int>{path.at(0)[0]}); // get coloring of length 1 with the zero color from path[0]
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
    if (canBeEnlarged()) enlarge();
    else if (canIncrement()) increment();
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
    shrinkUntilCanIncrement();
    if (lastResult.empty()) return Coloring();

    increment(); //shrinkUntilCanIncrement() has already checked, if we can increment

    return lastResult;
}

bool PartialColoringGenerator::isFullColoring()
{
    return lastResult.size() == fullLength;
}
