#include "Utils.h"
#include <iostream>

using namespace std;


//Returns all subsets of the set "set".
//Input set really needs to be a set, so the output will be a set again.
vector<tuple<int, int, int>> Utils::getSubsetsOfLength3(vector<int> set)
{
    vector<tuple<int, int, int>> res = vector<tuple<int, int, int>>();
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
vector<int> Utils::getSetToLength(int colors){
    vector<int> numbers = vector<int>(colors);
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
    std::reverse(res.begin(), res.end());
    return res;
}

//Converts number decimal (in decimal) to number in base of 3, so its digits are stored in vector.
vector<int> Utils::decimalToBase3(int decimal)
{
    return decimalToBase(decimal, 3);
}


//Converts vector to have legth "length" filling the start of it with zeroes. If the initial vector is greater than "length", then empty vector is returned.
vector<int> Utils::vectorToLength(vector<int> a, int length)
{
    if (a.size() == length) return a;
    if (a.size() > length) return vector<int>();
    vector<int> res = a;
    std::reverse(res.begin(), res.end());
    for (int i = res.size(); i < length; i++) res.push_back(0);
    reverse(res.begin(), res.end());
    return res;
}

//Prints vector of integers.
void Utils::printVector(vector <int> const &a)
{
    for(int i=0; i < a.size(); i++)
        cout << a.at(i) << ' ';
    cout << endl;
}

//Converts digits of number stored in vector "digits" to int with those numbers on respective positions.
int Utils::digitsToInt(vector<int> digits)
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
