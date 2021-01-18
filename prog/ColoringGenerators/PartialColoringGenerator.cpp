#include "PartialColoringGenerator.h"
#include <iostream>

using namespace std;


PartialColoringGenerator::PartialColoringGenerator(Path path_to_work_on) 
    : path(path_to_work_on)
    , length(path_to_work_on.size())
    , lastResult(Coloring())
{ }


Coloring PartialColoringGenerator::nextColoring()
{
    vector<int> res;

    asd

    return Coloring(res);
}

bool PartialColoringGenerator::isFullColoring()
{
    return lastResult.size() == length;
}
