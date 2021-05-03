#ifndef TESTPATHRELEVANCECHECK_H
#define TESTPATHRELEVANCECHECK_H

#include "../prog/PathGenerators/PathRelevanceCheck.h"
#include <vector>

using namespace std;


class TestPathRelevanceCheck
{
    private:
        vector<set<int>> getColorsUsage(Path path, int colorsInPath);
        void print(std::set<int> const &s);

    public:
        void test_getColorsUsage();
        void test_hasDisjunctColor();
        void test_isFirstLexicographically();
        void test_all();
};

#endif
