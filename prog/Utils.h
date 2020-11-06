#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <tuple>

class Utils
{
    public:
        Utils();
        
        vector<tuple<int, int, int>> getSubsetsOfLength3(int set[], int setLength);
        int* getSetToLength(int colors);
        vector<int> decimalToBase(int decimal, int base);
        vector<int> decimalToBase3(int decimal);
        vector<int> vectorToLength(vector<int> a, int length);
        void printVector(vector <int> const &a);
};
#endif