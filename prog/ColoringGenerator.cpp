#include "ColoringGenerator.h"
#include <iostream>

using namespace std;


ColoringGenerator::ColoringGenerator(Path path_to_work_on) 
    : path(path_to_work_on)
    , length(path_to_work_on.size())
    , nextPathColoring (0)
{ }


Coloring ColoringGenerator::nextColoring()
{
    vector<int> res;
    vector<int> toFind = vectorToLength(decimalToBase3(nextPathColoring), length);
    if (toFind.empty()) return Coloring();
    for (int i = 0; i < length; i++){
        int color;
        //TODO skus Array dlzky 3 namiesto tuplu
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
