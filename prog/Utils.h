#ifndef MY_UTILS_H
#define MY_UTILS_H

#include <vector>
#include <tuple>
#include <array>
#include <algorithm>

using namespace std;

vector<array<int, 3>> getSubsetsOfLength3(vector<int>);
vector<int> getSetToLength(int colors);
vector<int> decimalToBase(int decimal, int base);
vector<int> decimalToBase3(int decimal);
vector<int> vectorToLength(vector<int> a, int length);
int digitsToInt(vector<int> digits);
void printVector(vector<int> const &a);

#endif
