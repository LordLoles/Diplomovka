#include "Main.h"
#include "Utils.h"
#include "Coloring.h"
#include "Path.h"
#include "NonRepetitiveness.h"
#include "Utils.cpp"                // needed for visual studio code
#include "Coloring.cpp"             // needed for visual studio code
#include "Path.cpp"                 // needed for visual studio code
#include "NonRepetitiveness.cpp"    // needed for visual studio code
#include <iostream>
#include <vector>
#include <string>
#include <tuple>

using namespace std;

const int length = 7;
const int colors = 7;

Path* allColorSubsets; //all possible lists of colors (triplets) that will be used on verteces  -------not really a Path -> just to store it nicely-------
long long nextLists = 0; //next indeces of color lists (allColorSubsets) to be used in nextPath() in decimal
long long nextPathColoring = 0; //next indeces of colors in path (list of colors for path) to be used in nextColoring() in decimal
NonRepetitiveness* nonRepetitiveness = new NonRepetitiveness();

Path nextPath()
{
    //cout << "nextPath start";
    vector<tuple<int, int, int>> res;
    vector<int> toFind = vectorToLength(decimalToBase(nextLists, allColorSubsets->size()), length);
    if (toFind.empty()) return Path();
    for (int i = 0; i < length; i++){
        int found = toFind[i];
        tuple<int, int, int> tp = allColorSubsets->at(found);
        res.push_back(tp);
    }
    nextLists++;
    return Path(move(res));
}

Coloring* nextColoring(const Path & path)
{
    vector<int> res;
    vector<int> toFind = vectorToLength(decimalToBase3(nextPathColoring), length);
    if (toFind.empty()) return new Coloring();
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
    return new Coloring(res);
}

void resetColoring()
{
    nextPathColoring = 0;
}


int main()
{
    vector<int> setToColors = getSetToLength(colors);
    vector<tuple<int, int, int>> pseudoPath = getSubsetsOfLength3(setToColors);
    cout << "subsets count = " << pseudoPath.size() << endl;
    allColorSubsets = new Path(pseudoPath);
    cout << "all subsets: ";
    allColorSubsets->printPath();
    cout << "size " << allColorSubsets->size() << endl;

    Path nowPath = nextPath();

    cout << "nextPath done";

    while (!(nowPath.empty()))
    {
        resetColoring();
        //cout << endl;
        //cout << "path with lists: ";
        nowPath.printPath();

        Coloring* coloring = nextColoring(nowPath);
        while (!(coloring->empty()))
        {
            //cout << "coloring: ";
            coloring->printColoring();
            if (!nonRepetitiveness->checkNonRepetitiveness(coloring))
            {
                cout << "COUNTEREXAMPLE! COUNTEREXAMPLE! COUNTEREXAMPLE! COUNTEREXAMPLE! COUNTEREXAMPLE! COUNTEREXAMPLE! " << endl;
            }
            coloring = nextColoring(nowPath);
        }
        nowPath = nextPath();
    }
}
