#include "SimplePathGenerator.h"
#include <iostream>

using namespace std;


SimplePathGenerator::SimplePathGenerator(int lengthOfPath, int colorsInPath) 
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


Path SimplePathGenerator::nextPath()
{
    //cout << "nextPath start";
    vector<array<int, 3>> res;
    vector<int> toFind = vectorToLength(decimalToBase(nextLists, allColorSubsets.size()), length);
    if (toFind.empty()) return Path();
    for (int i = 0; i < length; i++){
        int found = toFind[i];
        array<int, 3> elem = allColorSubsets.at(found);
        res.push_back(elem);
    }
    nextLists++;
    return Path(move(res));
}

