#include "Utils.h"
#include <iostream>

using namespace std;



vector<tuple<int, int, int>> Utils::getSubsetsOfLength3(int* set, int setLength)
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

int* Utils::getSetToLength(int colors){
    int* numbers = new int[colors];
    for(int i = 0; i < colors; i++){
        numbers[i] = i;
    }
    return numbers;
}

//Converts number decimal (in decimal) to number in 'base', so its digits are stored in vector.
vector<int> Utils::decimalToBase(int decimal, int base)
{
    vector<int> res;
    while (decimal > 0){
        res.push_back(decimal % base);
        decimal /= base;
    }
    reverse(res.begin(), res.end());
    return res;
}

vector<int> Utils::decimalToBase3(int decimal)
{
    return decimalToBase(decimal, 3);
}

vector<int> Utils::vectorToLength(vector<int> a, int length)
{
    if (a.size() == length) return a;
    if (a.size() > length) return vector<int>();
    vector<int> res = a;
    reverse(res.begin(), res.end());
    for (int i = res.size(); i < length; i++) res.push_back(0);
    reverse(res.begin(), res.end());
    return res;
}

void Utils::printVector(vector <int> const &a)
{
    for(int i=0; i < a.size(); i++)
        cout << a.at(i) << ' ';
    cout << endl;
}
