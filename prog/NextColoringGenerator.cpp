#include "NextColoringGenerator.h"
#include <iostream>

using namespace std;


NextColoringGenerator::NextColoringGenerator(int lengthOfPath, Path & path_to_work_on) : path(path_to_work_on), length(lengthOfPath)
{
    resetColoring();
}


Coloring NextColoringGenerator::nextColoring()
{
    vector<int> res;
    vector<int> toFind = vectorToLength(decimalToBase3(nextPathColoring), length);
    if (toFind.empty()) return Coloring();
    for (int i = 0; i < length; i++){
        int color;
        switch(toFind[i]) {
            case 0:
                color = get<0>(path.at(i));
                break;
            case 1:
                color = get<1>(path.at(i));
                break;
            case 2:
                color = get<2>(path.at(i));
                break;
            default:
                throw "Lists are only of length 3!";
        }
        res.push_back(color);
    }
    nextPathColoring++;
    return Coloring(res);
}

void NextColoringGenerator::resetColoring()
{
    nextPathColoring = 0;
}
