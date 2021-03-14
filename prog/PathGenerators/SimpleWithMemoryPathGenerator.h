#ifndef SIMPLEWITHMEMORYPATHGENERATOR_H
#define SIMPLEWITHMEMORYPATHGENERATOR_H

#include <vector>
#include <tuple>
#include <unordered_map>
#include <set>
#include "../Path.h"
#include "../Utils.h"

using namespace std;

class SimpleWithMemoryPathGenerator
{
    private:
        int length;
        vector<int> allColors;


    public:
        Path lastResult;
        vector<set<int>> colorsUsage;
        
        void setColor(int vertex, int position, int color);
        void updateColorsUsage(int vertex, int position, int newColor);
        bool isLast(int vertex, int position);
        void reset(int vertex, int position);
        bool incrementVertexPostion(int vertex, int position);
        bool incrementVertex(int vertex);
        void increment();

        SimpleWithMemoryPathGenerator(int lengthOfPath, int colorsInPath);

        Path initialPath();
        Path nextPath();
};

#endif
