#include "WholeColoringGenerator.h"
#include <iostream>

using namespace std;


WholeColoringGenerator::WholeColoringGenerator(Path path_to_work_on) 
    : path(path_to_work_on)
    , length(path_to_work_on.size())
    , nextPathColoring(0)
{ }


Coloring WholeColoringGenerator::nextColoring()
{
    vector<int> res;
    vector<int> toFind = vectorToLength(decimalToBase3(nextPathColoring), length);
    if (toFind.empty()) return Coloring();
    for (int i = 0; i < length; i++){
        int color = path.at(i)[toFind[i]];
        res.push_back(color);
    }
    nextPathColoring++;
    return Coloring(res);
}
