#include <vector>
#include <tuple>
#include <algorithm>

#ifndef MY_UTILS_H
#define MY_UTILS_H

using namespace std;

class Utils
{
    public:
        vector<tuple<int, int, int>> getSubsetsOfLength3(vector<int>);
        vector<int> getSetToLength(int colors);
        vector<int> decimalToBase(int decimal, int base);
        vector<int> decimalToBase3(int decimal);
        vector<int> vectorToLength(vector<int> a, int length);
        int digitsToInt(vector<int> digits);
        void printVector(vector<int> const &a);
};
#endif
