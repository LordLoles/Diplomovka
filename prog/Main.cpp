#include "Main.h"
#include "Utils.h"
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
Utils utils = new Utils();

vector<tuple<int, int, int>> nextPath()
{
    vector<tuple<int, int, int>> res;
    vector<int> toFind = Utils::vectorToLength(Utils::decimalToBase(nextLists, allColorSubsets.size()), length);
    if (toFind.empty()) return vector<tuple<int, int, int>>();
    for (int i = 0; i < length; i++){
        res.push_back(allColorSubsets[toFind[i]]);
    }
    nextLists++;
    return res;
}

vector<int> nextColoring(vector<tuple<int, int, int>> path)
{
    vector<int> res;
    vector<int> toFind = Utils::vectorToLength(Utils::decimalToBase3(nextPathColoring), length);
    if (toFind.empty()) return vector<int>();
    for (int i = 0; i < length; i++){
        int color;
        switch(toFind[i]) {
            case 0:
                color = get<0>(path[i]);
                break;
            case 1:
                color = get<1>(path[i]);
                break;
            case 2:
                color = get<2>(path[i]);
                break;
            default:
                throw "Lists are only of length 3!";
        }
        res.push_back(color);
    }
    nextPathColoring++;
    return res;
}

void resetColoring()
{
    nextPathColoring = 0;
}

bool chcekNonRepetitivness(vector<int> coloring)
{
    return true;
}


int main()
{
    allColorSubsets = Utils::getSubsetsOfLength3(Utils::getSetToLength(colors), colors);
    cout << "all subsets: ";
    Utils::printColoring(allColorSubsets);

    vector<tuple<int, int, int>> nowPath;
    vector<int> coloring;

    while (!(nowPath = nextPath()).empty())
    {
        resetColoring();
        cout << endl;
        cout << "path with lists: ";
        Utils::printColoring(nowPath);
        while (!(coloring = nextColoring(nowPath)).empty())
        {
            cout << "coloring: ";
            Utils::printVector(coloring);
            if (!chcekNonRepetitivness(coloring))
            {
                cout << "COUNTEREXAMPLE! COUNTEREXAMPLE! COUNTEREXAMPLE! COUNTEREXAMPLE! COUNTEREXAMPLE! COUNTEREXAMPLE! " << endl;
            }
        }
    }
}
