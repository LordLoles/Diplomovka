#include "Utils.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;


//Returns all subsets of the set "set".
//Input set really needs to be a set, so the output will be a set again.
vector<array<int, 3>> getSubsetsOfLength3(vector<int> set)
{
    vector<array<int, 3>> res = vector<array<int, 3>>();
    int setLength = set.size();
    int count = 0; //for testing
    for (int i = 0; i < setLength; i++){
        for (int j = i+1; j < setLength; j++){
            for (int k = j+1; k < setLength; k++){
                res.push_back({set[i], set[j], set[k]});
                count++;
            }
        }
    }
    return res;
}

//Returns set containing numbers from 0 to "colors".
vector<int> getSetToLength(int colors){
    vector<int> numbers = vector<int>(colors);
    for(int i = 0; i < colors; i++){
        numbers[i] = i;
    }
    return numbers;
}

//Converts number decimal (in decimal) to number in 'base', so its digits are stored in vector.
vector<int> decimalToBase(int decimal, int base)
{
    vector<int> res;
    if ((base < 2) && (decimal >= base)) return res; //cover small base, so it can be used with the program also
    do {
        res.push_back(decimal % base);
        decimal /= base;
    }
    while (decimal > 0);
    std::reverse(res.begin(), res.end());
    return res;
}

//Converts number decimal (in decimal) to number in base of 3, so its digits are stored in vector.
vector<int> decimalToBase3(int decimal)
{
    return decimalToBase(decimal, 3);
}


//Converts vector to have legth "length" filling the start of it with zeroes. If the initial vector is greater than "length", then empty vector is returned.
vector<int> vectorToLength(vector<int> a, int length)
{
    if (a.empty()) return vector<int>();
    if (a.size() == length) return a;
    if (a.size() > length) return vector<int>();
    vector<int> res = a;
    std::reverse(res.begin(), res.end());
    for (int i = res.size(); i < length; i++) res.push_back(0);
    reverse(res.begin(), res.end());
    return res;
}

//Converts digits of number stored in vector "digits" to int with those numbers on respective positions.
int digitsToInt(vector<int> digits)
{
    int result = 0;
    int multiply = 1;
    reverse(digits.begin(), digits.end());
    for (int i = 0; i < digits.size(); i++) 
    {
        result += multiply * digits[i];
        multiply *= 10;
    }
    reverse(digits.begin(), digits.end());
    return result;
}

//Prints vector of integers.
void printVector(vector <int> const &a)
{
    for(int i=0; i < a.size(); i++)
        cout << a.at(i) << ' ';
    cout << endl;
}

//Convertes string in form "{a b c} {d e f} {g h i}" to vector<array<int, 3>>.
vector<array<int, 3>> stringTo3Vector(string pathString)
{
    stringstream lineStream(pathString);
    string segment;
    vector<string> seglist;
    vector<array<int, 3>> pathFromFile = vector<array<int, 3>>();

    while(getline(lineStream, segment, '{'))
    {
        if (segment.size() == 0) continue;
        string vertex; 
        getline(stringstream(segment), vertex, '}');
        stringstream vertexStream(vertex);

        string number1s;
        getline(vertexStream, number1s, ' ');
        string number2s;
        getline(vertexStream, number2s, ' ');
        string number3s;
        getline(vertexStream, number3s, ' ');

        pathFromFile.push_back(array<int, 3>{stoi(number1s), stoi(number2s), stoi(number3s)});
    }

    return pathFromFile;
}

//Convertes string in form "{a b c} {d e f} {g h i}" to Path.
Path stringToPath(string pathString)
{
    return Path(stringTo3Vector(pathString));
}

//Returns array, where on index i is a set of verteces, that the color i is on.
vector<set<int>> getColorsUsage(Path path, int colorsInPath)
{
    vector<set<int>> colorsUsage = vector<set<int>>(colorsInPath);
    for (int i = 0; i < colorsInPath; i++)
    {
        colorsUsage[i] = set<int>();
    }

    for (int i = 0; i < path.size(); i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int color = path.at(i).at(j);
            if (color >= 0) colorsUsage[color].insert(i);
        }
    }
    return colorsUsage;
}
