#include "PathGenerator.h"
#include <iostream>

using namespace std;


PathGenerator::PathGenerator(int lengthOfPath, int colorsInPath) 
    : nextLists(0)
    , length (lengthOfPath)
    , allColorSubsets (Path(getSubsetsOfLength3(getSetToLength(colorsInPath))))
{
    if (colorsInPath < 3) throw "There need to be at least 3 colors!";
    /*cout << "subsets count = " << pseudoPath.size() << endl;
    cout << "all subsets: ";
    allColorSubsets.printPath();
    cout << "size " << allColorSubsets.size() << endl;*/
}


Path PathGenerator::nextPath()
{
    //cout << "nextPath start";
    vector<tuple<int, int, int>> res;
    vector<int> toFind = vectorToLength(decimalToBase(nextLists, allColorSubsets.size()), length);
    if (toFind.empty()) return Path();
    for (int i = 0; i < length; i++){
        int found = toFind[i];
        tuple<int, int, int> tp = allColorSubsets.at(found);
        res.push_back(tp);
    }
    nextLists++;
    return Path(move(res));
}

