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
    vector<int> toFind = {0};//
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
    return Coloring(res);
}
