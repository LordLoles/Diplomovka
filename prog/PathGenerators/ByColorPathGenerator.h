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
        int colorBeingGenerated;


    public:
        Path lastResult;
        vector<set<int>> colorsUsage;

        ByColorPathGenerator(int lengthOfPath, int colorsInPath);

        bool isColorDisjunct(int color);

        int colorsInPath();
        int colorsPosition(int vertex, int color);
        int freePosInVertex(int vertex);
        bool isFullVertex(int vertex);
        bool isFullPath();
        int getFirstNotFullVertex();

        bool generateNextColor(int color);
        bool nextFullPathGenerator(int color);
        bool nextFullPath();

        Path initialPath();
        Path nextPath();
};

#endif
