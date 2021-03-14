#ifndef BYCOLORPATHGENERATOR_H
#define BYCOLORPATHGENERATOR_H

#include <vector>
#include <tuple>
#include <unordered_map>
#include <set>
#include "../Path.h"
#include "../Utils.h"

using namespace std;

class ByColorPathGenerator
{
    private:
        int length;
        vector<int> allColors;
        int fullVertecesCount;
        bool colorsDisjunct;


    public:
        Path lastResult;
        vector<set<int>> colorsUsage;

        ByColorPathGenerator(int lengthOfPath, int colorsInPath);

        bool isFullVertex(int vertex);
        bool isFullPath();

        void nextNotFullRelevantPath();
        void nextFullRelevantPath();

        Path initialPath();
        Path nextPath();
};

#endif
