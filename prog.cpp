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


vector<tuple<int, int, int>> getSubsetsOfLength3(int set[], int setLength)
{
    vector<tuple<int, int, int>> res;
    int count = 0; //for testing
    for (int i = 0; i < setLength; i++){
        for (int j = i+1; j < setLength; j++){
            for (int k = j+1; k < setLength; k++){
                res.push_back({i, j, k});
                count++;
            }
        }
    }
    cout << "subsets count = " << count << endl;
    return res;
}

int* getSetToLength(){
    int* numbers = new int[colors];
    for(int i = 0; i < colors; i++){
        numbers[i] = i;
    }
    return numbers;
}

void printVectorTuple(vector<tuple<int, int, int>> vt)
{
    for (tuple<int, int, int> &list : vt)
        cout << "[" << get<0>(list) << " "<< get<1>(list) << " "<< get<2>(list) << "] ";
    cout << endl;
}

//Converts number decimal (in decimal) to number in 'base', so its digits are stored in vector.
vector<int> decimalToBase(int decimal, int base)
{
    vector<int> res;
    while (decimal > 0){
        res.push_back(decimal % base);
        decimal /= base;
    }
    reverse(res.begin(), res.end());
    return res;
}

vector<int> decimalToBase3(int decimal)
{
    return decimalToBase(decimal, 3);
}

vector<int> vectorToLength(vector<int> a, int length)
{
    if (a.size() == length) return a;
    if (a.size() > length) return vector<int>();
    vector<int> res = a;
    reverse(res.begin(), res.end());
    for (int i = res.size(); i < length; i++) res.push_back(0);
    reverse(res.begin(), res.end());
    return res;
}

void printVector(vector <int> const &a)
{
    for(int i=0; i < a.size(); i++)
        cout << a.at(i) << ' ';
    cout << endl;
}

vector<tuple<int, int, int>> nextPath()
{
    vector<tuple<int, int, int>> res;
    vector<int> toFind = vectorToLength(decimalToBase(nextLists, allColorSubsets.size()), length);
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
    vector<int> toFind = vectorToLength(decimalToBase3(nextPathColoring), length);
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
    allColorSubsets = getSubsetsOfLength3(getSetToLength(), colors);
    cout << "all subsets: ";
    printVectorTuple(allColorSubsets);

    vector<tuple<int, int, int>> nowPath;
    vector<int> coloring;

    while (!(nowPath = nextPath()).empty())
    {
        resetColoring();
        cout << endl;
        cout << "path with lists: ";
        printVectorTuple(nowPath);
        while (!(coloring = nextColoring(nowPath)).empty())
        {
            cout << "coloring: ";
            printVector(coloring);
            if (!chcekNonRepetitivness(coloring))
            {
                cout << "COUNTEREXAMPLE! COUNTEREXAMPLE! COUNTEREXAMPLE! COUNTEREXAMPLE! COUNTEREXAMPLE! COUNTEREXAMPLE! " << endl;
            }
        }
    }
}
