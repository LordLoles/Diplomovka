#include <vector>
#include <tuple>

#ifndef MY_UTILS_H
#define MY_UTILS_H

class Utils
{
    public:
        
        vector<tuple<int, int, int>> getSubsetsOfLength3(int set[], int setLength);
        int* getSetToLength(int colors);
        vector<int> decimalToBase(int decimal, int base);
        vector<int> decimalToBase3(int decimal);
        vector<int> vectorToLength(vector<int> a, int length);
        void printVector(vector <int> const &a);
};
#endif