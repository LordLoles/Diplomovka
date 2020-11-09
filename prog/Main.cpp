#include "Main.h"
#include "Utils.h"
#include "Coloring.h"
#include "Path.h"
#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <algorithm>

using namespace std;

const int length = 2;
const int colors = 4;

vector<tuple<int, int, int>> allColorSubsets; //all possible lists of colors (triplets) that will be used on verteces
long long nextLists = 0; //next indeces of color lists (allColorSubsets) to be used in nextPath() in decimal
long long nextPathColoring = 0; //next indeces of colors in path (list of colors for path) to be used in nextColoring() in decimal
Utils* utils = new Utils();

Path* nextPath()
{
    vector<tuple<int, int, int>> res;
    vector<int> toFind = utils->vectorToLength(utils->decimalToBase(nextLists, allColorSubsets.size()), length);
    if (toFind.empty()) return new Path();
    for (int i = 0; i < length; i++){
        res.push_back(allColorSubsets[toFind[i]]);
    }
    nextLists++;
    return new Path(res);
}

Coloring* nextColoring(Path* path)
{
    vector<int> res;
    vector<int> toFind = utils->vectorToLength(utils->decimalToBase3(nextPathColoring), length);
    if (toFind.empty()) return new Coloring();
    for (int i = 0; i < length; i++){
        int color;
        switch(toFind[i]) {
            case 0:
                color = get<0>(path->at(i));
                break;
            case 1:
                color = get<1>(path->at(i));
                break;
            case 2:
                color = get<2>(path->at(i));
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

bool chcekNonRepetitivness(Coloring* coloring)
{
    return true;
}


int main()
{
    int* setToColors = utils->getSetToLength(colors);
    vector<tuple<int, int, int>> pathh = utils->getSubsetsOfLength3(setToColors, colors);
    Path* allColorSubsets = new Path(pathh);
    cout << "all subsets: ";
    allColorSubsets->printPath();

    Path* nowPath = nextPath();

    while (!(nowPath->empty()))
    {
        resetColoring();
        cout << endl;
        cout << "path with lists: ";
        nowPath->printPath();

        Coloring* coloring = nextColoring(nowPath);
        while (!(coloring->empty()))
        {
            cout << "coloring: ";
            coloring->printColoring();
            if (!chcekNonRepetitivness(coloring))
            {
                cout << "COUNTEREXAMPLE! COUNTEREXAMPLE! COUNTEREXAMPLE! COUNTEREXAMPLE! COUNTEREXAMPLE! COUNTEREXAMPLE! " << endl;
            }
            coloring = nextColoring(nowPath);
        }
        nowPath = nextPath();
    }
}
