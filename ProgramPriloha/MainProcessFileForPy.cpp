#include "Main.h"
#include "./prog/Utils.h"
#include "./prog/Coloring.h"
#include "./prog/Path.h"
#include "./prog/PathGenerators/ByColorContinuingPathGenerator.h"
#include "./prog/ColoringGenerators/PartialColoringGenerator.h"
#include "./prog/NonRepetitiveness.h"
#include "./prog/Consts.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <tuple>
#include <chrono>

using namespace std;

constexpr int processorsCount = 4; //how many part should be the file splitted to
constexpr int thisProcessorNumber = 3; //which lines will this code process

int main()
{
    ifstream file;
    file.open("PathsStarts.txt");
    string resultFileName = "Proc" + to_string(thisProcessorNumber) + "of" + to_string(processorsCount) + "Result.txt";
    ofstream fileResult;
    fileResult.open(resultFileName);

    std::cout << "thisProcessorNumber " << thisProcessorNumber << " out of " << processorsCount << endl;
    fileResult << "thisProcessorNumber " << thisProcessorNumber << " out of " << processorsCount << endl;

    /*if (!file.is_open())
    {
        std::cout << "Unable to open file" << endl;
        return 0;
    }*/

    auto startTime = chrono::high_resolution_clock::now();
    auto partTime = startTime;
    auto stopTime = startTime;
    chrono::milliseconds durationPart;
    chrono::milliseconds durationWhole;

    bool found;
    int lines = 0;
    int paths = 0;
    int pathsAll = 0;
    int colorsUsed = 0;
    string line;

    while (getline(file, line))
    {
        lines++;
        if (((lines) % 1000) == 0)
        {
            stopTime = chrono::high_resolution_clock::now();
            durationPart = chrono::duration_cast<chrono::milliseconds>(stopTime - partTime);
            durationWhole = chrono::duration_cast<chrono::milliseconds>(stopTime - startTime);
            partTime = stopTime;
            std::cout << "line " << lines << ", partTime " << durationPart.count() << ", wholeTime " << durationWhole.count() << endl;
            fileResult << "line " << lines << ", partTime " << durationPart.count() << ", wholeTime " << durationWhole.count() << endl;
        }
        if (((lines-1) % processorsCount) != thisProcessorNumber) continue;
        
        /*std::cout << endl;
        std::cout << "parsing line: " << line << endl;*/

        paths = 0;
        Path pathFromLine = stringToPath(line);
        ByColorContinuingPathGenerator pathGenerator = ByColorContinuingPathGenerator(pathFromLine.size(), 2, colorsInPath, pathFromLine);
        Path nowPath = pathGenerator.initialPath();

        while (!(nowPath.empty()))
        {
            //std::cout << "path with lists: ";
            //nowPath.printPath();
            paths++;

            found = false;

            PartialColoringGenerator coloringGenerator = PartialColoringGenerator(nowPath);
            Coloring coloring = coloringGenerator.initialColoring();

            //TODO aj coloring by slo na array<int, length>, ale musis si pamatat momentalnu dlzku
            while (!(coloring.empty()))
            {
                //std::cout << "coloring: ";
                //coloring.printColoring();

                if (checkNonRepetitivenessOnLastIndex(coloring))
                {
                    if (coloringGenerator.isFullColoring())
                    {
                        found = true;
                        break;
                    }
                    else
                    {
                        coloring = coloringGenerator.nextColoring();
                    }
                }
                else
                {
                    //coloring contains repetition
                    coloring = coloringGenerator.skipColoring();
                }
            }
            if (!found)
            {
                fileResult << "COUNTEREXAMPLE! COUNTEREXAMPLE! COUNTEREXAMPLE! COUNTEREXAMPLE! COUNTEREXAMPLE! COUNTEREXAMPLE! " << endl;
                fileResult << nowPath.to_string() << endl;
                std::cout << "COUNTEREXAMPLE! COUNTEREXAMPLE! COUNTEREXAMPLE! COUNTEREXAMPLE! COUNTEREXAMPLE! COUNTEREXAMPLE! " << endl;
                nowPath.printPath();
            }
            nowPath = pathGenerator.nextPath();
        }

        if (colorsUsed < pathGenerator.colorsUsed()) colorsUsed = pathGenerator.colorsUsed();
        pathsAll += paths;
    }

    
    stopTime = chrono::high_resolution_clock::now();
    durationPart = chrono::duration_cast<chrono::milliseconds>(stopTime - partTime);
    durationWhole = chrono::duration_cast<chrono::milliseconds>(stopTime - startTime);
    std::cout << "line " << lines << ", partTime " << durationPart.count() << ", wholeTime " << durationWhole.count() << endl;
    
    std::cout << "Lines checked " << lines/processorsCount << endl;
    std::cout << "Paths count " << pathsAll << endl;
    std::cout << "Colors used " << colorsUsed << endl;

    fileResult << "line " << lines << ", partTime " << durationPart.count() << ", wholeTime " << durationWhole.count() << endl;
    fileResult << "Lines checked " << lines/processorsCount << endl;
    fileResult << "Paths count " << pathsAll << endl;
    fileResult << "Colors used " << colorsUsed << endl;

    file.close();
    fileResult.close();
}
